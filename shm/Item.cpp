#include "Item.hpp"

Item::Item(const std::string name,
           size_t amount,
           size_t basePrice,
           Rarity rarity)
    : Cargo(name, amount, basePrice),
      rairty_(rarity) {}

Rarity Item::getRarity() const {
    return rairty_;
}

//Override from Cargo
size_t Item::getPrice() const {
    return basePrice_ * static_cast<size_t>(rairty_);
}
std::string Item::getName() const  { 
        return name_; 
}
size_t Item::getAmount() const  { 
    return amount_; 
}
size_t Item::getBasePrice() const  { 
    return basePrice_; 
}
