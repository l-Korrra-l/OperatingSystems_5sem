// OS06_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
using namespace std;

void HeapInfo(HANDLE pheap)
{
    PROCESS_HEAP_ENTRY phe;
    phe.lpData = NULL;
    while (HeapWalk(pheap, &phe))
    {
        cout << "-- address = " << hex << phe.lpData
            << ", size = " << dec << phe.cbData
            << ((phe.wFlags & PROCESS_HEAP_REGION) ? " R" : "") // начало непрерывной области
            << ((phe.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE) ? " U" : "") // нераспределенная область
            << ((phe.wFlags & PROCESS_HEAP_ENTRY_BUSY) ? " B" : "") // распределенная область
            << "\n";
    }
    std::cout << "-----------------------------------\n\n";
}

int main()
{
    HANDLE pheap = GetProcessHeap();
    HANDLE heap = HeapCreate(HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 4096, 0);

    HeapInfo(heap);

    int size = 300000;
    int* m = new int[size];
    //cout << "adress = " << hex << m << ", size = " << dec << size << " \n\n";

    int* mm = (int*)HeapAlloc(heap, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 300000 * sizeof(int));
    cout << "-adress = " << hex << mm << ", size = " << dec << 300000 << " \n\n";

    HeapInfo(heap);
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
