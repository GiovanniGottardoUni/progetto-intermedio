#ifndef INERTIAL_DRIVER_H
#define INERTIAL_DRIVER_H

#include <iostream>
#include "Lettura.h"
#include "MyVector.h"
#include "Misura.h"

/**
 * @class InertialDriver
 * @brief Classe che gestisce un buffer circolare di misure.
 *
 * La classe implementa funzioni per inserire, leggere e rimuovere
 * elementi da un buffer di dimensione fissa. Gestisce la logica
 * di buffer circolare e sovrascrive i dati più vecchi quando il
 * buffer è pieno.
 */
class InertialDriver
{

public:
    static constexpr size_t BUFFER_DIM = 100; // dimiensione massima del buffer

    /**
     * @brief Costruttore della classe.
     *
     * Inizializza il buffer.
     */
    InertialDriver() : buffer(BUFFER_DIM) {}

    /**
     * @brief Inserisce una misura nel buffer.
     *
     * @param measure Misura da inserire.
     */
    void push_back(const Misura &measure);

    /**
     * @brief Rimuove la misura più vecchia dal buffer.
     *
     * @return Riferimento alla misura rimossa.
     * @throw std::out_of_range se il buffer è vuoto.
     */
    Misura &pop_front();

    /**
     * @brief Legge un valore specifico da una misura nel buffer.
     *
     * @param index Indice della misura.
     * @return Lettura desiderata.
     * @throw std::out_of_range se l'indice non è valido.
     */
    Lettura get_reading(const int index) const;

    /**
     * @brief ritorna il numero di elementi nel buffer.
     */
    int get_current_size() const { return current_size; };

    /**
     * @brief Svuota completamente il buffer.
     */
    void clear_buffer();

    /**
     * @brief Stampa il contenuto del buffer su uno stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const InertialDriver &driver);

private:
    MyVector<Misura> buffer; // il buffer circolare
    int current_size = 0;    // numero elementi nella coda
    int tail = 0;            // indice del prossimo elemento da scrivere
    int head = 0;            // indice del prossimo elemento da leggere

    /**
     * @brief Incrementa index circolarmente e ritorna il vecchio valore.
     *
     * @param index tail/head del buffer.
     */
    int incrementIndex(int &index);
};

#endif // INERTIAL_DRIVER_H
