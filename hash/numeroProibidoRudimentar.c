#include <stdio.h>
// Sem tratamento de colusões
int v[262139];
int hashN(int n)
{
  return n % 262139;
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int t;
    scanf("%d", &t);

    v[hashN(t)] = t;
  }

  int c;
  while (scanf("%d", &c) == 1)
  {
    int t = hashN(c);
    if (v[t] == c)
    {
      printf("proibido \n");
    }
    else if (v[t] == 0)
    {
      printf("Não proibido\n");
    }
    else if (v[t] != c)
    {
      printf("Colisão!");
    }
  }
}