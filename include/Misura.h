#ifndef MISURA_H
#define MISURA_H

#include "lettura.h"
#include <iostream>

class Misura {
public:
    Misura(const Lettura input[]);

    Misura(std::initializer_list<Lettura> init);

    Lettura& operator[] (const size_t index){ return data[index]; }
    const Lettura& operator[] (const size_t index) const { return data[index];}

    int getNumSensors() const { return NUM_SENSORS;}

private:
    static constexpr int NUM_SENSORS = 17;
    Lettura data[NUM_SENSORS];
  
};

#endif