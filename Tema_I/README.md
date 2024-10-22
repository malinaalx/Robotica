# TEMA 1

<details>
  <summary><b>Cerinte</b></summary>

  ## Descrierea cerintelor:
  -Această temă modelează o stație de încărcare pentru vehicule electrice, folosind un circuit compus din LED-uri și butoane.
  -Sistemul include un LED RGB care indică starea stației:
Verde indică că stația este liberă și poate fi utilizată.
Roșu semnalizează că procesul de încărcare este în desfășurare.
Progresul încărcării bateriei este vizualizat prin intermediul a 4 LED-uri:LED-ul 1 indică 25% încărcare,LED-ul 2 semnalizează 50%, LED-ul 3 corespunde la 75%, LED-ul 4 arată când bateria a atins 100%.
Procesul de încărcare începe la apăsarea butonului START (apăsările suplimentare ale butonului în timpul încărcării sunt ignorate).
  -Fiecare LED, pe rând, clipește de două ori și se aprinde a treia oară, în timp ce următorul LED începe să clipească. Acest tipar continuă până când ultimul LED clipeste de două ori și apoi se stinge complet.
  -Durata de clipire pentru fiecare LED este de 3 secunde.
  -La finalul procesului de încărcare, toate cele 4 LED-uri se aprind intermitent de 3 ori simultan, iar LED-ul RGB revine la culoarea verde.
  -O apăsare lungă, de cel puțin o secundă, pe butonul STOP, va întrerupe încărcarea și va declanșa animația de final, cu toate LED-urile clipind de 3 ori în același timp.
##
</details>

<details> 
  <summary><b>Componente</b></summary>
  
  ## Componente:
  - 4x LED-uri (pentru a simula procentul de încărcare)
  - 1x LED RGB (pentru starea de liber sau ocupat)
  - 2x Butoane (pentru start încărcare și stop încărcare)
  - 9x Rezistoare (7x 220ohm, 2x 1K)
  - Breadboard
  - Linii de legătură
    ##
</details>


<details>
  <summary> <b> Schema electrica </b> </summary>

  ## Schema electrica a circuitului realizata in Wokki
![Simulator_tema1](https://github.com/user-attachments/assets/3bd6630a-2f4b-42cc-b334-e78aaca43496)
  ##
</details>
