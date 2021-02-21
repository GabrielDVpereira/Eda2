#include <stdio.h>

int main()
{
  int val;
  int count = 0;

  while (scanf("%d", &val) == 1)
  {
    count++;
  }

  printf("%d\n", count);

  return 0;
}