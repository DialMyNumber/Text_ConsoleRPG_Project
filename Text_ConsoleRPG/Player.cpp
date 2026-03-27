#include "Player.h"
#include <iostream>

// 부모 생성자 Character(name)을 호출하여 이름을 초기화합니다.
Player::Player(std::string name, std::string job) : Character(name)
{
    this->job = job;
    this->level = 1;      // 기본값 초기화
    this->maxHP = 100;
    this->currentHP = 100;
    this->ATK = 10;
    this->exp = 0;
    this->speed = 5;
}

void Player::attack(Enemy* enemy)
{
    // 여기에 플레이어만의 공격 로직 구현 (나중에 Enemy의 takeDamage 호출 등)
    std::cout << "[플레이어] " << name << "이(가) 적을 공격합니다!" << std::endl;
}

void Player::printStatus()
{
    std::cout << "========== PLAYER STATUS ==========" << std::endl;
    std::cout << "직업: " << job << std::endl;
    // 부모 클래스의 printStatus 내용을 그대로 사용하고 싶다면 아래처럼 호출 가능합니다.
    Character::printStatus();
    std::cout << "===================================" << std::endl;
}