PROVA INTERMEDIA DI PROGRAMMAZIONE

Gruppo __C Rangers__
- Romano Matteo
- Piombo Nicoli Giovanni
- Gottardo Giovanni

------------------------------------------------------------

SVILUPPO DEL PROGETTO

Lo sviluppo del progetto è iniziato con una fase di lettura e discussione
tra i membri del gruppo, al fine di definire una prima bozza della struttura
del progetto e degli strumenti da utilizzare per lo sviluppo del modulo C++
in remoto.

Strumenti principali utilizzati:
- VS Code come editor principale
- GitHub per il controllo di versione
- Estensioni Live Share per la collaborazione in tempo reale

Successivamente ci siamo assegnati dei ruoli specifici, pur lavorando in
maniera collaborativa per garantire la correttezza strutturale e logica del
progetto.

------------------------------------------------------------

SUDDIVISIONE DEI RUOLI

Giovanni G.:
    - Creazione dell’interfaccia InertialDriver
    - Implementazione del metodo get_reading()
    - Override dell’operator<<

Giovanni P.N.:
    - Creazione dell’interfaccia Lettura
    - Implementazione delle funzioni membro clear_buffer() e push_back()
    - Bozza del main() per la verifica del modulo

Matteo:
    - Creazione e ridefinizione della classe MyVector con verifica di correttezza
    - Creazione dell’interfaccia Misura
    - Implementazione di pop_front() e eventuali funzioni helper

Nota:
La suddivisione dei ruoli indicata rappresenta l’organizzazione ideale, ma nella
realtà tutti i membri del gruppo hanno collaborato attivamente su tutti gli
aspetti del progetto, verificando struttura, logica e efficienza del codice.

Comandi Compilazione: 
-Windows: g++ -Iinclude src/*.cpp -o program.exe
          ./program.exe
-Linux: g++ -Iinclude src/*.cpp -o program
        ./program

