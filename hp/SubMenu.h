#pragma once
#include "Menu.h"

using namespace std;

class SubMenu : public Menu
{
public:
	SubMenu(const string& fullname, bool isProtected) : Menu(fullname, isProtected) {}
	void add_item(Menu* menuItem) {
		items.push_back(menuItem);
	}
	void run() override;
	~SubMenu() {}
private:
	vector<Menu*> items;
};