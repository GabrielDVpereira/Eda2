#include <stdio.h>

int main()
{

  int val;
  int n;
  int total = 0;

  scanf("%d", &n);

  while (n > 0 && scanf("%d", &val) == 1)
  {
    total += val;
    n--;
  }

  printf("%d\n", total);
  return 0;
}