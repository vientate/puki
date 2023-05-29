#pragma once
#include <string>
#include <vector>

using namespace std;

class Menu
{
public:
	Menu(string Title, bool IsProtected) : fullname(Title), isProtected(IsProtected) {}
	string getTitle();
	virtual void run() = 0;
	bool getProtected() { return isProtected; }
	bool getAccessGranted() { return isAccessGranted; }
	virtual ~Menu() {}
protected:
	string fullname;
	string password = "777";
	bool isProtected;
	bool isAccessGranted = false;
	bool checkPassword();
};

