# Tema-Sortari-SD
Proiect realizat de Brînză Tudor-Alexandru

Proiect sortări

În acest proiect au fost implementați cinci algoritmi de sortare: Quicksort, Mergesort, Radixsort, Countsort și Timsort. Ulterior am realizat diferite teste și am comparat algoritmii în diferite moduri:

Prima comparare a fost între tipurile de algoritmi Quicksort, diferențiați de modul de alegere al pivotului: pivotul ales mereu ultimul element(quicksort 1), pivot ales un element random(quicksort 2), pivot ales ca mediana dintre trei valori random(quicksort 3).
![Qs 10^5 random](https://user-images.githubusercontent.com/72472437/111081730-6d509a00-850d-11eb-9c1c-cc08fc9832f7.png)
![Qs 10^6 random](https://user-images.githubusercontent.com/72472437/111081733-70e42100-850d-11eb-9f03-0067bcb2991e.png)
![Qs 10^7 random](https://user-images.githubusercontent.com/72472437/111081736-73467b00-850d-11eb-8509-f9b123fcf68f.png)
Pentru testul cu 10^7 valori deja sortate Quicksortul ce folosește ca pivot ultimul element a depășit timpul limită de 100 de secunde, așa că nu a mai fost adăugat în grafic.
![Qs sorted 10^7](https://user-images.githubusercontent.com/72472437/111081741-75a8d500-850d-11eb-9101-68b669c5b0a7.png)

Observații: Realizând aceste teste am observat că operațiile ce randomizează alegerea pivotului măresc timpul de execuție, depășind beneficiile pe care aceste metode le aduc. Totuși, în situații particulare precum un vector deja sortat sau aproape sortat metoda aparent rapidă de a alege pivotul pe ultima poziție va eșua.

A doua comparare a fost între tipurile de algoritmi Timsort, diferența fiind făcută de valoarea de la care se alege folosirea Insertion sort-ului. Prima valoare aleasă a fost 32, a doua 64 și a treia 128.

![Timsort 10^5 random](https://user-images.githubusercontent.com/72472437/111081775-a721a080-850d-11eb-8d51-4ab381ec6f1e.png)![Timsort 10^6 random](https://user-images.githubusercontent.com/72472437/111081791-b7d21680-850d-11eb-8128-3e427aea7c62.png)
![Timsort 10^7 random](https://user-images.githubusercontent.com/72472437/111081793-bb659d80-850d-11eb-9319-31476d1c47a1.png)

Observații: Precum era și așteptat, Timsort-ul cu valoare de Run aleasă între 32 și 64 obține rezultate similare, deși puțin mai rapid pe Run egal cu 32. O valoare mai mare încetinește procesul, întrucât Insertion sort-ul începe să-și arate ineficiența, lucru evidențiat de Timsort-ul cu 128.

A treia comparare a fost între Quicksort, Mergesort și Timsort. La fiecare comparare a fost aleasă pentru fiecare algoritm varianta care a oferit cele mai bune rezultate.
![Qs vs Ms vs Ts 10^5 random](https://user-images.githubusercontent.com/72472437/111081810-cb7d7d00-850d-11eb-8434-0b3a1188858c.png)
![Qs vs Ms vs Ts 10^6 random](https://user-images.githubusercontent.com/72472437/111081819-d1735e00-850d-11eb-8713-468ee8f34c24.png)
![Qs vs Ms vs Ts 10^7 random](https://user-images.githubusercontent.com/72472437/111081822-d2a48b00-850d-11eb-87d3-c3b9b52cd0e1.png)
![Qs vs Ms vs Ts 10^7 sorted](https://user-images.githubusercontent.com/72472437/111081826-d506e500-850d-11eb-872f-2bbe2f90c0ae.png)

Observații: Observăm că pentru valori alese random algoritmul Quicksort este cel mai rapid, iar Mergesort este cel mai lent. Totuși, cu cât crește numărul de valori Timsort devine mai rapid. Pentru valori sortate sau aproape sortate Timsort este mult mai rapid, un timp de execuție aproape de două ori mai bun.

A patra comparare a fost făcută între variații ale algoritmului Radixsort, diferența fiind baza în care au fost considerate cifrele. Astfel, avem baza 2, baza 10, baza 256, si baza 65536(2^16).

![Radix 10^5 random](https://user-images.githubusercontent.com/72472437/111081835-e6e88800-850d-11eb-8f0f-71ac46d8c93e.png)
![Radix 10^6 random values](https://user-images.githubusercontent.com/72472437/111081840-ebad3c00-850d-11eb-9bfa-f88b8eb5764b.png)
![Radix 10^7 random](https://user-images.githubusercontent.com/72472437/111081843-ecde6900-850d-11eb-96c7-6cc341326040.png)

Observații: Este evident că pe măsură ce mărim baza, timpul de execuție scade. O observație notabilă este totuși că diferența dintre Radix256 și Radix65536 nu este mare, dar cel de-al doilea va folosi de 200 de ori mai multă memorie.
O ultimă comparare a fost făcută între Radixsort si Countsort. Pentru a se putea realiza CountSort am considerat numerele ca fiind maxim 10 milioane.
![Radix vs count 10^7 random](https://user-images.githubusercontent.com/72472437/111081851-f49e0d80-850d-11eb-8543-edd5f9a32632.png)

Observații: Pentru intervalele unde poate fi folosit, CountSort este mai rapid. Marele său dezavantaj în această situație va fi memoria folosită, mult mai multă decât cea de la Radix. Un alt avantaj al Radix-ului este ca poate sorta numere oricât de mari, ceea ce îl face per total mai practic decât Countsort.
