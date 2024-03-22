#include <stdlib.h>
        
#define LeftChild( i )  ( 2 * ( i ) + 1 )

void
PercDown( ElementType A[ ], int i, int N )
{
    int Child;
    ElementType Tmp;

/* 1*/      for( Tmp = A[ i ]; LeftChild( i ) < N; i = Child )
    {
/* 2*/          Child = LeftChild( i );
/* 3*/          if( Child != N - 1 && A[ Child + 1 ] > A[ Child ] )
/* 4*/              Child++;
/* 5*/          if( Tmp < A[ Child ] )
/* 6*/              A[ i ] = A[ Child ];
        else
/* 7*/              break;
    }
/* 8*/      A[ i ] =Tmp;
}

void Heapsort( ElementType A[ ], int N )
{
    int i;

/* 1*/      for( i = N / 2; i >= 0; i-- )  /* BuildHeap */
/* 2*/          PercDown( A, i, N );
/* 3*/      for( i = N - 1; i > 0; i-- )
    {
/* 4*/          Swap( &A[ 0 ], &A[ i ] );  /* DeleteMax */
/* 5*/          PercDown( A, 0, i );
    }
}