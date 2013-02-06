#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char jmeno[50];
	int narozeni = 0;
	float prumer;

}STUDENT;

STUDENT *inputData()
{
	STUDENT *tmp;
	printf("Zadej jmeno\n");
	scanf("%s", tmp->jmeno);
	printf("Zadej narozeni (prvnich 6 cisel RC)\n");
	scanf("%d", tmp->narozeni);
	printf("Zadej prumer\n");
	scanf("%f", tmp->prumer);

	return tmp;
}

int main(int argc, char const *argv[])
{
	
	STUDENT *syky = inputData();



	//	char buffer[255];
	//	char *p_jmeno;
	//	int i;
	//	printf("Zadej jmeno\n");
	//	for(i=0;buffer[i] = getchar();i++) {}
	//	buffer[i] = '\0'
	//	p_jmeno = malloc (i * sizeof(char));
	//	strncpy(p_jmeno, buffer, (i + 1);

	return 0;
}