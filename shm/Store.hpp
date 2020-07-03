#pragma once

#include "Observer.hpp"
#include "Player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space,
    no_cargo
};

class Store : public Observer {
public:
    Response buy(Cargo* cargo, Player* player);
    Response sell(Cargo* cargo, Player* player);

    //override from Observer.hpp
    void nextDay() override;

private:
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
