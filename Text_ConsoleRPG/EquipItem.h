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
	EquipItem() {}
	
	EquipItem(const std::string& name, int atk, int def);

	void Equip(Character* target);

	void UnEquip(Character* target);
};