#pragma once

#include "Cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol::Alcohol(const std::string& name,
                     size_t amount,
                     size_t basePrice,
                     size_t percentage)
        : Cargo(name, amount, basePrice), percentage_(percentage) {}

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& other) const override;

    size_t getPrice() const override;
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

private:
    const size_t max_percentage_{96};
    size_t percentage_;
};
