#include "Player.hpp"

#include <algorithm>

Cargo* Player::getCargo(size_t index) const {
    if (index > ship_->getCargo().size())
        return nullptr;
    return ship_->getCargo(index).get();
}

void Player::countAvailableSpace() {
    auto amoutOfCargo = ship_->getCargo().size();
    auto availableSpaceTmp = ship_->getCapacity() - amoutOfCargo;

    if(availableSpaceTmp <= 0)
        availableSpace_ = 0;
    else
        availableSpace_ = availableSpaceTmp;
}

void Player::buyCargo(Cargo *cargo) {
    auto indexIt = getShip()->findCargo(cargo);
    getShip()->getCargo().emplace(indexIt, cargo);
    countAvailableSpace();
    setMoney(getMoney() - cargo->getPrice() * cargo->getAmount());
}

void Player::sellCargo(Cargo *cargo) {
    auto indexIt = getShip()->findCargo(cargo);
    if(indexIt->get()->getAmount() == cargo->getAmount()) {
        getShip()->getCargo().erase(indexIt);
        setMoney(getMoney() + cargo->getAmount() * cargo->getPrice());
    }
}
