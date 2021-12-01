#include <Windows.h>
#include <iostream>
#include <ctime>

int main() {
    int start = clock();
    DWORD pid = GetCurrentProcessId();
    HANDLE hs = CreateSemaphore(NULL, 2, 3, L"Semaphore");

    LPCWSTR an1 = L"..\\Debug\\OS07_04A.exe";
    LPCWSTR an2 = L"..\\Debug\\OS07_04B.exe";

    STARTUPINFO si1; STARTUPINFO si2;

    PROCESS_INFORMATION pi1; 
    PROCESS_INFORMATION pi2;

    ZeroMemory(&si1, sizeof(STARTUPINFO)); 
    ZeroMemory(&si2, sizeof(STARTUPINFO));

    si1.cb = sizeof(STARTUPINFO); 
    si2.cb = sizeof(STARTUPINFO);

    if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1)) {
        std::cout << "--Process OS07_04A created\n";
    }
    else {
        std::cout << "--Process OS07_04A not created\n";
    }

    if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2)) {
        std::cout << "--Process OS07_04B created\n";
    }
    else {
        std::cout << "--Process OS07_04B not created\n";
    }

    Sleep(5000);
    LONG prevcount = 0;
    for (int i = 0; i < 90; i++) {
        if (i == 30) {
            WaitForSingleObject(hs, INFINITE);
        }
        if (i == 60) {
            ReleaseSemaphore(hs, 1, &prevcount);
        }

        std::cout << i << " \tOS07_04 pid = " << pid << ", time: " << clock() - start << std::endl;
        Sleep(100);
    }

    WaitForSingleObject(pi1.hProcess, INFINITE);  
    WaitForSingleObject(pi2.hProcess, INFINITE);

    CloseHandle(hs);
    CloseHandle(pi1.hProcess);  
    CloseHandle(pi2.hProcess);

    system("pause");
    return 0;
}