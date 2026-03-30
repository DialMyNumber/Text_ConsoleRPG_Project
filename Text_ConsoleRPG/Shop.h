//Shop.h
#pragma once
#include <map>
#include <memory>

class ItemBase;

class Shop {
private:
    std::map<std::shared_ptr<ItemBase>, size_t> stock;
    std::map<std::shared_ptr<ItemBase>, size_t> buyBackStock;

public:
    void addStock(std::shared_ptr<ItemBase> item, size_t count);
    bool hasStock(std::shared_ptr<ItemBase> item, size_t count) const;
    void reduceStock(std::shared_ptr<ItemBase> item, size_t count);

    void addBuyBack(std::shared_ptr<ItemBase> item, size_t count);
    bool hasBuyBack(std::shared_ptr<ItemBase> item, size_t count) const;
    void reduceBuyBack(std::shared_ptr<ItemBase> item, size_t count);

    const std::map<std::shared_ptr<ItemBase>, size_t>& getStock() const;
    const std::map<std::shared_ptr<ItemBase>, size_t>& getBuyBack() const;
};