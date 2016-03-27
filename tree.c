#include "tree.h"

struct Node* create_node(int value) {

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    if ( unlikely(!node) )
        return NULL;

    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->count = 1;

    return node;
}

void free_node( struct Node* node ) {

    if ( unlikely(!node) )
        return;
    
    if ( node->left )
        free_node(node->left);
    if (node->right )
        free_node(node->right);
    free(node);

}

int search( struct Node* node, int key ) {
    
    if ( unlikely(!node) )
        return -1;
    
    for(;;) {
        if ( !node )
            return 0;
        else if (key == node->data)
            return 1;
        else if (key < node->data)
            node = node->right;
        else
            node = node->left;
    }

}

int add( struct Node** node, int key ) {
    

    if ( unlikely(!node) )
        return -1;

    if ( !*node ) {
        *node = create_node(key);
        if ( unlikely(!*node) )
            return -1;

        return 0;
    }

    if ( key < (*node)->data )
        return add( &((*node)->left), key );

    
    else if( key > (*node)->data )
        return add( &((*node)->right),key);

    else {
        (*node)->count++;
        return 0;
    }
}

void print_tree( struct Node* node, FILE* file ) {

    if ( !node )
        return;
    print_tree(node->left,file);
    for (size_t i = 0; i < node->count; ++i )
        fprintf(file,"%d ",node->data);
    print_tree(node->right, file);

}

struct Node* create_tree_from_file(FILE* file) {
    
    int value = 0;
    struct Node* node = NULL;
    while (fscanf(file,"%d",&value) == 1) {
        if (add(&node,value)) {
            printf("cannot add value\n");
            if (node)
                print_tree(node,file);
            free_node(node);
            return NULL;
        }
    }
    return node;
}
