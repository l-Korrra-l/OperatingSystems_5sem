#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <iomanip>

int main()
{
    DWORD pid = GetCurrentProcessId();
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 peProcessEntry;
    peProcessEntry.dwSize = sizeof(PROCESSENTRY32);

    std::wcout << L"Current pid: " << pid << "\n";
    std::wcout << L"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    try
    {
        if (!Process32First(snap, &peProcessEntry)) throw L"Process32First";
        do
        {
            std::wcout << L"Name: " << peProcessEntry.szExeFile << "\n"
                << L"Pid: " << peProcessEntry.th32ProcessID << "\n"
                << L"Ppid: " << peProcessEntry.th32ParentProcessID;
            if (peProcessEntry.th32ProcessID == pid) std::wcout << "---> current process";
            std::wcout << L"\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        } while (Process32Next(snap, &peProcessEntry));
    }
    catch (char* msg) {
        std::wcout << L"ERROR: " << msg << "\n";
    }
    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
