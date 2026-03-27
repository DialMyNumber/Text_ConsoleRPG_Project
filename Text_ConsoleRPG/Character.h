#pragma once
#include <string>
class Enemy; // Enemy 클래스에 대한 전방 선언

class Character
{
public:
	Character(std::string name);
	virtual ~Character() = default; // 안전한 메모리 해제를 위한 가상 소멸자

	virtual void attack(Character* enemy) = 0;
	virtual void death();
	virtual void printStatus();
	virtual void takeDamage(int amount); // 데미지를 입는 가상 함수 추가

	// getter 함수
	std::string getName();
	int getLevel();
	int getMaxHP();
	int getCurrentHP();
	int getATK();
	int getSpeed();

	int getExp();

	// setter 함수

	void setMaxHP(int MaxHP);
	void setCurrentHP(int currentHP);
	void setATK(int ATK);
	void setExp(int Exp);
	void setSpeed(int speed);

	void setLevel(int level);

protected:

	std::string name; 
	int maxHP; 
	int currentHP; 
	int level;
	int ATK; 
	int exp; 
	int speed;
};

