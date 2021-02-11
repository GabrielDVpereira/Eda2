#include <stdio.h>
#include "helpers.h"

void printArray(item *array, item length)
{
  for (item i = 0; i < length; i++)
  {
    printf("%d ", *(array + i));
  }
}

void bubleSort(item *array, item start, item end)
{
  for (item i = start; i < end; i++)
  {
    for (item j = start + 1; j < end; j++)
    {
      cmpExch(*(array + j - 1), *(array + j));
    }
  }
  printArray(array, 6);
}

int main()
{
  item array[6] = {5, 6, 34, 94, 4, 1};
  bubleSort(array, 0, 6);

  return 0;
}