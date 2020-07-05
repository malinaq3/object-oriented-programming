#pragma once

#include "Cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(std::string name,
            size_t amount,
            size_t basePrice,
            size_t percentage);

    ~Alcohol() = default;

    size_t getPercentage() const;

    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    void nextDay() override;
    
private:
    const size_t max_percentage_{96};
    size_t percentage_;
};
