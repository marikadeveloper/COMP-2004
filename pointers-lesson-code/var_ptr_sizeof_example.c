#include <stdio.h>

int main()
{
    int i = 7;
    int i2 = 5;
    int *iptr;
    int *iptr2;

    printf("size of i: %ld\n", sizeof (i));
    printf("size of iptr: %ld\n", sizeof (iptr));

    printf("iptr address %p\n", iptr);

    iptr = &i;    // iptr points to address of i
    iptr2 = &i2; // iptr2 points to address of i2

    printf("iptr value %p\n", iptr);
    printf("iptr address %p\n", &iptr);
    printf("iptr pointed value %d\n", *iptr);
    
    
    printf("iptr2 value %p\n", iptr2);
    printf("iptr2 address %p\n", &iptr2);
    printf("iptr2 pointed value %d\n", *iptr2);


    
    return 0;
}