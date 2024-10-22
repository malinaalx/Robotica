# TEMA 1

<details>
  <summary><b>Cerinte</b></summary>

  ## Descrierea cerintelor:
  -Această temă modelează o stație de încărcare pentru vehicule electrice, folosind un circuit compus din LED-uri și butoane.
  1. **Disponibilitate stație**: LED-ul RGB indică starea:
   - Verde: stația este liberă.
   - Roșu: stația este ocupată.

2. **Încărcare baterie**:
   - Progresul de încărcare este afișat cu 4 LED-uri (L1-L4) corespunzătoare la 25%, 50%, 75% și 100%.
   - Încărcarea se face progresiv, cu LED-ul curent clipind timp de 3s, cele anterioare rămânând aprinse.

3. **Pornire**:
   - Apăsarea scurtă a butonului **START** inițiază încărcarea.
   - Butonul nu are efect dacă încărcarea este deja în curs.

4. **Oprire forțată**:
   - Apăsarea lungă a butonului **STOP** (minim 1s) întrerupe încărcarea, declanșând clipirea simultană de 3 ori a tuturor LED-urilor.
   - LED-ul RGB revine la verde.
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
