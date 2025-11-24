#ifndef MISURA_H
#define MISURA_H

#include "lettura.h"
#include <iostream>

class Misura {
public:

    static constexpr int NUM_SENSORS = 17;

    Misura() = default;

    Misura(const Lettura input[]);

    Misura(std::initializer_list<Lettura> init);

    Lettura& operator[] (const size_t index){ return data[index]; }
    const Lettura& operator[] (const size_t index) const { return data[index];}

private:
    Lettura data[NUM_SENSORS];
  
};

#endif