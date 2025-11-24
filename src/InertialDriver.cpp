#include "../include/InertialDriver.h"
#include <iostream>

void InertialDriver::push_back(const Misura &measure)
{
    buffer[tail] = measure;
    incrementIndex(tail);
    if (current_size == BUFFER_DIM)
    {
        incrementIndex(head);
    }
    else
    {
        current_size++;
    }
}

Misura &InertialDriver::pop_front()
{
    if (current_size == 0)
    {
        throw std::out_of_range("**errore**: buffer impossibile pop_front");
    }
    current_size--;
    return buffer[incrementIndex(head)];
}

void InertialDriver::clear_buffer()
{
    current_size = 0;
    head = 0;
    tail = 0;
}

std::ostream &operator<<(std::ostream &os, const InertialDriver &driver)
{
    if (driver.get_current_size() == 0)
    {
        os << "[Buffer vuoto]";
        return os;
    }

    int last = (driver.tail - 1 + driver.BUFFER_DIM) % driver.BUFFER_DIM;
    os << "Ultima misura: ";
    os << "("
       << driver.buffer[last][0].getYawV() << ", "
       << driver.buffer[last][1].getYawA() << ", "
       << driver.buffer[last][2].getPitchV() << ", "
       << driver.buffer[last][3].getPitchA() << ", "
       << driver.buffer[last][4].getRollV() << ", "
       << driver.buffer[last][5].getRollA() << ") ";
    return os;
}

Lettura InertialDriver::get_reading(int index) const
{
    if (current_size == 0 || index < 0 || index >= buffer[head].NUM_SENSORS) // controllo validita' indice
    {
        throw std::out_of_range("Indice non valido o buffer vuoto");
    }
    int last = (tail - 1 + BUFFER_DIM) % BUFFER_DIM;
    return buffer[last][index];
}

// Incrementa l'indice passato in modo circolare
// Il parametro è passato per riferimento (&) così da modificare direttamente il suo valore
// restituisce il valore dell'indice preincrementazione

int InertialDriver::incrementIndex(int &index)
{
    int oldIndex = index;
    index = (index + 1) % BUFFER_DIM;
    return oldIndex;
};
