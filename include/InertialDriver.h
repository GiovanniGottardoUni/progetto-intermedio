#ifndef INERTIAL_DRIVER_H
#define INERTIAL_DRIVER_H

#include <iostream>
#include "Lettura.h"
#include "MyVector.h"
#include "Misura.h"

class InertialDriver {

    private:
        MyVector<Misura> buffer;    // il buffer circolare
        int current_size = 0;       // numero elementi nella coda
        int tail = 0;               // indice del prossimo elemento da scrivere
        int head = 0;               // indice del prossimo elemento da leggere
        
        int incrementIndex(int& index); // incrementa index circolarmente e ritorna il vecchio valore
        
    public:

        static constexpr size_t BUFFER_DIM = 100;

        InertialDriver();

        int get_current_size() const { return current_size; };

        void push_back(const Misura& m);

        Misura& pop_front();

        Lettura get_reading(const int index) const; // const->leggo i dati della classe ma non li modifico
        
        void clear_buffer();

        friend std::ostream& operator<<(std::ostream& os, const InertialDriver& driver);

};

#endif // INERTIAL_DRIVER_H
