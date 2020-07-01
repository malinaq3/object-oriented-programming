#include "Player.hpp"

#include <algorithm>

Player::Player(std::shared_ptr<Ship> s = nullptr, size_t m = 0, size_t as = 0)
    : ship_(s), money_(m), availableSpace_(as) {}

Cargo* Player::getCargo(size_t index) const {
    if (index > (ship_->getCargo().size())) {
        return nullptr;
    }
    return &ship_->getCargo()[index];
}

void Player::countAvailableSpace() {
    auto amoutOfCargo = ship_->getCargo().size();
    auto availableSpaceTmp = ship_->getCapacity() - amoutOfCargo;

    if (availableSpaceTmp <= 0) {
        availableSpace_ = 0;
    }
    availableSpace_ = availableSpaceTmp;
}
