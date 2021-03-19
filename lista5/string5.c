#include <stdio.h>
#include <string.h>

int ASCII_O_NUMBER = 111;
int main()
{

  int hash[10001];
  memset(hash, 0, sizeof(int) * 10001);

  char c;
  while (scanf("%c", &c) != EOF)
  {
    hash[c]++;
  }

  printf("%d", hash[ASCII_O_NUMBER]);

  return 0;
}