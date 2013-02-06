//
//      Ještě že to nebyly zase vlaky to bych si fakt už hodil mašli :)
//
//  main.cpp
//  tree
//
//  Created by Tomas Sykora on 12/10/12.
//  Copyright (c) 2012 Tomas Sykora. All rights reserved.
//


#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#define TELCO_NUMBERS 10

typedef struct TNode
{
    char          * m_Dest;
    struct TNode  * m_Child[TELCO_NUMBERS];
} TNODE;

#endif /* __PROGTEST__ */

#define TRUE 1
#define FALSE 0
#include <iostream>
#include <string>

TNODE * newNode() {
    TNODE * ptr = (TNODE*)malloc(sizeof (*ptr));
    for (int i=0; i < TELCO_NUMBERS; i++) {
        ptr->m_Child[i] = NULL;
    }
    ptr->m_Dest = NULL;
    
    return ptr;
}

void delTree ( TNODE * root )
{
    if (root == NULL) {
        return;
    }
    
    if (root->m_Dest != NULL ) {
        free(root->m_Dest);
    }
    
    
    for (int i = 0;i < TELCO_NUMBERS; i++) {
        delTree(root->m_Child[i]);
    }
    
    free(root);
}

void clearTree ( TNODE ** root )
{
    if (*root == NULL) {
        return;
    }
    
    int alive = FALSE;
    
    for (int i = 0; i < TELCO_NUMBERS; i++) {
        clearTree(&((*root)->m_Child[i]));
        if ( ((*root)->m_Child[i]) != NULL ) {
            alive = TRUE;
        }
        
    }
    
    if (!alive && ((*root)->m_Dest == NULL)) {
        delTree(*root);
        *root = NULL;
    }
    
}


int addDest ( TNODE ** root, const char * prefix, const char * dest )
{
    
    TNODE *ptr = *root;
    int idx = -1;
    
    /* Check prefixes for int values */
    for (size_t i = 0; i < strlen(prefix); i++) {
        //size_t a = strlen(prefix);
        idx  = prefix[i] - '0';
        if (idx > 9 || idx < 0 ) {
            return FALSE;
        }
        
    }
    
    if (ptr == NULL) {
        *root = newNode();
        ptr = *root;
    }
    
    for (size_t i = 0 ; i <strlen(prefix) ; i++) {
        idx  = prefix[i] - '0';
        if (ptr->m_Child[idx] == NULL) {
            ptr->m_Child[idx] = newNode();
        }
        ptr = ptr->m_Child[idx];
        
    }
    
    ptr->m_Dest = (char*)malloc(strlen(dest)+1);
    strcpy(ptr->m_Dest, dest);
    
    
    return TRUE;
    
}

int delDest ( TNODE ** root, const char * prefix )
{
    TNODE *ptr = *root;
    int idx = -1;
    
    if ((ptr == NULL) || (strlen(prefix) == 0)) {
        return FALSE;
    }
    
    for (size_t i = 0; i < strlen(prefix); i++) {
        
        idx  = prefix[i] - '0';
        if (idx > 9 || idx < 0 ) {
            return FALSE;
        }
        
        if (ptr->m_Child[idx] == NULL) {
            return FALSE;
        }
        
        ptr = ptr->m_Child[idx];
        
        
    }
    
    free(ptr->m_Dest);
    ptr->m_Dest = NULL;
    
    for (int i = 0; i < TELCO_NUMBERS; i++) {
        if (ptr->m_Child[i])
            return TRUE;
    }
    
    clearTree(root);
    
    return TRUE;
    
}

