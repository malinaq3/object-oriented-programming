#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(const std::string& name,
          size_t amount,
          size_t basePrice,
          size_t expiry_date, )
        : Cargo(name, amount, basePrice), expiry_date_(expiry_date), timeToSpoil_(expiry_date) {}

    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& checkCargo) const override;

    Fruit& operator--();

    //override from Observer.hpp
    void nextDay() override;

protected:
    size_t timeToSpoil_;
    size_t expiry_date_;
};
