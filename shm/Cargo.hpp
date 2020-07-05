#pragma once

#include <string>

class Cargo {
public:
    Cargo(std::string n = "", size_t a = 0, size_t bp = 0);

    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBasePrice() const { return basePrice_; }

    virtual void nextDay() = 0;
    
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo& checkCargo) const;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
