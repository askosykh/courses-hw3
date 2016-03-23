#include "tree.h"

// check count of command line arguements
int check_argc_count( int argc ) {

    if ( argc != 3 )
        return 1;
    return 0;

}

// read numbers from file and fill the struct
int read_from_file( char* filename ) {

    FILE* file = fopen( filename, "r" );

    if( !file ) 
        return 1;

    fclose( file );

    return 0;
}

// writing data from struct to file
int write_to_file( char* filename ) {

    FILE* file = fopen( filename, "w+" );

    if( !file )
        return 1;

    fclose( file );

    return 0;
}


int main( int argc, char* argv[] ) {

    if ( check_argc_count(argc) ) {
        printf( "Wrong arguements count.\n" );
        return 1;
    }

    if ( read_from_file(argv[1]) ) {
        printf( "Something went wrong. Cannot read data from file.\n");
        return 1;
    }

    if ( write_to_file(argv[2]) ) {
        printf( "Something went wrong. Cannot write data to file.\n" );
        return 1;
    }

    return 0;

}
