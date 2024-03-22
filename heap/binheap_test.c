#include "binheap.h"
#include <stdio.h>

int main()
{
    PriorityQueue H = Initialize (50);

    Insert (13, H);
    Insert (14, H);    
    Insert (16, H);
    Insert (24, H);
    Insert (21, H);
    Insert (19, H);
    Insert (68, H);
    Insert (65, H);
    Insert (26, H);
    Insert (32, H);
    Insert (31, H);
   
    PrintHeap (H);
    
    printf("DeleteMin Returned: %d\n", DeleteMin(H));
    PrintHeap(H);
    
    
}