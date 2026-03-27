#include <iostream>
#include <string>

#include "BossMonster.h"

BossMonster::BossMonster() :Character("초대형 울트라 찍찍 들쥐")
{
	// 모든 수치는 공유 후 조율할 예정
	maxHP = 10000;
	currentHP = 10000;
	level = 100;
	ATK = 100;
	exp = 100;
	speed = 100;
}

int BossMonster::determinePhase(int currentHP)
{
	if (currentHP > (maxHP * 2 / 3))
	{
		phase = 1;
	}
	else if (currentHP > (maxHP / 3))
	{
		phase = 2;
	}
	else {
		phase = 3;
	}

	return phase;
}

void BossMonster::attack(Enemy* enemy)
{	
	int pattern = 0;

	switch (determinePhase(currentHP))
	{
	case 1:
		pattern = rand() % 4 + 1; // 1~4 랜덤
		break;
	case 2:
		pattern = rand() % 4 + 3; // 3~6 랜덤
		break;
	case 3:
		pattern = rand() % 4 + 4; // 4~7 랜덤
		break;
	}

	switch (pattern)
	{
	case 1:
		std::cout << name << "이(가) [꼬리 휘두르기]를 시전했습니다!\n\n";

		// enemy->setCurrentHP(enemy->getCurrentHP() - (ATK));
		break;
	case 2:
		std::cout << name << "이(가) [산성 침 뱉기]를 시전했습니다!\n\n";

		// enemy->setCurrentHP(enemy->getCurrentHP() - (ATK * 0.7));
		break;
	case 3:
		std::cout << name << "이(가) [고양이 잡는 쥐]를 시전했습니다.\n";
		std::cout << "손톱이 날아옵니다!\n\n";

		// enemy->setCurrentHP(enemy->getCurrentHP() - (ATK * 1.7));
		break;
	case 4:
		attackPattern4(enemy);
		break;
	case 5:
		heal();
		break;
	case 6:
		isInvincible = true;
		// Player쪽에서 만약 isInvincible = true;면 대미지 0을 넣는 거로
		break;
	case 7:
		// 궁극기
		break;
	default:
		std::cout << "공격 패턴 출력 과정에서 오류 발생\n";
	}
}

void BossMonster::printStatus()
{
	std::cout << "현재 " << name << "의 상태입니다\n\n";
	std::cout << "체력: " << getCurrentHP() << "/" << getMaxHP() << "\n";
	std::cout << "민첩성: " << getSpeed() << "\n";
}

void BossMonster::death()
{
	std::cout << name << "크윽... 내가 지다니...!! 찍...\n";
	std::cout << name << "을(를) 쓰러뜨렸습니다~!!\n\n";
}

void BossMonster::attackPattern4(Enemy* enemy)
{
	std::cout << name << "이(가) 퀴즈 공격을 시전합니다!\n\n";
	std::cout << name << ": 너처럼 나쁜 아이는 벌을 받아야 한다 찍찍...\n";
	std::cout << name << ": 하지만 그 전에 너를 평가하겠다 찍찍!\n";
	std::cout << name << ": 과연 내가 내는 퀴즈를 맞출 수 있을까 찍찍~?!?!?!\n\n";

	int random = rand() % 4 + 1;

	switch (random)
	{
	case 1:
		// quiz #1
		break;
	case 2:
		// quiz #2
		break;
	case 3:
		// quiz #3
		break;
	case 4:
		//quiz #4
		break;
	}
}

void BossMonster::heal()
{
	setCurrentHP(getCurrentHP()+100);
}

bool BossMonster::getIsInvincible()
{
	return isInvincible;
}

void BossMonster::setIsInvincible(bool isInvincible)
{
	this->isInvincible = isInvincible;
}