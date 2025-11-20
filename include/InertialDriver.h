#ifndef INERTIAL_DRIVER_H
#define INERTIAL_DRIVER_H

#include <iostream>
#include "Lettura.h"
#include "MyVector.h"
#include "Misura.h"

class InertialDriver
{
private:
    MyVector<Misura> buffer; // il buffer circolare
    int current_size = 0;    // numero elementi nella coda
    int tail;                // indice del prossimo elemento da scrivere
    int head;                // indice del prossimo elemento da leggere
    static constexpr size_t BUFFER_DIM = 100;

    int incrementIndex(int index);

public:
    InertialDriver();

    int get_current_size() const { return current_size; };

    void push_back(const Misura& m);

    Misura pop_front(const Misura& out);

    Lettura get_reading(const int index) const; // const->leggo i dati della classe ma non li modifico
    
    void clear_buffer();

    friend std::ostream& operator<<(std::ostream& os, const InertialDriver& driver);

};

#endif // INERTIAL_DRIVER_H
