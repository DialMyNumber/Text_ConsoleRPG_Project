#pragma once

#include <iostream>
#include "ItemBase.h"
#include "Character.h"

class EquipItem : public ItemBase
{
private:
	int additionalAttack = 0;
	int additionalDefense = 0;

public:
	EquipItem(const std::string& name, int atk, int def)
	{
		itemType = EItemType::Equip;
	}

	void Equip(Character* target)
	{
		std::cout << "아이템(" << itemName << ")을 <장착>" << std::endl;

		if (!target)
		{
			return;
		}

		// 장착여부 판단 코드?

		target->setATK(target->getATK() + additionalAttack);
		target->setMaxHP(target->getMaxHP() + additionalDefense);
	}

	void UnEquip(Character* target)
	{
		std::cout << "아이템(" << itemName << ")을 <장착 해제>" << std::endl;

		if (!target)
		{
			return;
		}

		// 장착여부 판단 코드?

		target->setATK(target->getATK() - additionalAttack);
		target->setMaxHP(target->getMaxHP() - additionalDefense);
	}
};