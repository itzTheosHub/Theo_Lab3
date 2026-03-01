#ifndef HEAP_H
#define HEAP_H
using namespace std;

class Heap
{
    private:
        int *data;
        int size;
        int cap;

        void resize(int n);
        void bubbleUp(int idx);
        int left(int idx);
        int right(int idx);
        void buildHeapTD(const int arr[], int n);
        void buildHeapBU(const int arr[], int n);
        void bubbleDown(int idx);
        int parent(int idx);

    public:
        Heap();
        Heap(const int arr[], int n);
        void insert(int val);
        void display();
        void swapAt(int i, int j);
        int extract();
        void heapSort();

};

#endif