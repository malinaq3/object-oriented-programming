#include "Ship.hpp"

#include <iostream>

Ship::Ship()
    : id_(-1) {}

Ship::Ship(int capacity,
           int maxCrew,
           int speed,
           const std::string& name,
           size_t id,
           Delegate* delegate)
    : capacity_(capacity),
      maxCrew_(maxCrew),
      crew_(0),
      speed_(speed),
      name_(name),
      id_(id),
      payCrew(delegate) {}

Ship::Ship(int maxCrew,
           int speed,
           size_t id,
           Delegate* delegate)
    : Ship(0, maxCrew, speed, "", id, delegate) {}

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
void Ship::nextDay() {
    size_t crewCost = 1;
    payCrew->payCrew(crew_ * crewCost);
}
