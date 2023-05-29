#pragma once
#include "Menu.h"
#include <functional>

using namespace std;

class MenuItem : public Menu
{
public:
	MenuItem(const string& fullname, bool isProtected, function<void()> action) : Menu(fullname, isProtected), action(action) {}
	void run() override;
	~MenuItem() {}
private:
	function<void()> action;
};

