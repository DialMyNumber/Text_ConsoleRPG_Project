#include "EquipItem.h"


EquipItem::EquipItem(const std::string& name, int atk, int def)
{
    itemType = EItemType::Equip;
    itemName = name;
    additionalAttack = atk;
    additionalDefense = def;
}


void EquipItem::Equip(Character* target)
{
    if (!target)
    {
        return;
    }

    std::cout << "아이템(" << itemName << ")을 장착" << std::endl;

    target->setATK(target->getATK() + additionalAttack);
    target->setMaxHP(target->getMaxHP() + additionalDefense);

}


void EquipItem::UnEquip(Character* target)
{
    if (!target)
    {
        return;
    }

    std::cout << "아이템(" << itemName << ")을 해제" << std::endl;

    target->setATK(target->getATK() - additionalAttack);
    target->setMaxHP(target->getMaxHP() - additionalDefense);
}