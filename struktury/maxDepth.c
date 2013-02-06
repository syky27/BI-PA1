//
//  main.c
//  maxDept
//
//  Created by Tomas Sykora on 1/24/13.
//  Copyright (c) 2013 Tomas Sykora. All rights reserved.
//

#include <stdio.h>


typedef struct TNode {
    int m_Data;
    struct TNode * m_L, * m_R;
} TNODE;

int maxDepthHelper(TNODE *root, int depth)
{

    if (root == NULL) {
        return depth;
    }

    int levej = maxDepthHelper(root->m_L, depth + 1);
    int pravej = maxDepthHelper(root->m_R, depth + 1);
    
    
    if (pravej > levej) {
        return pravej;
    }
    
    return levej;
    
}

int maxDepth(TNODE *root)
{
    return maxDepthHelper(root, 0);
}


int main(int argc, const char * argv[])
{

    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

