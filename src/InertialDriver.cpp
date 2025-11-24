#include "../include/InertialDriver.h"
#include <iostream>

InertialDriver::InertialDriver() : buffer(BUFFER_DIM) {}

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
{ // rimosso parametro const Misura& out
    if (current_size == 0)
    {
        throw std::out_of_range("Buffer vuoto: impossibile pop_front");
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

Lettura InertialDriver::get_reading(int index) const
{
    if (current_size == 0 || index < 0 || index >= buffer[head].NUM_SENSORS)
    {
        throw std::out_of_range("Indice non valido o buffer vuoto");
    }
    int last = (tail - 1 + BUFFER_DIM) % BUFFER_DIM;
    return buffer[last][index];
}

 int InertialDriver::incrementIndex(int& index) {
     int oldIndex = index;
     index = (index + 1) % BUFFER_DIM;
     return oldIndex;
 };

