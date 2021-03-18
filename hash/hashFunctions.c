#include <stdio.h>

#define hash(v, m) (618033 * (unsigned)v % m)

typedef struct Item
{
  int chave;
  long e1, e2;
  long elemento;

} Item;

Item NULLITEM = {0, 0, 0, 0};

#define key(x) (x.chave)

#define less(a, b) (key(a) < key(b))

#define null(a) (key(ht[a]) == key(NULLITEM))

static int N, M;
static Item *ht;

void htInit(int max)
{
  int i;
  N = 0, M = 2 * max;
  ht = malloc(sizeof(Item) * M);

  for (int i = 0; i < M; i++)
  {
    ht[i] = NULLITEM;
  }
}

void htInsert(Item item)
{
  int v = key(item);
  int i = hash(v, M);
  while (!null(i))
    i = (i + 1) % M;

  ht[i] = item;
  N++;
}

Item htSearch(int v)
{
  int i = hash(v, M);
  while (!null(i))
  {
    if (eq(v, key(ht[i])))
    {
      return ht[i];
    }
    else
    {
      i = (i + 1) % M;
    }
  }

  return NULLITEM;
}

void htCount() { return N; };

int main()
{
  return 0;
}