const char * search ( TNODE * root, const char * number )
{
    
    char *ret = NULL;
    
    TNODE * ptr;
    ptr = root;
    int idx = 0;
    
    if ((ptr == NULL) || (strlen(number) == 0)) {
        return NULL;
    }
    
    for (size_t i = 0; i < strlen(number); i++) {
        idx  = number[i] - '0';
        if (idx > 9 || idx < 0 ) {
            return NULL;
        }
    }
    for (size_t i = 0; i < strlen(number); i++) {
        
        idx  = number[i] - '0';
        
        ptr = ptr->m_Child[idx];
        if (ptr == NULL) {
            return ret;
        }
        if (ptr->m_Dest != NULL) {
            ret = ptr->m_Dest;
        }
        
        
    }
    
    return ret;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
    TNODE       * root;
    char          tmpStr[100];
    const char  * dst;
    int           res;
    
    root = NULL;
    res = addDest ( &root, "420", "Czech republic" ); /* res = 1 */
    std::cout<<res<<std::endl;
    res = addDest ( &root, "421", "Slovak republic" ); /* res = 1 */
    std::cout<<res<<std::endl;
    res = addDest ( &root, "1", "USA" ); /* res = 1 */
    std::cout<<res<<std::endl;
    res = addDest ( &root, "420606", "CZ - O2 mobil" ); /* res = 1 */
    std::cout<<res<<std::endl;
    res = addDest ( &root, "420606123456", "CZ - Vodafone" ); /* res = 1 */
    std::cout<<res<<std::endl;
    dst = search ( root, "420606334455" ); /* dst = "CZ - O2 mobil" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "420603212223" ); /* dst = "Czech republic" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "420606123456" ); /* dst = "CZ - Vodafone" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "42060612345" ); /* dst = "CZ - O2 mobil" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "37123456" ); /* dst = NULL */
    
    /* nemuzu testovat pada do segfault - logicky  */
    
    
    dst = search ( root, "1998877665544332211" ); /* dst = "USA" */
    std::cout<<dst<<std::endl;
    delTree ( root );
    
    root = NULL;
    res = addDest ( &root, "420", "Czech republic" ); /* res = 1 */
    std::cout<<res<<std::endl;
    res = addDest ( &root, "421", "Slovak republic" ); /* res = 1 */
    std::cout<<res<<std::endl;
    res = addDest ( &root, "1", "USA" ); /* res = 1 */
    std::cout<<res<<std::endl;
    res = addDest ( &root, "420606", "CZ - O2 mobil" ); /* res = 1 */
    std::cout<<res<<std::endl;
    res = addDest ( &root, "420606123456", "CZ - Vodafone" ); /* res = 1 */
    std::cout<<res<<std::endl;
    dst = search ( root, "420222333444" ); /* dst = "Czech republic" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "420606112233" ); /* dst = "CZ - O2 mobil" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "420606123456" ); /* dst = "CZ - Vodafone" */
    std::cout<<dst<<std::endl;
    res = delDest ( &root, "420" ); /* res = 1 */
    std::cout<<res<<std::endl;
    
    /*  tady res je 0 */
    
    dst = search ( root, "420222333444" ); /* dst = NULL */
    
    /* nemuzu testovat pada do segfault - logicky  */
    
    dst = search ( root, "420606112233" ); /* dst = "CZ - O2 mobil" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "420606123456" ); /* dst = "CZ - Vodafone" */
    std::cout<<dst<<std::endl;
    res = addDest ( &root, "42", "Euro telco company" ); /* res = 1 */
    std::cout<<res<<std::endl;
    dst = search ( root, "420222333444" ); /* dst = "Euro telco company" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "420606112233" ); /* dst = "CZ - O2 mobil" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "420606123456" ); /* dst = "CZ - Vodafone" */
    
    delTree ( root );
    
    root = NULL;
    strncpy ( tmpStr, "Czech republic", sizeof ( tmpStr ) );
    res = addDest ( &root, "420", tmpStr ); /* res = 1 */
    std::cout<<res<<std::endl;
    strncpy ( tmpStr, "Slovak republic", sizeof ( tmpStr ) );
    res = addDest ( &root, "421", tmpStr ); /* res = 1 */
    std::cout<<res<<std::endl;
    strncpy ( tmpStr, "USA", sizeof ( tmpStr ) );
    res = addDest ( &root, "1", tmpStr ); /* res = 1 */
    std::cout<<res<<std::endl;
    strncpy ( tmpStr, "CZ - O2 mobil", sizeof ( tmpStr ) );
    res = addDest ( &root, "420606", tmpStr ); /* res = 1 */
    std::cout<<res<<std::endl;
    strncpy ( tmpStr, "CZ - Vodafone", sizeof ( tmpStr ) );
    res = addDest ( &root, "420606123456", tmpStr ); /* res = 1 */
    std::cout<<res<<std::endl;
    dst = search ( root, "420606334455" ); /* dst = "CZ - O2 mobil" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "420603212223" ); /* dst = "Czech republic" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "420606123456" ); /* dst = "CZ - Vodafone" */
    std::cout<<dst<<std::endl;
    dst = search ( root, "37123456" ); /* dst = NULL */
    
    
    
    dst = search ( root, "1998877665544332211" ); /* dst = "USA" */
    delTree ( root );
    
    root = NULL;
    res = addDest ( &root, "420", "Czech republic" ); /* res = 1 */
    res = addDest ( &root, "1", "USA" ); /* res = 1 */
    dst = search ( root, "420606334455" ); /* dst = "Czech republic" */
    dst = search ( root, "12345" ); /* dst = "USA" */
    res = delDest ( &root, "1" ); /* res = 1 */
    dst = search ( root, "12345" ); /* dst = NULL */
    res = delDest ( &root, "420" ); /* res = 1 */
    dst = search ( root, "420606334455" ); /* dst = NULL */
    res = delDest ( &root, "420" ); /* res = 0 */
    res = addDest ( &root, "420A", "???" ); /* res = 0 */
    delTree ( root );    return 0;
}
#endif /* __PROGTEST__ */
