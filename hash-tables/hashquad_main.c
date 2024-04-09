#include <stdio.h>
#include "hashquad.h"


void PrintHashTable (HashTable H)
{
    
    printf("Hash Table Size = %d\n", H->TableSize );
    
    for (int i = 0; i < H->TableSize; i ++)
    {
        if (H->TheCells[i]. Info == Legitimate)
            printf("%d: %d (Legitimate)\n", i, H->TheCells[i].Element);
        else if (H->TheCells[i]. Info == Deleted)
            printf("%d: %d (Deleted)\n", i, H->TheCells[i].Element);
        else if (H->TheCells[i]. Info == Empty)
            printf("%d: (Empty)\n", i);

    }
}


int main()
{
    HashTable H = InitializeTable( 10 );
    printf("Printing HashTable after InitializeTable\n");
    PrintHashTable(H);
    
    Insert(89, H);
    Insert(18, H);
    Insert(49, H);
    Insert(58, H);
    Insert(69, H);
    Insert(35, H);
    
    printf("Printing HashTable after Inserts\n");
    PrintHashTable(H);    
    
    Delete(49, H);
    printf("Printing HashTable after delete 49\n");
    PrintHashTable(H);    

    printf("Location of 69 after delete 49: %d\n", Find(69, H));
    
    H = Rehash (H);
    printf("Printing HashTable after Rehash\n");
    PrintHashTable(H);   