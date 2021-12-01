#include <Windows.h>
#include <iostream>
#include <ctime>

int start;

int main() {
    start = clock();

    DWORD pid = GetCurrentProcessId();
    HANDLE hm = OpenMutex(SYNCHRONIZE, FALSE, L"Mutex");

    hm == NULL ? std::cout << "OS07_03B: Open Error Mutex\n" : std::cout << "OS07_03B: Open Mutex\n";

    Sleep(5000);

    for (int i = 0; i < 90; i++) {
        if (i == 30) {
            WaitForSingleObject(hm, INFINITE);
        }
        if (i == 60) {
            ReleaseMutex(hm);
        }

        std::cout << i << " \tB pid = " << pid << ", time: " << clock() - start << std::endl;
        Sleep(100);
    }
    CloseHandle(hm);

    system("pause");
}