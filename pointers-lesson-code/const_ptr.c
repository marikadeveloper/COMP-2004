#include <stdio.h>

// You can uncomment the commented-out lines one at a time
// to check that running those lines of code gives an error

int main()
{
    int x1 = 15, y1 = 17;
    int *const myPtr1 = &x1; // int pointer to a fixed address
    printf("myPtr1 addr, value = %p, %d\n", myPtr1, *myPtr1);
    
    //myPtr1 = &y1; // myPtr1's address cannot be changed
    *myPtr1 = y1;   // myPtr1's value can be changed
    printf("myPtr1 addr, value = %p, %d\n", myPtr1, *myPtr1);

    int x2 = 25, y2 = 27;
    const int *myPtr2 = &x2; // pointer to a constant integer
    printf("myPtr2 addr, value = %p, %d\n", myPtr2, *myPtr2);

    myPtr2 = &y2; // myPtr2's address can be changed
    //*myPtr2 = y2; // myPrt2's value cannot be changed
    printf("myPtr2 addr, value = %p, %d\n", myPtr2, *myPtr2);
    
    int x3 = 35, y3 = 37;
    const int *const myPtr3 = &x3; 

    //myPtr3 = &y3; // myPtr2's address cannot be changed
    //*myPtr3 = y3; // myPrt2's value cannot be changed
    printf("myPtr3 addr, value = %p, %d\n", myPtr3, *myPtr3);
}