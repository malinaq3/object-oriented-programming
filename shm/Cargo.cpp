#include "Cargo.hpp"

#include <iostream>

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}
Cargo& Cargo::operator-=(size_t amount) {
    if (amount > amount_) {
        std::cerr << "Amount can't be less than 0!\n";
        return *this;
    }
    amount_ -= amount;
    return *this;
}
