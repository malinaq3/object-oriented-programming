#include "Fruit.hpp"

Fruit::Fruit(std::string name,
             size_t amount,
             size_t basePrice,
             size_t expiryDate)
    : Cargo(name, amount, basePrice),
      expiryDate_(expiryDate) {}

Fruit::Fruit(std::string name,
             size_t amount,
             size_t basePrice,
             size_t expiryDate,
             size_t timeElapsed)
    : Cargo(name, amount, basePrice),
      expiryDate_(expiryDate),
      timeElapsed_(timeElapsed) {}

size_t Fruit::getTimeElapsed() const {
    return timeElapsed_;
}
size_t Fruit::getExpiryDate() const {
    return expiryDate_;
}

//Override from Cargo
size_t Fruit::getPrice() const {
    if (timeElapsed_ >= expiryDate_) {
        return 0;
    }
    return static_cast<size_t>(
        basePrice_ * ((float)(expiryDate_ - timeElapsed_)) / expiryDate_);
}
std::string Fruit::getName() const {
    return name_;
}
size_t Fruit::getAmount() const {
    return amount_;
}
size_t Fruit::getBasePrice() const {
    return basePrice_;
}
