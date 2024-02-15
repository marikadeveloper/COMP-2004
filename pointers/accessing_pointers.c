#include <stdio.h>

int main()
{
    int i1 = 10, i2 = 8, i3;
    int *iptr = &i2; // iptr points to i2
    printf("Value pointed to by iptr: %d\n",*iptr); // prints 8 – value of i2
    i3 = *iptr; //i3’s value becomes 8
    *iptr = i1; //*iptr and i2’s values both become 10
    printf("Value pointed to by iptr: %d\n",*iptr); // prints 10 – value of i1
    printf("i2 is also updated: %d\n",i2); // prints 10 

}