#include <stdio.h>
#include <stdlib.h>

typedef struct tList
{
  int aValues[255];
  int nLastPos;

} oList;


void SetLastPos (oList * pList, int value)
{
  pList->nLastPos += value;
}

void InsertFim (oList * pList, int nvalue)
{
  SetLastPos (pList, 1);
  pList->aValues[pList->nLastPos] = nvalue;
}

void InsetInto (oList * pList, int pos, int value)
{
  int lSetArray = 1;
  //Valida se a possiC'C#o C) valida
  if (pos > pList->nLastPos || pos < 0)
    lSetArray = 0;

  if (lSetArray == 1)
    {
      printf ("Inserindo Meio \n");
      //Incrementa +1 pos no array
      SetLastPos (pList, 1);
      //Realoca o array atC) a posiC'C#o desejada
      for (int i = pList->nLastPos; i > pos; i--)
	pList->aValues[i] = pList->aValues[i - 1];
      //seta o novo valor para posiC'C#o desejada
      pList->aValues[pos] = value;
    }
  else
    {
      printf ("Inserindo Fim \n");
      InsertFim (&pList, value);
    }
}

void Remove (oList * pList, int pos)
{
  int lSetArray = 1;
  //Valida se a possiC'C#o C) valida
  if (pos > pList->nLastPos || pos < 0)
    lSetArray = 0;

  if (lSetArray == 1)
    {
      for (int i = 0; i <= pList->nLastPos; i++)
	{
	  if (i < pos)
	    continue;

	  pList->aValues[i] = pList->aValues[i + 1];
	}
      SetLastPos (&pList, -1);
    }
  else
    {
      printf ("Imposivel remover na pos %d \n", pos);
    }
}

void PrintList (oList pList)
{
  for (int i = 0; i <= pList.nLastPos; i++)
    {
      printf ("Pos: %d Valor: %d \n", i, pList.aValues[i]);
    }
}


int
main ()
{
  oList pList;
  pList.nLastPos = -1;

  printf ("Tamanho inicial: %d \n", pList.nLastPos);
  InsertFim (&pList, 10);
  InsertFim (&pList, 20);
  InsertFim (&pList, 40);
  PrintList (pList);
  printf ("Tamanho Atual: %d \n", pList.nLastPos);
  InsetInto (&pList, 2, 30);
  InsetInto (&pList, 5, 60);
  InsetInto (&pList, 4, 50);
  PrintList (pList);

  printf ("Tamanho Atual: %d \n", pList.nLastPos);
  Remove (&pList, 3);
  PrintList (pList);
  //system("pause");
  return 0;
}
