#include <Windows.h>
#include <iostream>
#include <ctime>

int main() {
    int start = clock();

    DWORD pid = GetCurrentProcessId();
    HANDLE hs = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, L"Semaphore");

    hs == NULL ? std::cout << "OS07_04A: Open Error Semaphore\n" : std::cout << "OS07_04A: Open Semaphore\n";

    Sleep(5000);
    for (int i = 0; i < 90; i++) {
        if (i == 30) {
            WaitForSingleObject(hs, INFINITE);
        }
        if (i == 60) {
            ReleaseMutex(hs);
        }
        std::cout << i << " \tOS07_04B pid = " << pid << ", time: " << clock() - start << std::endl;
        Sleep(100);
    }

    CloseHandle(hs);

    system("pause");
    return 0;
}