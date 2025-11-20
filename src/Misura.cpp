
#include "Misura.h"
#include <iostream>

Misura(const Lettura input[]) { 
    std::copy(input, input + NUM_SENSORS, data); 
}

Misura(std::initializer_list<Lettura> init) {
    int n = std::min((int)init.size(), NUM_SENSORS);
    std::copy(init.begin(), init.begin() + init.size(), data);
    std::fill(data + init.size(), data + NUM_SENSORS, Lettura());
}