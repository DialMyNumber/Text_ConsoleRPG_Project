#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Money.h"

class Player : public Character
{
public:
    // 부모 생성자를 호출해야 합니다.
    Player(std::string name, std::string job);
    virtual ~Player() = default;

    // 순수 가상 함수였던 attack을 반드시 구현해야 합니다. (override 키워드 권장)
    virtual void attack(Character* enemy) override;

    // 부모의 기능을 확장하고 싶다면 printStatus도 재정의할 수 있습니다.
    virtual void printStatus() override;

    Inventory& GetInventory() { return inventory; }; // 플레이어의 인벤토리
	Money& GetMoney() { return money; }; // 플레이어의 돈

	bool BuyItem(std::shared_ptr<ItemBase> item, size_t amount);    
    

private:
    std::string job; // 플레이어만의 전용 속성 추가

	// 플레이어는 인벤토리와 돈을 가지고 있습니다. (Character에는 없는 속성)
	Inventory inventory; // 플레이어의 인벤토리
	Money money; // 플레이어의 돈
};