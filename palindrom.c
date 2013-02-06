#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

char *itoaa(unsigned long long int i, char* s, int dummy_radix) {
    sprintf(s, "%llu", i);
    return s;
}

void MyReverse(char *str)
{
             char *lpstrOut;
             lpstrOut = (char *) malloc(strlen(str) + 1);

             int iB, iE;

             lpstrOut[strlen(str)] = 0x00;
    for (iB = 0, iE = strlen(str) - 1; iE >= 0; iB++, iE--)
    {
                    lpstrOut[iE] = str[iB];
             }
             strcpy(str, lpstrOut);
             free ((void *) lpstrOut);
    return;
}



       void Equation(char EnteredString[100], char ReversedString[100])
       {
             int i;
             unsigned long long int EnteredInt, ReversedInt;
             unsigned long long int EnteredIntBeforeCycle = ULLONG_MAX;
             //printf("LONG LONG: %llu \n",EnteredIntBeforeCycle);


             for (i=1; strcmp(EnteredString,ReversedString)!=0; i++)
             {



                    EnteredInt = strtoull(EnteredString,'\0',10);
                    ReversedInt = strtoull(ReversedString,'\0',10);

                    if (EnteredInt + ReversedInt < EnteredInt)
                    {
                           printf("Palindrom nenalezen.\n");
                           break;
                    }

                    EnteredInt = EnteredInt + ReversedInt;
                    itoaa (EnteredInt,EnteredString,10);
                    strcpy(ReversedString, EnteredString);
                    MyReverse(ReversedString);
                    EnteredIntBeforeCycle = EnteredInt;


                    if(strcmp(ReversedString,EnteredString)==0)
                    {
                           printf("Vypocteny palindrom: %s (iteraci: %d)\n",EnteredString, i);
                           break;
                    }
                    else
                    {
                           continue;
                    }

             }

       }
       void isEnteredStringPalindrom (char EnteredString[100])
{
       int iRet;
       char ReversedString [100];
       iRet = FALSE;
       ReversedString[0] = '\0';

       strcpy(ReversedString, EnteredString);
       MyReverse(ReversedString);

       if(strcmp(ReversedString,EnteredString)==0)
       {
       printf("Vypocteny palindrom: %s (iteraci: 0)\n",EnteredString);
       }
       else
       {
             Equation(EnteredString,ReversedString);
       }

}


       int main()

{
       unsigned long long int EnteredNumberBeforeFirstConversionToString;
       char EnteredString [100];
       printf("Zadejte cislo:\n");
       if (scanf("%llu",&EnteredNumberBeforeFirstConversionToString) == 0 )
       {
             printf("Nespravny vstup.\n");
             return 0;
       }
       EnteredString[0] = '\0';
       itoaa (EnteredNumberBeforeFirstConversionToString,EnteredString,10);

       isEnteredStringPalindrom(EnteredString);

       return 0;

       }
