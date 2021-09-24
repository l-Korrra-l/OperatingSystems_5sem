// OS03_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int main()
{
    LPCWSTR an = L"C:\\Users\\User\\Documents\\ОСиСП\\OperationSystems_5sem\\OS03_01\\Debug\\OS03_02.exe";
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if ( //child process
        CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)
        )
    std::cout << "---Proc created"
    std::cout << "Hello World!\n";
}
