#include <iostream>
#include "Heap.h"
using namespace std;

int main()
{
    Heap *myHeap = new Heap();

    myHeap->insert(10);
    myHeap->insert(20);
    myHeap->insert(15);
    myHeap->insert(22);
    myHeap->display();
    myHeap->extract();
    myHeap->display();
    myHeap->extract();
    myHeap->display();
  

    int A[] = {1,2,3,4,5};
    Heap* h2 = new Heap(A, 4);
    std::cout << "\nNew Heap:\n";
    h2->display();
    h2->insert(100);
    h2->insert(101);
    h2->display();
    h2->extract();
    h2->display();

    h2->heapSort();

    delete myHeap;
    delete h2;


    return 0;
}