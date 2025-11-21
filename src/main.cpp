#include <iostream>
#include "InertialDriver.h"
#include "Misura.h"
#include "Lettura.h"

// Helper per creare dati fittizi
Misura generaMisuraTest(double val) {
    Lettura letture[17];
    for (int i = 0; i < 17; ++i) {
        letture[i] = Lettura(val, val, val, val, val, val);
    }
    return Misura(letture);
}

int main() {
    std::cout << "=== TEST SUITE COMPLETA ===" << std::endl;

    InertialDriver driver;

    // --- TEST 1: Inserimento (Push) ---
    driver.push_back(generaMisuraTest(1.0)); // Misura A
    driver.push_back(generaMisuraTest(2.0)); // Misura B
    std::cout << "Test 1 (Push): Size corrente (atteso 2) -> " << driver.get_current_size() << std::endl;

    // --- TEST 2: Stampa (Operator<<) ---
    std::cout << "Test 2 (Stampa): Dovrebbe mostrare valori 2.0:" << std::endl;
    std::cout << driver << std::endl;

    // --- TEST 3: Lettura specifica (get_reading) ---
    try {
        Lettura l = driver.get_reading(0); // Legge sensore 0 dell'ultima misura (2.0)
        std::cout << "Test 3 (Get Reading): Valore atteso 2.0 -> " << l.getYawV() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Test 3 ERROR: " << e.what() << std::endl;
    }

    // --- TEST 4: Rimozione (Pop Front) ---
    try {
        Misura m = driver.pop_front();
        std::cout << "Test 4 (Pop): Valore rimosso (atteso 1.0) -> " << m[0].getYawV() << std::endl;
        std::cout << "Test 4 (Size): Size dopo pop (atteso 1) -> " << driver.get_current_size() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Test 4 ERROR: " << e.what() << std::endl;
    }

    // --- TEST 5: Buffer Circolare (Overflow) ---
    driver.clear_buffer();
    std::cout << "Test 5: Riempimento buffer (105 elementi)..." << std::endl;
    for(int i=0; i<105; ++i) driver.push_back(generaMisuraTest((double)i));
    
    // Il buffer è da 100. I primi 5 (0,1,2,3,4) sono persi. Il più vecchio è il 5.
    Misura old = driver.pop_front();
    std::cout << "Test 5 (Circular): Il più vecchio è (atteso 5.0) -> " << old[0].getYawV() << std::endl;

    // --- TEST 6: Gestione Buffer Vuoto ---
    driver.clear_buffer();
    try {
        driver.pop_front();
        std::cout << "Test 6 (Empty Pop): FALLITO (Doveva lanciare eccezione)" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Test 6 (Empty Pop): PASSATO (Eccezione catturata: " << e.what() << ")" << std::endl;
    }

    std::cout << "=== FINE TEST ===" << std::endl;
    return 0;
}
