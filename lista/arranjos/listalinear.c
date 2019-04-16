#include <stdio.h>
#include <stdlib.h>

typedef struct tList
{
  int aValues[255];
  int nLastPos;
  int nInitPos;

} oList;


void InsertFim (oList *pList, int nvalue)
{
    printf ("Inserindo %d no Fim \n", nvalue);
    pList->nLastPos = pList->nLastPos + 1;
    pList->aValues[pList->nLastPos] = nvalue;
}


void InsetInto (oList *pList, int pos, int value)
{
    int lSetArray = 1;
    //Valida se a possiC'C#o C) valida
    if (pos > pList->nLastPos || pos < 0)
        lSetArray = 0;

    if (lSetArray == 1)
    {
        printf ("Inserindo %d no  Meio \n", value);
        //Incrementa +1 pos no array
        pList->nLastPos = pList->nLastPos + 1;
        //Realoca o array atC) a posiC'C#o desejada
        for (int i = pList->nLastPos; i > pos; i--)
            pList->aValues[i] = pList->aValues[i - 1];

        pList->aValues[pos] = value;
    }
    else
    {
        InsertFim (pList, value);
    }
}

void Remove (oList *pList, int pos)
{
  int lSetArray = 1;

  if (pos > pList->nLastPos || pos <= 0)
    lSetArray = 0;

  if (lSetArray == 1)
  {
      printf ("Removendo pos %d \n", pos);

      for (int i = 1; i <= pList->nLastPos; i++)
      {
          if (i < pos)
            continue;
          pList->aValues[i] = pList->aValues[i + 1];
      }
      pList->nLastPos = pList->nLastPos - 1;
  }
  else
  {
      printf ("Imposivel remover na pos %d \n", pos);
  }
}

void PrintList (oList *pList)
{
    for (int i = 1; i <= pList->nLastPos; i++)
      printf ("Pos: %d Valor: %d \n", i, pList->aValues[i]);
}

int main ()
{
  oList pList;
  pList.nLastPos = 0;

  printf ("Tamanho Atual: %d \n", pList.nLastPos);
  InsertFim (&pList, 10);
  InsertFim (&pList, 20);
  InsertFim (&pList, 40);
  PrintList (&pList);
  InsetInto (&pList, 2, 30);
  InsetInto (&pList, 5, 60);
  InsetInto (&pList, 4, 50);
  PrintList (&pList);

  Remove (&pList, 0);
  Remove (&pList, 1);
  Remove (&pList, 5);
  PrintList (&pList);
  //system("pause");
  return 0;
}
