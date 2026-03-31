#include "Monster.h"

// Monster 몬스터 
Monster::Monster(std::string name) : Character(name)
{
	this->name = name;
}

void Monster::attack(std::shared_ptr<Character> enemy)
{
	std::cout << this->name << "이(가)" << enemy->getName() << "을(를) 공격했다!" << std::endl;
	Sleep(1000);
	enemy->takeDamage(this->getATK());
	std::cout << "\n[enter 키를 눌러 계속하기]";
	_getch();
	system("cls");
}

void Monster::takeDamage(int amount)
{
	// 회피 확률 계산 (예: 속도 1당 0.5% 확률, 최대 30%)
	int dodgeChance = (this->speed > 60) ? 30 : this->speed / 2;

	if ((rand() % 100) < dodgeChance) {
		std::cout << "\n 휘릭! " << name << "이(가) 공격을 가볍게 피했습니다!" << std::endl;
		Sleep(500);
		return; // 데미지를 입지 않고 함수 종료
	}

	// 회피 실패 시 부모 클래스의 기본 데미지 로직 실행
	Character::takeDamage(amount);
}

void Monster::death()
{
	std::cout << this->name << "이(가) 쓰러졌다!" << std::endl;
	Sleep(500);
}

void Monster::printStatus()
{
	std::cout << "몬스터의 이름: " << name << std::endl;
	std::cout << "몬스터의 레벨: " << level << std::endl;
	std::cout << "몬스터의 최대 HP: " << maxHP << std::endl;
	std::cout << "몬스터의 현재 HP: " << currentHP << std::endl;
	std::cout << "몬스터의 공격력: " << ATK << std::endl;
	std::cout << "몬스터의 속도: " << speed << std::endl;
}

int Monster::getMoney() const
{

	return this->money;
}

std::vector<std::string> Monster::getAsciiArt() const
{
	return this->asciiArt;
}

// Monster를 상속받은 실제로 생성할 몬스터 클래스들 구현
// 멤버 변수들 값은 일단 임의로 설정한 상태
// Chonkycat 뚱냥이
Chonkycat::Chonkycat() : Monster("뚱냥이")
{
	this->maxHP = 48;
	this->currentHP = 48;
	this->ATK = 9;
	this->speed = 5;
	this->level = 1;
	this->exp = 15;
	this->money = 10;
	this->asciiArt = {
		R"(      /\_/\  )",
		R"(     ( o.o ) )",
		R"(      > ^ <  )",
		R"(     (  "  ) )"
	};
}



// Bulldog 불독
Bulldog::Bulldog() : Monster("불독")
{
	this->maxHP = 93;
	this->currentHP = 93;
	this->ATK = 21;
	this->speed = 13;
	this->level = 2;
	this->exp = 28;
	this->money = 50;
	this->asciiArt = {
		R"(     / \---/ \  )",
		R"(    (  O   O  ) )",
		R"(     \   m   /  )",
		R"(     |       |  )",
		R"(     |   _   |  )",
		R"(     \__/ \__/  )"
	};
}



// Ghost 고스트
Ghost::Ghost() : Monster("고스트")
{
	this->maxHP = 104;
	this->currentHP = 104;
	this->ATK = 54;
	this->speed = 60;
	this->level = 3;
	this->exp = 49;
	this->money = 100;
	this->asciiArt = {
		R"(          .--.  )",
		R"(         (>  <) )",
		R"(         | ww | )",
		R"(         \    / )",
		R"(          `~~`  )"
	};
}



// Golem 골렘
Golem::Golem() : Monster("골렘")
{
	this->maxHP = 158;
	this->currentHP = 158;
	this->ATK = 100;
	this->speed = 1;
	this->level = 4;
	this->exp = 97;
	this->money = 500;
	this->asciiArt = {
		R"(     [|||||||]   )",
		R"(    [|[ o o ]|]  )",
		R"(    [|   ^   |]  )",
		R"(     [||___||]   )",
		R"(      /|   |\    )"
	};
}



// LuckyMonster 럭키 몬스터
LuckyMonster::LuckyMonster() : Monster("???")
{
	// 난수 생성
	std::random_device rd;
	std::mt19937 generate(rd());


	this->maxHP = std::uniform_int_distribution<int>(50, 500)(generate);
	this->currentHP = this->maxHP;
	this->ATK = std::uniform_int_distribution<int>(5, 100)(generate);
	this->speed = std::uniform_int_distribution<int>(1, 100)(generate);
	this->level = std::uniform_int_distribution<int>(1, 4)(generate);
	this->exp = std::uniform_int_distribution<int>(1, 200)(generate);
	this->money = std::uniform_int_distribution<int>(1, 5000)(generate);
	this->asciiArt = {
		R"(      .-------.  )",
		R"(     /   $   /|  )",
		R"(    .-------. |  )",
		R"(    |  _ _  | /  )",
		R"(    '-------'    )"
	};
}