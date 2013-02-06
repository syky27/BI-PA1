/*
 *	Vytvořit funkci int menShares(TShare *list), která zjistí kolik bajtů
 *	paměti zabírá zadaný seznam akcionářů - POZOR JDE O SPOJOVÝ SEZNAM
 */


#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

 typedef struct TShare{
	struct TShare *m_Next;
	char m_name[100];
	int M_Share;
	}TSHARE;


 int memShares(TSHARE *leaf){
 	if (!leaf) {
 	    return 0;
 	}
 	return ( memShares(leaf->m_Next))  + sizeof(TSHARE);
 };
 int main (void) {
 	TSHARE *p = (TSHARE*) malloc (sizeof(TSHARE));
 	p->m_Next = (TSHARE*) malloc (sizeof(TSHARE));
 	return memShares(p);
 }
