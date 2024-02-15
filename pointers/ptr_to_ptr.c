#include <stdio.h>

int main()
{
     int i=10, *iPtr;
     int **iPtr2;
     
     iPtr = &i;
     iPtr2 = &iPtr;
     
     printf("iPtr2's address = %p\n", iPtr2);
     printf("iPtr2's value = %p\n", *iPtr2);
     printf("iPtr's value (accessed via iPtr2)= %d\n", **iPtr2);
}