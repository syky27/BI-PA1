//
//  main.c
//  sudejStrom
//
//  Created by Tomas Sykora on 1/24/13.
//  Copyright (c) 2013 Tomas Sykora. All rights reserved.
//

#include <stdio.h>

typedef struct TNode {
    int            m_Data;
    struct TNode * m_L, * m_R;
} TNODE;


int sumHelp(TNODE *root, int even)
{
    if (root == NULL) {
        return 0;
    }
    if (even){
        return root->m_Data + sumHelp(m_L, 0 ) + sumHelp (m_R, 0);
    }
    
    return sumHelp(m_L, 1 ) + sumHelp (m_R, 1);
}


int sumEvenLevels ( TNODE * root )
{

    return sumHelp(root, 1);
}







int main(int argc, const char * argv[])
{

    

    return 0;
}

