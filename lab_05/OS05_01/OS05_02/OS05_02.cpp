// OS05_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <process.h>
#include "OS05_02.h"

DWORD SwPriority(int i) {
    switch (i) {
    case 1: return IDLE_PRIORITY_CLASS; 
    case 2: return BELOW_NORMAL_PRIORITY_CLASS; 
    case 3: return NORMAL_PRIORITY_CLASS;
    case 4: return ABOVE_NORMAL_PRIORITY_CLASS;
    case 5: return HIGH_PRIORITY_CLASS;
    case 6: return REALTIME_PRIORITY_CLASS;
    default: throw "No such priority class";
    }
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << "arg" << i << ": " << argv[i] << "\n";
    }

    LPCWSTR an = L"..\\Debug\\OS05_02x.exe";
    STARTUPINFO si;
    PROCESS_INFORMATION pi, pi1;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    unsigned long long mask;
    HANDLE hp = GetCurrentProcess();

    try {
        DWORD pa = NULL, sa = NULL, icpu = -1;
        if (!GetProcessAffinityMask(hp, &pa, &sa)) throw "Process Affinity Mask";
        std::cout << " Process Affinity Mask: " << std::showbase << std::hex << pa << "\n";
        std::cout << " System Affinity Mask: " << std::showbase << std::hex << sa << "\n";
        std::cout << std::dec << std::noshowbase << "\n\n";

        if (argv[1] != NULL) {
            sscanf_s(argv[1], "%d", &mask);
            if (!SetProcessAffinityMask(hp, mask)) throw "SetProcessAffinityMask";
        }

        if (!GetProcessAffinityMask(hp, &pa, &sa)) throw "Process Affinity Mask";
        std::cout << " Process Affinity Mask: " << std::showbase << std::hex << pa << "\n";
        std::cout << " System Affinity Mask: " << std::showbase << std::hex << sa << "\n";
        std::cout << std::dec << std::noshowbase;

        DWORD i = SwPriority(1);
        if (!CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | SwPriority(atoi(argv[2])), NULL, NULL, &si, &pi))  throw "---Proc 1 wasn't created";
        if (!CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | SwPriority(atoi(argv[3])), NULL, NULL, &si, &pi1))  throw "---Proc 2 wasn't created";
    }
    catch (const std::exception& a)
    {
        std::cout << "Error: " << a.what() << "\n";
    }
    catch (const char* msg)
    {
        std::cout << "Error: " << msg ;
    }
}

