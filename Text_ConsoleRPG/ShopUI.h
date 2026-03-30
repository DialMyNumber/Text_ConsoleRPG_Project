#pragma once
#include <memory>
#include <vector>
#include <map>
#include <deque>
#include <string>

class Shop;
class Money;
class ItemBase;
class Player;

class ShopUI
{
public:
	bool updateShopTick(Shop&, std::shared_ptr<Player>);
	void setPlayer(std::shared_ptr <Player> player);

private:
	void ResetUIState();
	void showMenu(int row);
	void showItemLists(Shop& shop, int startRow);

	template<typename MapType>
	std::shared_ptr<ItemBase> selectItem(const MapType& items, int startRow);

	void gotoxy(int x, int y);
	void clearLine(int row);
	void pushLog(const std::string& msg);
	void renderLog(int startRow);

	std::deque<std::string> s_logs;
	static constexpr int MAX_LOGS = 5;
	std::shared_ptr<Player> myPlayer = nullptr;
};