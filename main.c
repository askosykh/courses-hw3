#include "tree.h"

// check count of command line arguements
int check_argc_count( int argc ) {

    if ( argc != 3 )
        return 1;
    return 0;

}

// read numbers from file and fill the struct
struct Node* read_from_file( char* filename ) {

    FILE* file = fopen( filename, "r" );

    if( !file )  {
        printf( "Something went wrong. Cannot read data from file.\n");
        return NULL;
    }
    struct Node* node = create_tree_from_file(file);
    if (!node) {
        fclose( file );
        printf("cannot create tree from file.\n");
        return NULL;
    }

    fclose( file );

    return node;
}

// writing data from struct to file
int write_to_file( struct Node* node, char* filename ) {

    FILE* file = fopen( filename, "w+" );

    if( !file )
        return 1;
    if ( !node ) {
        fclose( file );
        return -1;
    }

    print_tree(node, file);
    free_node(node);
    fclose( file );

    return 0;
}


int main( int argc, char* argv[] ) {

    if ( check_argc_count(argc) ) {
        printf( "Wrong arguements count.\n" );
        return 1;
    }
    struct Node* node = NULL;
    node = read_from_file(argv[1]);
    if ( !node ) {
        return 1;
    }

    if ( write_to_file(node, argv[2]) ) {
        printf( "Something went wrong. Cannot write data to file.\n" );
        return 1;
    }

    return 0;

}
