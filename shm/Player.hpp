#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Ship.hpp"

class Player {
public:
    Player(std::shared_ptr<Ship> s = nullptr, size_t m = 0, size_t as = 0);

    std::shared_ptr<Ship> getShip() const { return ship_; }
    size_t getMoney() const { return money_; }
    size_t getAvailableSpace() const { return availableSpace_; }

    size_t getSpeed() const { return ship_->getSpeed(); }
    Cargo* getCargo(size_t index) const;

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    void countAvailableSpace();
};
