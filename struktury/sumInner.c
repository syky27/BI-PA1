//
//  main.c
//  sumInner
//
//  Created by Tomas Sykora on 1/24/13.
//  Copyright (c) 2013 Tomas Sykora. All rights reserved.
//

#include <stdio.h>

typedef struct TNode {
    int m_Data;
    struct TNode * m_L, * m_R;
} TNODE;

int sumInner(TNODE *root)
{
    
    if (root == NULL) {
        return 0;
    }
    
    if (!(root->m_R || root->m_L)) {
        return 0;
    }
    
    return (sumInner(root->m_L) + sumInner(root->m_R ) + root->m_Data);
    

};


int main(int argc, const char * argv[])
{


    
    return 0;
}

