#include "Player.h"
#include <iostream>
#include <windows.h>


// 부모 생성자 Character(name)을 호출하여 이름을 초기화합니다.
Player::Player(std::string name, std::string job) : Character(name), money(1000)
{
    this->job = job;
    this->level = 1;      // 기본값 초기화
    this->maxHP = 100;
    this->currentHP = 100;
    this->ATK = 100;
    this->exp = 0;
    this->speed = 5;

    // 인벤토리 생성
    inventory = std::make_shared<Inventory>(10);
}

bool Player::BuyItem(std::shared_ptr<ItemBase> item, size_t amount)
{
    size_t totalCost = item->buyCost * amount;

    // 1. 돈이 충분한가?
    if (!money.canAfford(totalCost)) {
        std::cout << "골드가 부족합니다!" << std::endl;
        return false;
    }

    // 2. 인벤토리에 공간이 있는가?
    if (inventory->GetAcceptableAmount(item) < amount) {
        std::cout << "인벤토리에 공간이 부족합니다!" << std::endl;
        return false;
    }

    // 3. 결제 및 아이템 추가
    money.spendMoney(totalCost); // 돈 차감
    inventory->AddItem(item, amount); // 아이템 추가

    std::cout << item->itemName << " " << amount << "개를 구매했습니다." << std::endl;
    return true;
}

void Player::attack(std::shared_ptr<Character> enemy)
{
    // 여기에 플레이어만의 공격 로직 구현 (나중에 Enemy의 takeDamage 호출 등)
    if (enemy == nullptr) return;

    std::cout << "[플레이어] " << this->name << "의 맹렬한 공격!" << std::endl;

	Sleep(500); // 공격 모션을 표현하기 위한 딜레이 (500ms)

    // 플레이어의 공격력(ATK)을 적의 takeDamage로 전달
    enemy->takeDamage(this->ATK);
}

void Player::printStatus()
{
    std::cout << "========== PLAYER STATUS ==========" << std::endl;
    std::cout << "직업: " << job << std::endl;
    // 부모 클래스의 printStatus 내용을 그대로 사용하고 싶다면 아래처럼 호출 가능합니다.
    Character::printStatus();
    std::cout << "===================================" << std::endl;
}