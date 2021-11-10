// OS04_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <iostream>

DWORD WINAPI OS04_03_T1() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 50; ++i) {
        Sleep(1000);
        std::cout << "\nPID = " << pid << ", TID = " << tid << "\tT1";
    }

    return 0;
}

DWORD WINAPI OS04_03_T2() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 125; ++i) {
        Sleep(1000);
        std::cout << "\nPID = " << pid << ", TID = " << tid << "\tT2";
    }

    return 0;
}

int main() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    DWORD childId_T1, childId_T2 = NULL;

    HANDLE hChild1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_03_T1, NULL, 0, &childId_T1);
    Sleep(10);
    HANDLE hChild2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_03_T2, NULL, 0, &childId_T2);

    for (int i = 0; i < 100; ++i) {
        Sleep(1000);
        std::cout << "\nPID = " << pid << ", PT TID = " << tid <<"\t"<<i;
        if (i == 20) {
            SuspendThread(hChild1);
            std::cout << "\n -=-=-=-=-=-=-=-=-=-=-=-\n|  Suspend  OS04_03_T1  |\n -=-=-=-=-=-=-=-=-=-=-=-";
        }
        else if (i == 60) {
            ResumeThread(hChild1);
            std::cout << "\n -=-=-=-=-=-=-=-=-=-=-=-\n|  Resume  OS04_03_T1  |\n -=-=-=-=-=-=-=-=-=-=-=-";
        }
        else if (i == 40) {
            SuspendThread(hChild2);
            std::cout << "\n -=-=-=-=-=-=-=-=-=-=-=-\n|  Suspend  OS04_03_T2  |\n -=-=-=-=-=-=-=-=-=-=-=-";
        }
    }

    ResumeThread(hChild1);
    std::cout << "\n -=-=-=-=-=-=-=-=-=-=-=-\n|  Resume  OS04_03_T2  |\n -=-=-=-=-=-=-=-=-=-=-=-";

    WaitForSingleObject(hChild1, INFINITE);
    WaitForSingleObject(hChild2, INFINITE);

    CloseHandle(hChild1);
    CloseHandle(hChild2);

    return 0;
}