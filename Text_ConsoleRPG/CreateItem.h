#pragma once

#include <memory>
#include "ItemBase.h"

std::shared_ptr<ItemBase> CreateItem(size_t itemID);