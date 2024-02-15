#include <stdio.h>
#include "list.c"

void
PrintList( const List L )
{
    Position P = Header( L );

    if( IsEmpty( L ) )
        printf( "Empty list\n" );
    else
    {
        do
        {
            P = Advance( P );
            printf( "%d ", Retrieve( P ) );
        } while( !IsLast( P, L ) );
        printf( "\n" );
    }
}

int main( )
{
    List L;
    Position P;
    int i;

    L = MakeEmpty( NULL );
    P = Header( L );
    PrintList( L );

    // insert numbers from 0 to 9 into the list
    for( i = 0; i < 10; i++ )
    {
        Insert( i, L, P );
        PrintList( L );
        P = Advance( P );
    }

    // delete even numbers from the list
    for( i = 0; i < 10; i+= 2 )
        Delete( i, L );

    for( i = 0; i < 10; i++ )
        // if i is even, then Find should return NULL because we deleted all even numbers
        if( ( i % 2 == 0 ) == ( Find( i, L ) != NULL ) )
            printf( "Find fails\n" );

    printf( "Finished deletions\n" );

    PrintList( L );

    DeleteList( L );

    return 0;
}
