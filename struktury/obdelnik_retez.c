#include <stdio.h>
#include <stdlib.h>


 typedef struct box
 {
 	struct box s_next;
 	int a, b;
 	char color[31];
 }BOX;

 BOX *makeEmpty( int amount)
 {
	 BOX *tmp;
	 BOX *origin;

	 tmp = malloc (sizeof (BOX));
	 origin = tmp;	 

	 for (int i = 1; i < amount; ++i)
	 {
	 	tmp->s_next = malloc(sizeof(BOX));
	 	tmp = tmp->s_next;		
	 }

	tmp->s_next = NULL;
	return origin;
 }

 int main(int argc, char const *argv[])
 {

 	BOX *prvni = makeEmpty( 10);
 	
 	return 0;
 }