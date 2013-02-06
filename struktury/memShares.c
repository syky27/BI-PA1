/* Vytvořit funkci int menShares(TShare *list),
 * která zjistí kolik bajtů paměti zabírá zadaný seznam akcionářů
 * POZOR JDE O SPOJOVÝ SEZNAM
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>


typedef struct TShare
{
   struct TShare *m_Next;  /* další člen ve spojovém seznamu */
   char m_name[100];       /* jmeno akcionare */
   int m_Share;            /* počet akcií */
} TSHARE;

int memShares(TShare *list)
{
	if (list ==  NULL)
	{

		return 0;
	}

	return memShares(list->m_Next) + sizeof(TSHARE);  

}

int main(int argc, char const *argv[])
{
	TSHARE a, b;
	
	a.m_Next = &b;
	b.m_Next = NULL;
	printf("%d\n",memShares(&a));




	return 0;
}