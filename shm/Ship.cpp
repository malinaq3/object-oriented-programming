#include "Ship.hpp"

#include <iostream>
#include <algorithm>

Ship::Ship()
        : id_(-1) {}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, std::vector<std::shared_ptr<Cargo>> cargo)
        : capacity_(capacity),
          maxCrew_(maxCrew),
          crew_(0),
          speed_(speed),
          name_(name),
          id_(id),
          cargo_(cargo){};

Ship::Ship(int maxCrew, int speed, size_t id)
        : Ship(0, maxCrew, speed, "", id, cargo_) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

void Ship::Load(const std::shared_ptr<Cargo> &cargo) {
    if(capacity_ - cargo->getAmount() < 0){
        std::cout << "Not enough space on ship" << std::endl;
        return;
    }
    //set new amount of cargo
    auto found = std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& car){ return car->getName() == cargo->getName(); });
    if(found != cargo_.end()){
        (*found)->setAmout((*found)->getAmount() + cargo->getAmount());
    }
    else{
        cargo_.push_back(cargo);
    }
    capacity_ -= cargo->getAmount();
}

void Ship::Unload(Cargo *cargo) {
    auto found = std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& car){ return car->getName() == cargo->getName(); });
    if(found == cargo_.end()){
        std::cout << "No " << cargo->getName() << " on ship";
        return;
    }
    if((*found)->getAmount() - cargo->getAmount() <= 0){
        cargo_.erase(found);
    }
    else{
        (*found)->setAmount((*found)->getAmount() - cargo->getAmount());
    }
}

Ship& Ship::operator-=(size_t num) {
    if (num > crew_) {
        std::cerr << "Number of papays is lower than 0\n";
        return *this;
    }
    crew_ -= num;
    return *this;
}
Ship& Ship::operator+=(size_t num) {
    if (crew_ + num > maxCrew_) {
        std::cerr << "Too many papays!\n";
        return *this;
    }
    crew_ += num;
    return *this;
}

size_t Ship::getCapacity() const {
    return capacity_;
}
size_t Ship::getMaxCrew() const {
    return maxCrew_;
}
size_t Ship::getSpeed() const {
    return speed_;
}
std::string Ship::getName() const {
    return name_;
}
size_t Ship::getId() const {
    return id_;
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    return cargo_[index];
}

std::vector<std::shared_ptr<Cargo>> Ship::getCargo() const {
    return cargo_;
}
