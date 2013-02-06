/* 
 * File:   trains2.c
 * Author: Tomas Sykora, jr.
 * Eukliduv algoritmus viz: http://www.algoritmy.net/article/44/Eukliduv-algoritmus
 * Created on 7. listopad 2012, 14:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SUCCESS 0
#define FAIL 1

long long int  GratestCommonDivider ( long long int  a, long long int  b );
long long int  GratestCommonDividerForAnArray(long long int  * n, long long int  size);
long long int  LeastCommonMultiplier(long long int  a, long long int  b);
int LeastCommonMultiplierForAnArray(long long int  * n, long long int  size, long long int  *UINTRetval);

int myInput(long long int * Trains, long long int * ConversedTime)
{
    long long int i, j, myInputTrains;
    printf("Zadejte pocet vlaku:\n");
    if(! (scanf("%lld", &myInputTrains) == 1 && myInputTrains <= 20 && myInputTrains >= 1))
    {
        printf("Nespravny vstup.\n");
        exit (FAIL);
    }

    *Trains = myInputTrains;
    for(i=0,j=1;i<myInputTrains;i++,j++)
    {
        long long int Hours, Minutes;
        printf("Interval vlaku %lld:\n",j);
        if(! (scanf("%lld:%lld", &Hours, &Minutes) == 2 && Hours >= 0 && Hours <= UINT_MAX  && Minutes >= 0 && Minutes < 60  && Minutes <= UINT_MAX && Hours <= UINT_MAX && (Hours != 0 || Minutes != 0)))
        {
            printf("Nespravny vstup.\n");
            exit (FAIL);
        }
        ConversedTime[i] = (Hours*60 + Minutes);
    }
    return SUCCESS;
}

int main(int argc, char** argv) 
{
    long long int Trains;
    long long int  ConversedTime[20];
    long long int  UINTRetval;
    
    myInput(&Trains,&ConversedTime[0]);
    
    if(Trains == 1)
    {
        printf("Vsechny vlaky se potkaji za: %lld:%lld\nMezitim projede:\n* vlak 1: 0x.\n",ConversedTime[0]/60,ConversedTime[0]-(ConversedTime[0]/60)*60);
        return SUCCESS;
    }
    else
    {
			if (FAIL ==  LeastCommonMultiplierForAnArray(ConversedTime, Trains, &UINTRetval))
			{
					printf("Vysledek mimo rozsah datoveho typu.\n");
					exit(FAIL);
			}

    printf("Vsechny vlaky se potkaji za: %lld:%02lld\nMezitim projede:\n",UINTRetval / 60, UINTRetval - (UINTRetval / 60) * 60);
    long long int   i, j, repeat;
    for(i=0,j=1,repeat=0; i <= (Trains-1);i++)
    {
        repeat = (UINTRetval / ConversedTime[i])-1;
        printf("* vlak %lld: %lldx",j++,repeat);
       
        if(i==(Trains-2))
        {
            printf(" a\n");            
        }
        else if(i==(Trains-1))
        {
            printf(".\n");
        }        
        else
        {
            printf(",\n");
        }        
}    
    return SUCCESS;
    }
}

long long int  GratestCommonDivider (long long int  a, long long int  b )
{
    unsigned c;
    while ( a != 0 )
    {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}

long long int  LeastCommonMultiplier(long long int  a, long long int  b)
{
    return (b / GratestCommonDivider(a, b) ) * a;
}

long long int  GratestCommonDividerForAnArray(long long int  * n, long long int  size)
{
    long long int  last_gcd, i;
    if(size < 2) return 0;
    last_gcd = GratestCommonDivider(n[0], n[1]);
    for(i=2; i < size; i++)
    {
        last_gcd = GratestCommonDivider(last_gcd, n[i]);
    }
   return last_gcd;
}

int LeastCommonMultiplierForAnArray(long long int  * n, long long int  size, long long int  *UINTRetval)
{
		int bRet = SUCCESS;
		*UINTRetval = 0;
    long long int  last_lcm, i;
    if(size < 2) return 0;
    last_lcm = LeastCommonMultiplier(n[0], n[1]);

    for(i = 2; i < size; i++)
    {
        last_lcm = LeastCommonMultiplier(last_lcm, n[i]);
				if (last_lcm > UINT_MAX )
				{
					bRet = FAIL;
					*UINTRetval = 0;
					break;
				}
    }
 		*UINTRetval = last_lcm;
	   return bRet;
}
