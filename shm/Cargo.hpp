#pragma once

#include <string>

class Cargo {
public:
    Cargo(std::string n = "", size_t a = 0, size_t bp = 0)
        : name_(n), amount_(a), basePrice_(bp){};

    virtual std::string getName() const { return name_; }
    virtual size_t getAmount() const { return amount_; }
    virtual size_t getBasePrice() const { return basePrice_; }
    virtual size_t getPrice() const { return price_; }

    virtual Cargo& operator+=(size_t amount);
    virtual Cargo& operator-=(size_t amount);
    virtual bool operator==(const Cargo& checkCargo) const;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
    size_t price_;
};
