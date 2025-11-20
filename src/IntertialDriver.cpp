#include "../include/InertialDriver.h"
#include <iostream>

void InertialDriver::push_back(const Misura &m)
{
    // riempe se il vettore non ha ancora raggiunto la dimensione target(100)
    if (buffer.getSize() < BUFFER_DIM)
    {
        buffer.push_back(m);
        tail = (tail + 1) % BUFFER_DIM;
        current_size++;
    }
    // sovrascrivo gli elementi se il vettore ha raggiunto i 100 elementi
    else
    {
        buffer[tail] = m;
        tail = (tail + 1) % BUFFER_DIM;
        if (current_size == BUFFER_DIM)
        {
            head = (head + 1) % BUFFER_DIM;
        }
        else
        {
            current_size++;
        }
    }
}

Misura InertialDriver::pop_front(const Misura& out) {
    if(current_size > 0) {
        current_size--;
        return buffer.at(incrementIndex(head));
    }
}

void InertialDriver::clear_buffer(){
    current_size = 0;
    head = 0;
    tail = 0;
}

std::ostream &operator<<(std::ostream &os, const InertialDriver &driver){
    if (driver.get_current_size() == 0)
    {
        os << "[Buffer vuoto]";
        return os;
    }

    int last = (driver.tail - 1 + BUFFER_DIM) % BUFFER_DIM;
    os << "Ultima misura: ";
    for (int i = 0; i < driver.get_current_size(); ++i)
    {
        os << "("
           << driver.buffer[last][i].getYawV() << ", "
           << driver.buffer[last][i].getYawA() << ", "
           << driver.buffer[last][i].getPitchV() << ", "
           << driver.buffer[last][i].getPitchA() << ", "
           << driver.buffer[last][i].getRollV() << ", "
           << driver.buffer[last][i].getRollA() << ") ";
    }
    return os;
}

Lettura InertialDriver::get_reading(int index) const{
    if(current_size == 0 || index < 0 || index >= buffer[head].getNumSensors()){
        throw std::out_of_range("Indice non valido o buffer vuoto");
    }
    int last = (tail - 1 + BUFFER_DIM) % BUFFER_DIM;
    return buffer[last][index];
}

    int incrementIndex(int index) {
        int oldIndex = index;
        index = (index + 1) % BUFFER_DIM;
        return oldIndex;
    };
