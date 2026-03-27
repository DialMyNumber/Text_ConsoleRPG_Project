#pragma once
#include "Character.h"

class Player : public Character
{
public:
    // 부모 생성자를 호출해야 합니다.
    Player(std::string name, std::string job);

    // 순수 가상 함수였던 attack을 반드시 구현해야 합니다. (override 키워드 권장)
    virtual void attack(Enemy* enemy) override;

    // 부모의 기능을 확장하고 싶다면 printStatus도 재정의할 수 있습니다.
    virtual void printStatus() override;

private:
    std::string job; // 플레이어만의 전용 속성 추가
};