#include <stdio.h>
#include <string.h>

int main()
{

  int biggest = 0;
  char c[1000];
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {

    scanf("%s", c);
    if (strlen(c) > biggest)
    {
      biggest = strlen(c);
    }
  }

  printf("%d", biggest);

  return 0;
}