#include "Cargo.hpp"

#include <iostream>

Cargo::Cargo() = default;

Cargo::Cargo(std::string n, size_t a, size_t bP)
    : name_(n), amount_(a), basePrice_(bP){};

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
