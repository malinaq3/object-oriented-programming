#pragma once

#include <string>

class Cargo {
public:
    Cargo();
    Cargo(std::string n, size_t a, size_t bP);

    virtual ~Cargo() = default;

    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;
    virtual size_t getPrice() const = 0;

    virtual void nextDay() = 0;

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo& checkCargo) const;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
