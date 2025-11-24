#ifndef MISURA_H
#define MISURA_H

#include "lettura.h"
#include <iostream>

/**
 * @class Misura
 * @brief Rappresenta una misura completa composta da più sensori.
 *
 * Una singola misura contiene un array di Lettura, una per ciascun sensore.
 */
class Misura
{
public:
    static constexpr int NUM_SENSORS = 17; // Numero di sensori per misura

    /**
     * @brief Costruttore di default.
     *
     * Inizializza le letture a valori di default (tutte a 0).
     */
    Misura() = default;

    /**
     * @brief Costruttore da array di Lettura.
     *
     * Copia i valori dell'array passato nei sensori della misura.
     *
     * @param input Array di Lettura di dimensione NUM_SENSORS
     */
    Misura(const Lettura input[]);

    /**
     * @brief Costruttore da initializer_list.
     *
     * Permette di inizializzare una misura usando una lista di Lettura.
     *
     * @param init Lista di Lettura
     */
    Misura(std::initializer_list<Lettura> init);

    /**
     * @brief Accesso in lettura/scrittura a una Lettura del sensore.
     *
     * @param index Indice del sensore (0 <= index < NUM_SENSORS)
     * @return Riferimento alla Lettura corrispondente
     */
    Lettura &operator[](const size_t index) { return data[index]; }

    /**
     * @brief Accesso in sola lettura a una Lettura del sensore.
     *
     * @param index Indice del sensore (0 <= index < NUM_SENSORS)
     * @return Riferimento const alla Lettura corrispondente
     */
    const Lettura &operator[](const size_t index) const { return data[index]; }

private:
    Lettura data[NUM_SENSORS]; // Array di letture per ciascun sensore
};

#endif