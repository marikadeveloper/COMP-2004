#include "binheap.h"
#include <stdlib.h>
#include <stdio.h>

PriorityQueue
Initialize( int MaxElements )
{
    PriorityQueue H;

/* 1*/      if( MaxElements < MinPQSize )
/* 2*/      {
               printf( "Priority queue size is too small" );
               exit(1);
            }
/* 3*/      H = malloc( sizeof( struct HeapStruct ) );
/* 4*/      if( H ==NULL )
            {
/* 5*/          printf( "Out of space!!!" );
                exit(1);
            }

    /* Allocate the array plus one extra for sentinel */
/* 6*/      H->Elements = malloc( ( MaxElements + 1 )
                            * sizeof( ElementType ) );
/* 7*/      if( H->Elements == NULL )
            {
/* 8*/          printf( "Out of space!!!" );
                exit(1);
            }

/* 9*/      H->Capacity = MaxElements;
/*10*/      H->Size = 0;
/*11*/      H->Elements[ 0 ] = MinData;

/*12*/      return H;
}


void
MakeEmpty( PriorityQueue H )
{
    H->Size = 0;
}


/* H->Element[ 0 ] is a sentinel */

#if 0
void
Insert( ElementType X, PriorityQueue H )
{
    int hole;

    if( IsFull( H ) )
    {
        printf( "Priority queue is full\n" );
        return;
    }

    for( hole = ++H->Size; H->Elements[ hole / 2 ] > X; hole /= 2 )
        H->Elements[ hole ] = H->Elements[ hole / 2 ];
    H->Elements[ hole ] = X;
}
#endif

void Insert (ElementType X, PriorityQueue H)
{
    int hole;
    
    if( IsFull( H ) )
    {
        printf( "Priority queue is full\n" );
        return;
    }
    
    H->Size += 1;
    hole = H->Size;
    
    while ( X < H->Elements [hole/2])
    {
        H->Elements [hole] = H->Elements[ hole/2 ];
        hole /= 2;
    }
    H->Elements [hole] = X;
    
}


ElementType
DeleteMin( PriorityQueue H )
{
    int i, Child;
    ElementType MinElement, LastElement;

/* 1*/      if( IsEmpty( H ) )
    {
/* 2*/          printf( "Priority queue is empty\n" );
/* 3*/          return H->Elements[ 0 ];
    }
/* 4*/      MinElement = H->Elements[ 1 ];
/* 5*/      LastElement = H->Elements[ H->Size-- ];

/* 6*/      for( i = 1; i * 2 <= H->Size; i = Child )
    {
        /* Find smaller child */
/* 7*/          Child = i * 2;
/* 8*/          if( Child != H->Size && H->Elements[ Child + 1 ]
/* 9*/                                < H->Elements[ Child ] )
/*10*/              Child++;

        /* Percolate one level */
/*11*/          if( LastElement > H->Elements[ Child ] )
/*12*/              H->Elements[ i ] = H->Elements[ Child ];
        else
/*13*/              break;
    }
/*14*/      H->Elements[ i ] = LastElement;
/*15*/      return MinElement;
}


ElementType
FindMin( PriorityQueue H )
{
    if( !IsEmpty( H ) )
        return H->Elements[ 1 ];
    printf( "Priority Queue is Empty\n" );
    return H->Elements[ 0 ];
}

int
IsEmpty( PriorityQueue H )
{
    return H->Size == 0;
}

int
IsFull( PriorityQueue H )
{
    return H->Size == H->Capacity;
}

void
Destroy( PriorityQueue H )
{
    free( H->Elements );
    free( H );
}

void PrintHeap ( PriorityQueue H)
{
    if ( !IsEmpty (H))
    {
        printf("Heap Elements: ");
        for (int i = 1; i <= H->Size; i++)
            printf("%d ", H->Elements[i]);
        printf("\n");
    }
    else
        printf ("Empty Heap: Nothing to print!");
}


