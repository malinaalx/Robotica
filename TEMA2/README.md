<details>
  <summary> <b> Despre </b> </summary>

  ## Descrierea temei:
  
  - Aceasta tema simuleaza un joc TypeRacer.
  - Jocul va implica utilizarea unor componente hardware de bază, cum ar fi un LED RGB pentru a indica starea jocului și butoane pentru a controla începutul și dificultatea jocului. De asemenea, vom implementa un algoritm simplu pentru generarea aleatoare a cuvintelor dintr-un dicționar predefinit, care va fi afișat utilizatorului pentru a fi tastat.
    
   </details>
   
   <details>
  <summary><b>Detalii tehnice</b></summary>

   ## 1. Detalii tehnice:
  -  Led-ul RGB reprezinta indicatorul de stare. In repaus led-ul va fi alb, iar la apasarea butonului de start va clipi timp de 3 secunde.
    
  -  Led-ul se va face verde sau rosu, in timpul unei runde, daca textul introdus este corect, respectiv gresit.
    
  -  Vom avea 2 butoane: 1. De start/stop 2. De dificultate

  -  Apasarea butonului de start/stop va initia/ va opri runda. Cand jocul este oprit, daca se apasa butonul de start, se va face o numaratoare inversa de 3 secunde pana la o noua runda.

  - Al doilea buton, de dificultate, indica viteza cu care apar cuvintele si functioneaza doar in repaus. Dificultatea poate fi : Easy/Medium/Hard.

  - Dictionarul de cuvinte va fi afisat in terminal random. In functie de corectitudinea cuvantului introdus, se va genera unul nou imediat, in caz contrar, se va astepta timpul stabilit de fiecare dificultate.

    </details>

    <details> 
  <summary><b>Componente</b></summary>
  
  ## Componentele folosite:
  
  -Arduino UNO (ATmega328P microcontroller)
  
  -1x LED RGB (pentru a semnaliza dacă cuvântul corect e scris greșit sau nu)
  
  -2x Butoane (pentru start/stop rundă și pentru selectarea dificultății)
  
  -5x Rezistoare (3x 220/330 ohm, 2x 1000 ohm)
  
  -Breadbord
  
  -Fire de legătură
</details>

<details>
  <summary> <b> Schema electrica </b> </summary>

  ## Schema electrica a circuitului implementat pe WOWKI

 ![Simulator_tema2](https://github.com/user-attachments/assets/247e52a6-e335-4d5a-8acd-8ade31bd964a)

  ##
</details>

<details>
  <summary> <b> Poze ale setup-ului fizic </b> </summary>
  
## Setup-ul fizic
![WhatsApp Image 2024-11-05 at 22 55 10_c8d7a6d5](https://github.com/user-attachments/assets/63609a4e-634b-4bdb-a046-7d383cbbb67d)
![WhatsApp Image 2024-11-05 at 22 59 46_e1022ffd](https://github.com/user-attachments/assets/90ccf857-ab65-46f9-8a62-e72a235ada87)
![WhatsApp Image 2024-11-05 at 22 55 10_fdeadac5](https://github.com/user-attachments/assets/67f70a21-d4ec-4398-8506-afab8aafd065)


##

</details>

<details>
  <summary> <b> Functionalitatea montajului fizic </summary>
    https://youtu.be/qgXuEfWsXPE?si=F6bcP7M3ovDF6b0f
</details>



