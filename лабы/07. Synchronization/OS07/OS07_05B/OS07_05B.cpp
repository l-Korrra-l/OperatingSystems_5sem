#include <Windows.h>
#include <iostream>
#include <ctime>

int main() {
    int start = clock();

    DWORD pid = GetCurrentProcessId();
    HANDLE he = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"Event");

    he == NULL ? std::cout << "OS07_05B: Open Error Event\n" : std::cout << "OS07_05B: Open Event\n";

    WaitForSingleObject(he, INFINITE);
    for (int i = 0; i < 90; i++) {
        std::cout << i << " OS07_05B pid = " << pid << ", time: " << clock() - start << std::endl;
        Sleep(100);
    }

    CloseHandle(he);

    system("pause");
    return 0;
}