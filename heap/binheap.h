typedef int ElementType;

#ifndef _BinHeap_H
#define _BinHeap_H

#define MinPQSize (10)
#define MinData (-32767)

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize( int MaxElements );
void Destroy( PriorityQueue H );
void MakeEmpty( PriorityQueue H );
void Insert( ElementType X, PriorityQueue H );
ElementType DeleteMin( PriorityQueue H );
ElementType FindMin( PriorityQueue H );
int IsEmpty( PriorityQueue H );
int IsFull( PriorityQueue H );
void PrintHeap ( PriorityQueue H);

#endif

