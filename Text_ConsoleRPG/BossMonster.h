#pragma once
#include <string>
#include <memory>	
#include "Character.h"
#include "Player.h"

//전방선언 필요?

class BossMonster :public Character
{
public:
	BossMonster();
	// 소멸자 해야하나?
	
	void attack(std::shared_ptr<Character> enemy) override;

	void takeDamage(int amount) override;

	void printStatus() override;
	
	void death() override;

<<<<<<< Updated upstream
	void attackPattern4(Player* player);

	void attackPattern4CheckAnswer(Player* player);
=======
	void attackPattern4(std::shared_ptr<Character> enemy);
>>>>>>> Stashed changes

	int determinePhase(int currentHP);

	// getters
	int getCorrectAnswer();
	int getPhase();
	bool getIsInvincible();

	// setters

private:
	bool isInvincible = false;
	int phase = 1;
	int correctAnswer = 0;
};