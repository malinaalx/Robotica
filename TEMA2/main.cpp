#include <Arduino.h>

// Definire pini LED RGB și butoane
#define LED_ROSU 6
#define LED_VERDE 5
#define LED_ALBASTRU 4
#define PIN_START 2
#define PIN_DIFICULTATE 3

// Stare joc și variabile pentru butoane
volatile bool rundaInDesfasurare = false;
volatile bool flagStartApasat = false;
volatile bool flagDificultateApasat = false;
int nivelDificultate = 0;  // 0 - Ușor, 1 - Mediu, 2 - Greu
unsigned long debounceUltim = 0;
const unsigned long pragAntirebote = 60;

// Lista de cuvinte și index pentru joc
const char* cuvinte[] = {"roz", "mov", "galben", "negru", "indigo"};
const int nrCuvinte = sizeof(cuvinte) / sizeof(cuvinte[0]);
int indiceCuvant = 0;
int scorCorect = 0;

// Durată rundă și intervale
unsigned long startRundaTimp = 0;
unsigned long timpNumaratoare = 2500;
unsigned long durataRunda = 30000;
unsigned long intervalDificultate = 5000;
unsigned long timpUltimCuvant = 0;

// Declarații funcții
void seteazaCuloareLED(int r, int g, int b);
void initRunda();
void opresteRunda();
void gestioneazaDificultate();
void butonStartApasat();
void butonDificultateApasat();
void verificaText();
void afiseazaCuvantNou();

String curataInput(String text, char eliminat) {
    String textCurat = "";
    for (char c : text) {
        if (c != eliminat) {
            textCurat += c;
        } else {
            if (textCurat.length() > 0) textCurat.remove(textCurat.length() - 1);
        }
    }
    return textCurat;
}

void setup() {
    Serial.begin(9600);

    // Inițializare LED RGB
    pinMode(LED_ROSU, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_ALBASTRU, OUTPUT);
    seteazaCuloareLED(255, 255, 255);

    // Configurare butoane
    pinMode(PIN_START, INPUT_PULLUP);
    pinMode(PIN_DIFICULTATE, INPUT_PULLUP);

    // Întreeruperi pentru butoane
    attachInterrupt(digitalPinToInterrupt(PIN_START), butonStartApasat, FALLING);
    attachInterrupt(digitalPinToInterrupt(PIN_DIFICULTATE), butonDificultateApasat, FALLING);

    randomSeed(analogRead(0));
}

void loop() {
    if (flagStartApasat) {
        flagStartApasat = false;
        if (rundaInDesfasurare) {
            opresteRunda();
        } else {
            initRunda();
        }
    }

    if (flagDificultateApasat) {
        flagDificultateApasat = false;
        if (!rundaInDesfasurare) {
            gestioneazaDificultate();
        }
    }

    if (rundaInDesfasurare) {
        if (millis() - startRundaTimp >= durataRunda) {
            opresteRunda();
        } else {
            verificaText();
        }
    }
}

void initRunda() {
    rundaInDesfasurare = true;
    scorCorect = 0;
    startRundaTimp = millis();
    timpUltimCuvant = millis();

    Serial.println("Incepem in:");
    for (int i = 3; i > 0; i--) {
        seteazaCuloareLED(255, 255, 0);  // Galben pentru numărătoare inversă
        Serial.println(i);
        delay(500);
        seteazaCuloareLED(0, 0, 0);  // LED oprit pentru efect intermitent
        delay(500);
    }

    seteazaCuloareLED(0, 255, 0); // Verde pentru start runda
    afiseazaCuvantNou();
}

void opresteRunda() {
    rundaInDesfasurare = false;
    seteazaCuloareLED(255, 255, 255); // Alb pentru standby
    Serial.print("Runda incheiata. Cuvinte corecte: ");
    Serial.println(scorCorect);
}

void gestioneazaDificultate() {
    nivelDificultate = (nivelDificultate + 1) % 3;
    switch (nivelDificultate) {
        case 0:
            intervalDificultate = 5000;
            Serial.println("Mod Ușor activat (5 secunde)");
            break;
        case 1:
            intervalDificultate = 3000;
            Serial.println("Mod Mediu activat (3 secunde)");
            break;
        case 2:
            intervalDificultate = 1500;
            Serial.println("Mod Greu activat (1,5 secunde)");
            break;
    }
}

void verificaText() {
    if (millis() - timpUltimCuvant >= intervalDificultate) {
        timpUltimCuvant = millis();
        Serial.println("Timpul pentru cuvantul curent a expirat.");
        afiseazaCuvantNou();
    }

    if (Serial.available()) {
        String inputText = Serial.readStringUntil('\n');
        inputText.trim();
        inputText = curataInput(inputText, 8);

        if (inputText.equals(cuvinte[indiceCuvant])) {
            scorCorect++;
            seteazaCuloareLED(0, 255, 0); // Verde pentru corect
            afiseazaCuvantNou();
            timpUltimCuvant = millis();
        } else {
            seteazaCuloareLED(255, 0, 0); // Roșu pentru greșit
        }
    }
}

void afiseazaCuvantNou() {
    indiceCuvant = random(0, nrCuvinte);
    Serial.print("Scrie acest cuvant: ");
    Serial.println(cuvinte[indiceCuvant]);
}

void seteazaCuloareLED(int r, int g, int b) {
    analogWrite(LED_ROSU, r);
    analogWrite(LED_VERDE, g);
    analogWrite(LED_ALBASTRU, b);
}

void butonStartApasat() {
    unsigned long curentMillis = millis();
    if (curentMillis - debounceUltim > pragAntirebote) {
        flagStartApasat = true;
        debounceUltim = curentMillis;
    }
}

void butonDificultateApasat() {
    unsigned long curentMillis = millis();
    if (curentMillis - debounceUltim > pragAntirebote) {
        flagDificultateApasat = true;
        debounceUltim = curentMillis;
    }
}

