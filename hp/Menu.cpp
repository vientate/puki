#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

string Menu::getTitle() {
	return fullname;
}

bool Menu::checkPassword() {
	system("cls");
	string nativepassword;
	cout << "��� ��������� ������� ������� ������: ";
	cin >> nativepassword;
	if (nativepassword != password) {
		cout << "������ ��������. ������ ������������ ������, ������� ����� ������� ��� �����������..";
		getchar();
		getchar();
	}
	isAccessGranted = (nativepassword == password);
	return isAccessGranted;
}