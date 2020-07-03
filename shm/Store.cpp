#include "Store.hpp"

#include <iostream>
#include <algorithm>

Response Store::buy(Cargo *cargo, Player *player) {
    //finding this item in store
    auto indexIt = std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& cargoTmp){
        return cargoTmp->getName() == (*cargo).getName();
    });

    if(indexIt == cargo_.end()){
        std::cout << "There's no cargo on ship like that" << std::endl;
        return Response::no_cargo;
    }
    if(indexIt->get()->getAmount() < cargo->getAmount()){
        std::cout << "Not enough amonut of cargo in this store" << std::endl;
        return Response::lack_of_cargo;
    }
    if(player->getMoney() < indexIt->get()->getPrice() * cargo->getAmount()){
        std::cout << "Not enough money to buy this cargo" << std::endl;
        return Response::lack_of_money;
    }
    if(player->getAvailableSpace() - cargo->getAmount() < 0){
        std::cout << "Not enough space";
        return Response::lack_of_space;
    }

    player->getShip()->getCargo().emplace(indexIt, cargo);
    player->countAvailableSpace();
    player->setMoney(player->getMoney() - cargo->getPrice() * cargo->getAmount());

    return Response::done;
}

Response Store::sell(Cargo *cargo, Player *player) {
    //finding this item in player
    auto indexIt = std::find_if(player->getShip()->getCargo().begin(), player->getShip()->getCargo().end(), [cargo](const auto& cargoTmp){
        return cargoTmp->getName() == (*cargo).getName();
    });

    if(indexIt == player->getShip()->getCargo().end()){
        std::cout << "You don't have that cargo to sell" << std::endl;
        return Response::no_cargo;
    }
    if(indexIt->get()->getAmount() < cargo->getAmount()){
        std::cout << "Not enough cargo" << std::endl;
        return Response::lack_of_cargo;
    }
    if(indexIt->get()->getAmount() == cargo->getAmount()) {
        player->getShip()->getCargo().erase(indexIt);
        player->setMoney(player->getMoney() + cargo->getAmount() * cargo->getPrice());
    }

     return Response::done;
}
