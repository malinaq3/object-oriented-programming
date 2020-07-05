#pragma once

#include <string>
#include <vector>

#include "Cargo.hpp"
#include "Delegate.hpp"

class Ship {
public:
    Ship();
    Ship(int capacity,
         int maxCrew,
         int speed,
         const std::string& name,
         size_t id,
         Delegate* delegate = nullptr);

    Ship(int maxCrew,
         int speed,
         size_t id,
         Delegate* delegate = nullptr);

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    void nextDay();

    void setName(const std::string& name) {
        name_ = name;
    }

    size_t getCapacity() const {
        return capacity_;
    }
    size_t getMaxCrew() const {
        return maxCrew_;
    }
    size_t getSpeed() const {
        return speed_;
    }
    std::string getName() const {
        return name_;
    }
    size_t getId() const {
        return id_;
    }
    std::vector<Cargo> getCargo() const {
        return cargo_;
    }
    void setDelegate(Delegate* delegate) {payCrew = delegate; }

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<Cargo> cargo_;
    Delegate* payCrew;
};
