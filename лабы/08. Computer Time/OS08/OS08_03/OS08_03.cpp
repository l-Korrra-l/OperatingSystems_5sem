#include <ctime>
#include <iostream>
#include <Windows.h>

#define SECOND 10000000
//-----------------
int main()
{
	HANDLE htimer = CreateWaitableTimer(NULL, FALSE, L"taskTimer");
	long long it = -3 * SECOND;
	std::cout << clock() << " : main\n";
	clock_t start = clock();
	 
	if (!SetWaitableTimer(htimer, (LARGE_INTEGER*)&it, 3000, NULL, NULL, FALSE)) throw "Error SetWaitableTimer";  //(PTIMERAPCROUTINE)10

	for (int i = 0;; i++)
	{

		if ((clock() - start) / CLOCKS_PER_SEC == 15) {
			std::cout << clock() - start << " sec: " << i << std::endl;
			CancelWaitableTimer(htimer);
			break;
		}

		if (WaitForSingleObject(htimer, INFINITE) == WAIT_OBJECT_0)
		std::cout << clock() - start << " sec: " << i << std::endl;

	}
	
	system("pause");
	return 0;
}


