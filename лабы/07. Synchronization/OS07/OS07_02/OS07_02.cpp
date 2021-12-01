#include <iostream>
#include <ctime>
#include <Windows.h>


DWORD pid = NULL;
DWORD WINAPI A();
DWORD WINAPI B();

CRITICAL_SECTION cs;

int main() {
	pid = GetCurrentProcessId();

	InitializeCriticalSection(&cs);

	DWORD tid = GetCurrentThreadId();
	DWORD AId = NULL, BId = NULL;
	HANDLE hA = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)A, NULL, 0, &AId);
	HANDLE hB = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)B, NULL, 0, &BId);

	int start = clock();
	for (int i = 0; i < 90; i++) {
		if (i == 30) {
			EnterCriticalSection(&cs);
		}
		if (i == 60) {
			LeaveCriticalSection(&cs);
		}

		std::cout << i << " pid = " << pid << ", \tmain tid = " << tid << ", \ttime: " << clock() - start << std::endl;
		Sleep(100);
	}

	WaitForSingleObject(hA, INFINITY);	
	WaitForSingleObject(hB, INFINITY);
	DeleteCriticalSection(&cs);

	CloseHandle(hA); 
	CloseHandle(hB);

	system("pause");
	return 0;
}

DWORD WINAPI A() {
	DWORD tid = GetCurrentThreadId();

	int start = clock();
	for (int i = 0; i < 90; i++) {
		if (i == 30) {
			EnterCriticalSection(&cs);
		}
		if (i == 60) {
			LeaveCriticalSection(&cs);
		}

		std::cout << i << " pid = " << pid << ", \tA tid = " << tid << ", \ttime: " << clock() - start << std::endl;
		Sleep(100);
	}

	return 0;
}

DWORD WINAPI B() {
	DWORD tid = GetCurrentThreadId();

	int start = clock();
	for (int i = 0; i < 90; i++) {
		if (i == 30) {
			EnterCriticalSection(&cs);
		}
		if (i == 60) {
			LeaveCriticalSection(&cs);
		}

		std::cout << i << " pid = " << pid << ", \tB tid = " << tid << ", \ttime: " << clock() - start << std::endl;
		Sleep(100);
	}

	return 0;
}