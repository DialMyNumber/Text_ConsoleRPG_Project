#pragma once
#include <string>

#include "Character.h"

class BossMonster :public Character
{
public:
	BossMonster();
	
	void attack(Enemy* enemy) override;

	void printStatus() override;
	
	void death() override;

	void attackPattern4(Enemy* enemy);

	int determinePhase(int currentHP);

	void heal();

	// getters
	bool getIsInvincible();

	// setters
	void setIsInvincible(bool isInvincible);

private:
	bool isInvincible = false;
	int phase = 1;
};