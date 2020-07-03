#pragma once

#include <vector>

#include "Observer.hpp"

class Time {
public:
    void addSubscriber(Observer* obs);
    void removeSubscriber(Observer* obs);
    Time& operator++();

private:
    std::vector<Observer*> observersList_;
    size_t elapsedTime_{0};

    void notify();
};
