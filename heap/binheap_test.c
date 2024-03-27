#include "binheap.c"
#include <stdio.h>

int main()
{
  PriorityQueue H = Initialize(50);

  Insert(10, H);
  Insert(12, H);
  Insert(1, H);
  Insert(14, H);
  Insert(6, H);
  Insert(5, H);
  Insert(8, H);
  Insert(15, H);
  Insert(3, H);
  Insert(9, H);
  Insert(7, H);
  Insert(4, H);
  Insert(11, H);
  Insert(13, H);
  Insert(2, H);

  PrintHeap(H);

  printf("DeleteMin Returned: %d\n", DeleteMin(H));
  printf("DeleteMin Returned: %d\n", DeleteMin(H));
  printf("DeleteMin Returned: %d\n", DeleteMin(H));
  PrintHeap(H);
}