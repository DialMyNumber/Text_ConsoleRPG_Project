#include "EquipItem.h"

std::shared_ptr<ItemBase> CreateItem(size_t itemID)
{
	auto item = std::make_shared<EquipItem>();

	switch (itemID)
	{
	case 1:
		item->itemName = "Feather Helmet";
		item->buyCost = 100;
		item->sellCost = 20;
		break;

	case 2:
		item->itemName = "Iron Helmet";
		item->buyCost = 500;
		item->sellCost = 100;
		break;

	default:
		return nullptr;
	}

	return item;
}

