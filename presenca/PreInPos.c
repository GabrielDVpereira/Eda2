#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux
{
  TIPOCHAVE chave;
  struct aux *esq, *dir;
} NO;

NO *inicializa()
{
  return NULL;
}

NO *adiciona(NO *raiz, NO *no)
{
  if (raiz == NULL)
    return no;
  if (no->chave < raiz->chave)
  {
    raiz->esq = adiciona(raiz->esq, no);
  }
  else
  {
    raiz->dir = adiciona(raiz->dir, no);
  }

  return raiz;
}

NO *criaNovoNO(TIPOCHAVE ch)
{
  NO *novoNo = (NO *)malloc(sizeof(NO));
  novoNo->chave = ch;
  novoNo->esq = NULL;
  novoNo->dir = NULL;
  return novoNo;
}

int numeroNos(NO *raiz)
{
  if (!raiz)
    return 0;
  return numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir);
}

void printPostorder(NO *no)
{
  if (no == NULL)
    return;

  printPostorder(no->esq);
  printPostorder(no->dir);
  printf("%d ", no->chave);
}

/* Given a binary tree, print its nos in inorder*/
void printInorder(NO *no)
{
  if (no == NULL)
    return;

  printInorder(no->esq);
  printf("%d ", no->chave);
  printInorder(no->dir);
}

/* Given a binary tree, print its nos in preorder*/
void printPreorder(NO *no)
{
  if (no == NULL)
    return;

  printf("%d ", no->chave);
  printPreorder(no->esq);
  printPreorder(no->dir);
}

void exibirArvore(NO *raiz)
{
  if (raiz != NULL)
  {
    printf("%i", raiz->chave);
    printf("(");
    exibirArvore(raiz->esq);
    exibirArvore(raiz->dir);
    printf(")");
  }
}

int main()
{

  int n;
  NO *r = inicializa();

  while (scanf("%d", &n) == 1)
  {
    NO *no = criaNovoNO(n);
    r = adiciona(r, no);
  }
  printPreorder(r);
  printf(".\n");
  printInorder(r);
  printf(".\n");
  printPostorder(r);
  printf(".\n");
}