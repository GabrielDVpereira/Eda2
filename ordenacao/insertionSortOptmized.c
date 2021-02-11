#include <stdio.h>
#include "helpers.h"
/*PROBLEMA*/
void printArray(item *array, item length)
{
  for (item i = 0; i < length; i++)
  {
    printf("%d ", *(array + i));
  }
}

void insertionSort(item *array, item start, item end)
{

  for (int i = end; i > start; i--)
  {
    cmpExch(*(array + i - 1), *(array + i))
  }

  for (int i = start + 2; i <= end; i++)
  {
    int j = i;
    item tmp = *(array + j);

    while (less(tmp, *(array j - 1)))
    {
    }
  }
}

int main()
{
  item array[6] = {5, 6, 34, 94, 4, 1};
  insertionSort(array, 0, 6);

  return 0;
}