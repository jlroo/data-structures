//
//  btree.cpp
//  C++
//
//  Created by jlroo on 11/6/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#include "btree.h"
using namespace std;

// Driver program to test above functions
int main()
{
    struct Node * root = NULL;
    
    char word1='cat';
    char word2='cats';
    char word3='up';
    char word4='bug';

    
    insert(&root,&word1);
    insert(&root,&word2);
    insert(&root,&word3);
    insert(&root,&word4);
    
    printf("Following is traversal of ternary search tree\n");
    traverseTST(root);
    
    cout<<"Following are search results for cats, bu and cat respectively"<<endl;

    
    return 0;
}