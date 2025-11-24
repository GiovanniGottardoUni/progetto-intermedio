#include <iostream>
#include "../include/InertialDriver.h"
#include "../include/Misura.h"
#include "../include/Lettura.h"

// Helper function per creare dati
Misura generaMisuraTest(double val)
{
    Lettura letture[17];
    for (int i = 0; i < 17; ++i)
    {
        letture[i] = Lettura(val, val, val, val, val, val);
    }
    return Misura(letture);
}

int main()
{
    InertialDriver driver;

    // test 1: push_back
    driver.push_back(generaMisuraTest(1.0));
    driver.push_back(generaMisuraTest(2.0));
    std::cout << "Test 1, Push: current_size -> 2, calcolato:" << driver.get_current_size() << std::endl;

    // test 2, <<operator
    std::cout << "Test 2, Stampa: Dovrebbe mostrare valori 2.0:" << std::endl;
    std::cout << driver << std::endl;

    // test 3, get_reading
    try
    {
        Lettura l = driver.get_reading(0); // Legge sensore 0 dell'ultima misura (2.0)
        std::cout << "Test 3, get_reading: valore atteso 2.0 -> " << l.getYawV() << std::endl;
    }
    catch (std::exception &e) // eccezione se l'indice non e' valdo
    {
        std::cout << "Test 3, errore: " << e.what() << std::endl;
    }

    // test 4, pop_front
    try
    {
        Misura m = driver.pop_front();
        std::cout << "Test 4, pop_front: Valore rimosso atteso 1.0 -> " << m[0].getYawV() << std::endl;
        std::cout << "Test 4, size: Size dopo pop atteso 1 -> " << driver.get_current_size() << std::endl;
        std::cout << "Test 4, Stampa: atteso 2.0:" << driver << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Test 4, errore: " << e.what() << std::endl;
    }

    // test 5, Overflow buffer (105 elementi)
    driver.clear_buffer();
    std::cout << "Test 5, riempimento buffer (105 elementi)..." << std::endl;
    for (int i = 0; i < 105; ++i)
        driver.push_back(generaMisuraTest((double)i));

    // Il buffer è da 100. I primi 5 0,1,2,3,4 sono persi. Il più vecchio elemento inserito è il 5.
    Misura old = driver.pop_front();
    std::cout << "Test 5, buffer circolare: il valore piu' vecchio atteso e' 5.0 -> " << old[0].getYawV() << std::endl;

    // test 6, Gestione Buffer vuoto
    driver.clear_buffer();
    try
    {
        driver.pop_front();
        std::cout << "Test 6, pop con buffer empty: FALLITO (Doveva lanciare eccezione)" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Test 6, pop con buffer empty: PASSATO (Eccezione catturata: " << e.what() << ")" << std::endl;
    }
    return 0;
}
