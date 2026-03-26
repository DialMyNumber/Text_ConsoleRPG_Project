#include "ItemBase.h"
#include <iostream>	// std::cout, std::endl

void ItemBase::UseItem()
{
	std::cout << "아이템(" << itemName << ")을 사용" << std::endl;
}
