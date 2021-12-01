// OS05_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <process.h>
#include <bitset>

int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    HANDLE h = GetCurrentProcess();
    DWORD prty = GetPriorityClass(h);
    HANDLE hp = GetCurrentThread();
    DWORD prth = GetThreadPriority(hp);

  
    std::cout << "\nPID:\t" << pid << "\nTID:\t" << tid;

    std::cout << "\nProcess priority:\t" << prty;
    switch (prty) {
    case IDLE_PRIORITY_CLASS:  std::cout << " --> IDLE_PRIORITY_CLASS"; break;
    case BELOW_NORMAL_PRIORITY_CLASS: std::cout << " --> BELOW_NORMAL_PRIORITY_CLASS"; break;
    case NORMAL_PRIORITY_CLASS: std::cout << " --> NORMAL_PRIORITY_CLASS"; break;
    case ABOVE_NORMAL_PRIORITY_CLASS: std::cout << " --> ABOVE_NORMAL_PRIORITY_CLASS"; break;
    case HIGH_PRIORITY_CLASS: std::cout << " --> HIGH_PRIORITY_CLASS"; break;
    case REALTIME_PRIORITY_CLASS: std::cout << " --> REALTIME_PRIORITY_CLASS"; break;
    default: std::cout << "error"; break;
    }

    std::cout << "\nThread priority:\t" << prth;
    switch (prth) {
    case THREAD_PRIORITY_LOWEST: std::cout << " --> THREAD_PRIORITY_LOWEST\n"; break;
    case THREAD_PRIORITY_BELOW_NORMAL: std::cout << " --> THREAD_PRIORITY_BELOW_NORMAL\n"; break;
    case THREAD_PRIORITY_NORMAL: std::cout << " --> THREAD_PRIORITY_NORMAL\n"; break;
    case THREAD_PRIORITY_ABOVE_NORMAL: std::cout << " --> THREAD_PRIORITY_ABOVE_NORMAL\n"; break;
    case THREAD_PRIORITY_HIGHEST: std::cout <<  " --> THREAD_PRIORITY_HIGHEST\n"; break;
    case THREAD_PRIORITY_IDLE: std::cout << " --> THREAD_PRIORITY_IDLE\n"; break;
    default: std::cout << "error"; break;
    }

    DWORD pa = NULL, sa = NULL, icpu = -1;
    if (!GetProcessAffinityMask(h, &pa, &sa)) throw "GetProcessAffinityMask";
    std::cout << "Process affinity mask:\t" << std::showbase << std::bitset<12>{pa} << "\n"; //Маска родства процесса отображает процессоры, на которых разрешается выполнение потоков данного процесса.
    std::cout << "System Affinity Mask: " << std::showbase << std::bitset<12>{sa} << "\n"; //Маска родства системы отображает процессоры, сконфигурированные в системе.
    icpu = SetThreadIdealProcessor(hp, MAXIMUM_PROCESSORS);
    std::cout << "Processor: " << icpu << "\n";
    SYSTEM_INFO sys_info;
    GetSystemInfo(&sys_info);
    std::cout << "Max count processors: " << sys_info.dwNumberOfProcessors << std::endl;
}

