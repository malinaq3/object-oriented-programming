#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(std::string name,
            size_t amount,
            size_t basePrice,
            size_t expiryDate);

    Fruit(std::string name,
            size_t amount,
            size_t basePrice,
            size_t expiryDate,
            size_t timeElapsed);

    size_t getTimeElapsed() const;
    size_t getExpiryDate() const;

    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    void nextDay() override;

private:
    size_t timeElapsed_{0};
    size_t expiryDate_;
};
