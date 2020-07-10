#include "Store.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::shared_ptr<Cargo>>::iterator Store::findCargo(Cargo* cargo) {
    return std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& cargoTmp){
        return cargoTmp->getName() == (*cargo).getName();
    });
}

Response Store::buy(Cargo *cargo, Player *player) {
    auto indexIt = findCargo(cargo);

    if(indexIt == cargo_.end()){
        std::cout << "There's no cargo in this store like that" << std::endl;
        return Response::no_cargo;
    }
    if(indexIt->get()->getAmount() < cargo->getAmount()){
        std::cout << "Not enough amonut of cargo in this store" << std::endl;
        return Response::lack_of_cargo;
    }
    if(player->getMoney() < cargo->getPrice() * cargo->getAmount()){
        std::cout << "Not enough money to buy this cargo" << std::endl;
        return Response::lack_of_money;
    }
    if(player->getAvailableSpace() - cargo->getAmount() < 0){
        std::cout << "Not enough space";
        return Response::lack_of_space;
    }

    player->buyCargo(cargo);
    return Response::done;
}

Response Store::sell(Cargo *cargo, Player *player) {
    auto indexIt = findCargo(cargo);

    if(indexIt == player->getShip()->getCargo().end()){
        std::cout << "You don't have that cargo to sell" << std::endl;
        return Response::no_cargo;
    }
    if(indexIt->get()->getAmount() < cargo->getAmount()){
        std::cout << "Not enough cargo" << std::endl;
        return Response::lack_of_cargo;
    }

    player->sellCargo(cargo);
    return Response::done;
}
