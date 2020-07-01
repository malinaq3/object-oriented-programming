#include "Cargo.hpp"

#include <iostream>

Cargo::Cargo(std::string n = "", size_t a = 0, size_t bp = 0)
    : name_(n), amount_(a), basePrice_(bp){};

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

bool Cargo::operator==(const Cargo& checkCargo) const {
    return (name_ == checkCargo.name_ &&
            amount_ == checkCargo.amount_ &&
            basePrice_ == checkCargo.basePrice_);
}
