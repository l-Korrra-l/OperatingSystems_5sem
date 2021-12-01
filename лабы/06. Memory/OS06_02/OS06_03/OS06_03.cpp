// OS06_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

#define KB (1024)
#define PG (4 * KB)

int main()
{
    int pages = 256;
    int countItems = pages * PG / sizeof(int);

    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);
    int* arr = (int*)xmemaddr;

    for (int i = 0; i < countItems; i++) {
        arr[i] = i;
    }

    //М (204dec) D1 hex
    //Е (229dec) E5 hex
    //Р (240dec) F0 hex
    //Page: D1 = 204dec, offset = E5F = 3679
    //adress 204 * PG + 3679 = 839 263 (CCE5F)
    //00400000 + CCE5F = 004CCE5F
    system("pause");

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
