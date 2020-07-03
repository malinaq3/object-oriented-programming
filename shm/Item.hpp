#pragma once
#include <string>
#include "Cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity {
        common = 1,
        rare = 5,
        epic = 10,
        legendary = 20
    };
    Item(const std::string name, size_t amount, size_t basePrice, Rarity rarity)
        : Cargo(name, amount, basePrice), rairty_(rarity) {}

    size_t getPrice() const override;
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    Rarity getRarity() const;

    bool operator==(const Cargo& item) const;
    bool operator!=(const Cargo& item) const;
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

private:
    const Rarity rairty_;
};
