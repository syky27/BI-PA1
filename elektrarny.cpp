#include<stdio.h>
#include<limits.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int swingers(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int index;
    int maximus = INT_MAX;
    int equation;
    

    for (index = i; index <j; index++)
    {
        equation = swingers(p, i, index) + swingers(p, index+1, j) + p[index]+p[i-1]*p[j];
        if (equation < maximus)
            maximus = equation;
    }
    
    return maximus;
}

int main()
{

    int* bolts;
    int size = 2;
    int i = 0;

    bolts = ((int *) malloc(size * sizeof (int)));
    
    cout<<"Zadejte pocty sroubu pro jednotlive priruby:"<<endl;
    while (1) {
        
        
        if ( i == size ) {
            size++;
            bolts = (int*) realloc(bolts, size * sizeof(int));
        }
        cin >> bolts[i];
        if ((bolts[i] <= 0)) {
            cout<<"Nespravny vstup."<<endl;
            return 1;
        }
        i++;

        if (cin.get() == '\n')break;

    }


    /* Pokud jsou na vstupu pouze 2 čísla */
    
    if (i == 1) {
        cout<<"Nespravny vstup."<<endl;
        return 0;
    }
    if (i == 2) {
        cout<<"Cena: 0"<<endl;
        return 0;
    }
    int n = i;
    cout<<"Cena: "<<swingers(bolts, 1, n-1)<<endl;
    
    return 0;
}