#include "Character.h"
#include "Windows.h"
#include <iostream>

Character::Character(std::string name) 
{
	this->name = name;
}

void Character::attack(std::shared_ptr<Character> enemy)
{
	std::cout <<"공격합니다!" << std::endl;
}
void Character::death()
{
	std::cout << "캐릭터가 사망했습니다." << std::endl;
}
void Character::printStatus()
{
	std::cout << "캐릭터 이름: " << name << std::endl;
	std::cout << "레벨: " << level << std::endl;
	std::cout << "최대 HP: " << maxHP << std::endl;
	std::cout << "현재 HP: " << currentHP << std::endl;
	std::cout << "공격력: " << ATK << std::endl;
	std::cout << "속도: " << speed << std::endl;
}
void Character::takeDamage(int amount) {
	this->currentHP -= amount; // 현재 체력 차감

	std::cout << name << "이(가) " << amount << "의 피해를 입었습니다!" << std::endl;
	Sleep(500);
	if (this->currentHP <= 0) {
		this->currentHP = 0;
		this->death(); // 체력이 0 이하면 사망 처리 호출
	}
}

// getter 함수
std::string Character:: getName()
{
	return name;
}
int Character::getLevel()
{
	return level;
}
int Character::getMaxHP()
{
	return maxHP;
}
int Character::getCurrentHP()
{
	return currentHP;
}
int Character::getATK()
{
	return ATK;
}
int Character::getSpeed()
{
	return speed;
}
int Character::getExp()
{
	return exp;
}
std::string Character::getHPsubStat() {
	// 기본 체력(100)과 레벨업당 성장치(60)를 제외한 순수 추가 스탯 계산
	int subStat = maxHP - 100 - (level - 1) * 60;

	if (subStat > 0)
	{
		// 추가 스탯이 있는 경우: "기본+성장치 + 추가스탯" 형식으로 반환
		return std::to_string(maxHP) + "+" + "("+std::to_string(subStat)+")";
	}

	// 추가 스탯이 없는 경우 전체 수치만 문자열로 반환
	return std::to_string(maxHP);
}

// setter 함수

void Character::setMaxHP(int MaxHP)
{
	this->maxHP = MaxHP;
}
void Character::setCurrentHP(int currentHP)
{
	this->currentHP = currentHP;
}
void Character::setATK(int ATK)
{
	this->ATK = ATK;
}
void Character::setExp(int Exp)
{
	this->exp = Exp;
}
void Character::setSpeed(int speed)
{
	this->speed = speed;
}
void Character::setLevel(int level)
{
	this->level = level;
}