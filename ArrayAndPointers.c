#include <stdio.h>

void main()
{
  int a[5];
  a[3] = 95;
  a[2] = 98;
  a[1] = 32;
  for(int i = 0; i < 5; i++)
  {
    printf("Address of a[%d] is %p\t", i, (a+i));  //to access the memory address of array elements
    printf("Value of a[%d] is %d\n", i, *(a+i));
  }
}
