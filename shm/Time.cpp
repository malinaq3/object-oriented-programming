#include "Time.hpp"
#include <algorithm>

void Time::addSubscriber(Observer* obs) {
    auto it = std::find(observersList_.begin(), observersList_.end(), obs);
    if (it != observersList_.end()) {
        return;
    }
    observersList_.push_back(obs);
}

void Time::removeSubscriber(Observer* obs) {
    auto it = std::find(observersList_.begin(), observersList_.end(), obs);
    if (it == observersList_.end()) {
        return;
    }
    observersList_.erase(it);
}

void Time::notify() {
    for (auto& el : observersList_) {
        el->nextDay();
    }
}

Time& Time::operator++() {
    elapsedTime_++;
    notify();
    return *this;
}