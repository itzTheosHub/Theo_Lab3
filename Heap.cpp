#include <iostream>
#include <algorithm>
#include "Heap.h"
using namespace std;

void Heap::resize(int n)
{
    int *temp = new int[n];
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];

    }
    cap = n;
    delete[] data;
    data = temp;
}   

void Heap::bubbleUp(int idx)
{
    while( idx > 0 )
    {
        int j = parent(idx);
        if (data[j] < data[idx])
        {
            int temp = data[j];
            data[j] = data[idx];
            data[idx] = temp;
            idx = j;
        }
        else
        {
            return;
        }
    }
}

int Heap::left(int idx)
{
    return 2*idx + 1;
}

int Heap::right(int idx)
{
    return 2*idx + 2;
}

void Heap::buildHeapTD(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        insert(arr[i]);

    }
}

void Heap::buildHeapBU(const int arr[], int n)
{
    for ( int i = 0; i < n; i++)
    {
        data[i] = arr[i];
    }
    size = n;
    for (int i = n-1; i >= 0; i--)
    {
        bubbleDown(i);
    }
            
}

void Heap::bubbleDown(int idx)
{
    while(true)
    {
        int l = left(idx);
        int r = right(idx);
            
        int largest = idx;

        if (l < size && data[idx] < data[l])
        {
            largest = l;
        }

        if (r < size && data[largest] < data[r])
        {
            largest = r;
        }

        if (largest == idx)
        {
            return;
        }

        swapAt(idx, largest);
        idx = largest;
    }
}

int Heap::parent(int idx)
{
    return (idx-1)/2;
}


Heap::Heap()
{
    size = 0;
    data = new int[20];
    cap = 20;
}

Heap::Heap(const int arr[], int n)
{
    size = 0;
    cap = n;
    if ( n== 0 )
    {
        cap = 20;
    }
            
    data = new int[cap];
    //buildHeapTD(arr, n);
    buildHeapBU(arr, n);
}
    
void Heap::insert(int val)
{
if (size == cap)
{
    resize(cap*2);
}
    data[size] = val;
    size++;
    bubbleUp(size-1);
} 

void Heap::display()
{
    std::cout << " Displaying Heap: ";

    for (int i = 0; i < size; i++ )
    {
        std::cout << data[i] << " ";
    }    
        std::cout <<"\n";    
}

void Heap::swapAt(int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int Heap::extract()
{
    if (size <= 0)
    {   
        std::cout << "Heap is empty" << std::endl;
        return -1;
    }
        
    int temp = data[0];
    swapAt(0, size-1);
    size--;
    bubbleDown(0);
    return temp;
}
    
void Heap::heapSort() 
{
    std::cout << "Heap Sort\n";
    display();
    int n = size;

    for ( int i = 0; i < n; i++)
    {   
        extract(); // all elements deleted
    }
    size = n;
    display();
    std::reverse(data, data + size);
    display();
}