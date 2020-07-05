#pragma once

#include "Cargo.hpp"

enum class Rarity {
    common = 1,
    rare = 5,
    epic = 10,
    legendary = 20
};

class Item : public Cargo {
public:
    Item(const std::string name,
         size_t amount,
         size_t basePrice,
         Rarity rarity);
         
    Rarity getRarity() const;

    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;

private:
    const Rarity rairty_;
};
