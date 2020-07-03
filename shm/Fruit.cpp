#include "Fruit.hpp"

Fruit& Fruit::operator--() {
    if (timeToSpoil_ > 0) {
        --timeToSpoil_;
    }

    return *this;
}

Cargo& Fruit::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}
Cargo& Fruit::operator-=(size_t amount) {
    if (amount > amount_) {
        std::cerr << "Amount can't be less than 0!\n";
        return *this;
    }
    amount_ -= amount;
    return *this;
}
bool Fruit::operator==(const Cargo& checkCargo) const {
    if (typeid(*this).hash_code() != typeid(checkCargo).hash_code()) {
        return false;
    }
    return (name_ == checkCargo.getName() &&
            basePrice_ == checkCargo.getBasePrice());
}

size_t Fruit::getPrice() const override {
    return (timeToSpoil_ / expiry_date_) * basePrice_;
}