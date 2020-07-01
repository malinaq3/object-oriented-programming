#pragma once

#include "Player.hpp"

enum class Response{
    done, lack_of_money, lack_of_cargo, lack_of_space, no_cargo
};

class Store {
public:
    Response buy(Cargo* cargo, Player* player);
    Response sell(Cargo* cargo, Player* player);
private:
    std::vector<std::shared_ptr<Cargo>> cargo_;
};

