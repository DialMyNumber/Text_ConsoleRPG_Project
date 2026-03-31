#include "ConsumeItem.h"
#include <iostream>
#include "Character.h"
#include "LogMacros.h"
#include "Player.h"
#include <windows.h>

bool HPPotionItem::ApplyEffect(const std::shared_ptr<Character> character)
{
	// 포인터(매개변수) nullptr 값 방어 코드
	if (character != nullptr)
	{
		// 캐릭터 레벨이 사용 조건을 만족하는지 확인
		if (character->getLevel() >= minLevel)
		{
			// 로그 출력
			std::string logMsg = "#ConsumeItem : Success to Apply Item(";
			logMsg.append(itemName);
			logMsg.append(") to ");
			logMsg.append(character->getName());
			LOG_INFO(logMsg);

			// 최대 체력의 30% 회복
			if (character->getCurrentHP() + (character->getMaxHP() * 0.3) >= character->getMaxHP())
			{
				character->setCurrentHP(character->getMaxHP());
			}
			else
			{
				character->setCurrentHP(character->getCurrentHP() + (character->getMaxHP() * 0.3));
			}
			

			return true;
		}
	}

	// 로그 출력
	std::string logMsg = "#ConsumeItem : Failed to Apply Item(";
	logMsg.append(itemName);
	logMsg.append(")");
	LOG_INFO(logMsg);

	return false;
}

bool ExpScroll::ApplyEffect(const std::shared_ptr<Character> character)
{
	// 포인터(매개변수) nullptr 값 방어 코드
	if (character != nullptr)
	{
		// 캐릭터 레벨이 사용 조건을 만족하는지 확인
		if (character->getLevel() >= minLevel)
		{
			// 로그 출력
			std::string logMsg = "#ConsumeItem : Success to Apply Item(";
			logMsg.append(itemName);
			logMsg.append(") to ");
			logMsg.append(character->getName());
			LOG_INFO(logMsg);

			auto characterPtr = std::dynamic_pointer_cast<Player>(character); // addExp()에 접근하기 위한 다운캐스팅
			system("cls");  // 인벤토리 화면 없애기
			characterPtr->addExp(exp);

			return true;
		}
	}

	std::string logMsg = "#ConsumeItem : Failed to Apply Item(";
	logMsg.append(itemName);
	logMsg.append(")");
	LOG_INFO(logMsg);

	return false;
}

bool AtkBuffItem::ApplyEffect(const std::shared_ptr<Character> character)
{
	// 포인터(매개변수) nullptr 값 방어 코드
	if (character != nullptr)
	{
		// 캐릭터 레벨이 사용 조건을 만족하는지 확인
		if (character->getLevel() >= minLevel)
		{
			// 로그 출력
			std::string logMsg = "#ConsumeItem : Success to Apply Item(";
			logMsg.append(itemName);
			logMsg.append(") to ");
			logMsg.append(character->getName());
			LOG_INFO(logMsg);

			// 증가된 공격력 계산
			size_t newAtk = character->getATK() + buffAtk;

			// 증가된 공격력 적용
			character->setATK(newAtk);

			return true;
		}
	}

	std::string logMsg = "#ConsumeItem : Failed to Apply Item(";
	logMsg.append(itemName);
	logMsg.append(")");
	LOG_INFO(logMsg);

	return false;
}

bool AtkBuffItem::RevertEffect(const std::shared_ptr<Character> character)
{
	// 포인터(매개변수) nullptr 값 방어 코드
	if (character != nullptr)
	{
		// 캐릭터 레벨이 사용 조건을 만족하는지 확인
		if (character->getLevel() >= minLevel)
		{
			// 로그 출력
			std::string logMsg = "#ConsumeItem : Success to Revert Item(";
			logMsg.append(itemName);
			logMsg.append(") from ");
			logMsg.append(character->getName());
			LOG_INFO(logMsg);

			// 감소된 공격력 계산
			size_t newAtk = character->getATK() - buffAtk;

			// 감소된 공격력 적용
			character->setATK(newAtk);

			return true;
		}
	}

	std::string logMsg = "#ConsumeItem : Failed to Revert Item(";
	logMsg.append(itemName);
	logMsg.append(")");
	LOG_INFO(logMsg);

	return false;
}

bool HPBuffItem::ApplyEffect(const std::shared_ptr<Character> character)
{
	// 포인터(매개변수) nullptr 값 방어 코드
	if (character != nullptr)
	{
		// 캐릭터 레벨이 사용 조건을 만족하는지 확인
		if (character->getLevel() >= minLevel)
		{
			// 로그 출력
			std::string logMsg = "#ConsumeItem : Success to Apply Item(";
			logMsg.append(itemName);
			logMsg.append(") to ");
			logMsg.append(character->getName());
			LOG_INFO(logMsg);

			// 증가된 최대 HP 계산
			size_t newMaxHP = character->getMaxHP() + buffHP;

			// 증가된 최대 HP 적용
			character->setMaxHP(newMaxHP);

			return true;
		}
	}

	std::string logMsg = "#ConsumeItem : Failed to Apply Item(";
	logMsg.append(itemName);
	logMsg.append(")");
	LOG_INFO(logMsg);

	return false;
}

bool HPBuffItem::RevertEffect(const std::shared_ptr<Character> character)
{
	// 포인터(매개변수) nullptr 값 방어 코드
	if (character != nullptr)
	{
		// 캐릭터 레벨이 사용 조건을 만족하는지 확인
		if (character->getLevel() >= minLevel)
		{
			// 로그 출력
			std::string logMsg = "#ConsumeItem : Success to Revert Item(";
			logMsg.append(itemName);
			logMsg.append(") from ");
			logMsg.append(character->getName());
			LOG_INFO(logMsg);

			// 감소된 최대 HP 계산
			size_t newMaxHP = character->getMaxHP() - buffHP;

			// 감소된 최대 HP 적용
			character->setMaxHP(newMaxHP);

			return true;
		}
	}

	std::string logMsg = "#ConsumeItem : Failed to Revert Item(";
	logMsg.append(itemName);
	logMsg.append(")");
	LOG_INFO(logMsg);

	return false;
}
