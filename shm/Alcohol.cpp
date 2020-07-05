#include "Alcohol.hpp"

Alcohol::Alcohol(std::string name,
                 size_t amount,
                 size_t basePrice,
                 size_t percentage)
    : Cargo(name, amount, basePrice),
      percentage_(percentage) {}

size_t Alcohol::getPercentage() const {
    return percentage_;
}

//Override from Cargo
size_t Alcohol::getPrice() const {
    return static_cast<size_t>(basePrice_ * (float(percentage_)) / max_percentage_);
}
std::string Alcohol::getName() const {
    return name_;
}
size_t Alcohol::getAmount() const {
    return amount_;
}
size_t Alcohol::getBasePrice() const {
    return basePrice_;
}
void Alcohol::nextDay() {
    if (percentage_ > 0) {
        --percentage_;
    }
    amount_ = 0;
}
