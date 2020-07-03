#include "Item.hpp"

size_t Item::getPrice() const {
    return basePrice_ * static_cast<size_t>(rairty_);
}

Item::Rarity Item::getRarity() const {
    return rairty_;
}

Cargo& Item::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Item::operator==(const Cargo& item) const {
    if (typeid(Item) == typeid(Cargo)) {
    }
}

bool Item::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Item)) {
        const Item* rarity_ptr = static_cast<const Item*>(&cargo);
        return name_ == rarity_ptr->getName() &&
               amount_ == rarity_ptr->getAmount() &&
               basePrice_ == rarity_ptr->getBasePrice() &&
               rairty_ == rarity_ptr->getRarity();
    }
    return false;
}
bool Item::operator!=(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Item)) {
        const Item* rarity_ptr = static_cast<const Item*>(&cargo);
        return name_ != rarity_ptr->getName() ||
               amount_ != rarity_ptr->getAmount() ||
               basePrice_ != rarity_ptr->getBasePrice() ||
               rairty_ != rarity_ptr->getRarity();
    }
    return false;
}