//
//  main.c
//  equalTrees
//
//  Created by Tomas Sykora on 1/24/13.
//  Copyright (c) 2013 Tomas Sykora. All rights reserved.
//



//      A:  7     B:  7     C:  7     D:  7     E:  7
//      / \       /         / \       / \       / \
//      6  35     6         6  35     6  35     5  35
//                          /
//                          18

#include <stdio.h>

typedef struct TNode {
    int m_Data;
    struct TNode * m_L, * m_R;
} TNODE;


int equalTrees(TNODE* tree1,TNODE* tree2)
{
    if (tree1 == tree2 ) {
        return 1;
    }
    if (tree1 == NULL || tree2 == NULL ) {
        return 0;
    }
    
    if (tree1->m_Data != tree2->m_Data) {
        return 0;
    }
    
    return (equalTrees(tree1->m_L, tree2->m_L) && equalTrees(tree1->m_R, tree2->m_R));
    
    
    
}

int main(int argc, const char * argv[])
{



    return 0;
}

