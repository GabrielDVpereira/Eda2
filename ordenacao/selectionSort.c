#include <stdio.h>
#include "helpers.h"

void printArray(item *array, item length)
{
  for (item i = 0; i < length; i++)
  {
    printf("%d ", *(array + i));
  }
}

void selectionSort(item *array, item start, item end)
{
  for (item i = start; i < end; i++)
  {
    int min = i;
    for (item j = i + 1; j < end; j++)
    {
      if (less(*(array + j), *(array + min)))
      {
        min = j;
      }
    }
    exch(*(array + i), *(array + min));
  }
  printArray(array, 6);
}

int main()
{
  item array[6] = {5, 6, 34, 94, 4, 1};
  selectionSort(array, 0, 6);

  return 0;
}