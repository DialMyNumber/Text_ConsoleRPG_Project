//TransactionManager.h
#pragma once
#include <memory>

class Shop;
class ItemBase;
class Money;
class Player;


class TransactionManager
{
public:
    static bool buyItem(Shop& shop, std::shared_ptr<ItemBase> item, std::shared_ptr<Player> player, size_t count);
    static bool sellItem(Shop& shop, std::shared_ptr<ItemBase> item, std::shared_ptr<Player> player, size_t count);
    static bool buyBackItem(Shop& shop, std::shared_ptr<ItemBase> item, std::shared_ptr<Player> player, size_t count);
};