/*
 *Realizujte funkci equalTree, která zjistí, zda-li se dva zadané stromy shodují (vrátí 1 při shodě).
 */

 #include <stdio.h>
 #include <stdlib.h>

 typedef struct TNode 
 {
    int m_Data;
    struct TNode * m_L, * m_R;
 } TNODE;

 int equalTree (TNODE* a, TNODE*b)
 {
    return (!a && !b) || (a && b && a->m_Data == b->m_Data && equalTree (a->m_L, b->m_L) && equalTree (a->m_R, b->m_R));
 }

 int main(int argc, char const *argv[])
 {
	
	TNODE a,b,c;


	a.m_Data = 3;
	b.m_Data = 3;

	b.m_R = a.m_R = NULL;
	b.m_L = a.m_L = NULL;


	printf ("%d",equalTree(&a,&b));

 	return 0;
 }