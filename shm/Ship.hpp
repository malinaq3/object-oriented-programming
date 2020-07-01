#pragma once

#include "Cargo.hpp"

#include <string>
#include <vector>
#include <memory>

#include "Cargo.hpp"

class Ship {
public:
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, std::vector<std::shared_ptr<Cargo>> cargo);
    Ship(int maxCrew, int speed, size_t id);

    void setName(const std::string& name);
    void Load(const std::shared_ptr<Cargo>& cargo);
    void Unload(Cargo* cargo);

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);


    size_t getCapacity() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    std::string getName() const;
    size_t getId() const;
    std::vector<std::shared_ptr<Cargo>> getCargo() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;

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

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;

    std::vector<std::shared_ptr<Cargo>> cargo_;

};
