#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>

#define unlikely(x) __builtin_expect(!!(x),0)

struct Node;
// struct of one node
struct Node {
    
    // value of node
    int data;

    // ptr to left child
    struct Node *left;

    // ptr to right child
    struct Node *right;

    // count of same values
    int count;

};

// create an empty tree
struct Node* create_node(int value);

// free memory
void free_node( struct Node* node );

// search the node by key
int search( struct Node* node, int key );

// add the node
int add(struct Node** node, int key );

// printing tree to file
void print_tree( struct Node* node, FILE* file );

// create a tree from file
struct Node* create_tree_from_file(FILE* file);
#endif //_MATRIX_H_
