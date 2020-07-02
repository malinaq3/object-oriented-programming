#include "Alcohol.hpp"

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(basePrice_ * (float(percentage_)) / max_percentage_);
}

Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
    if (amount_ <= amount) {
        amount_ = 0;
    } else {
        amount_ -= amount;
    }

    return *this;
}
