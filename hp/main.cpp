#include <iostream>
#include <Windows.h>
#include "DoctorBase.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DoctorBase* bb = new DoctorBase();
    bb->run();
    return 0;
}
