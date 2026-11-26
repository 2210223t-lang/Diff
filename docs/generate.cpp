#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include "sys/stat.h"
#include "sys/mman.h"
#include "fcntl.h"
#include "unistd.h"

#include "../debug/colours.h"
#include "../diff_config.h"
#include "../debug/utilities.h"
#include "docs_utility.h"



static FILE* docs_out = 0;
static char docs_path[ PATH_MAX ] = "docs.tex";
static size_t steps_count = 1;

static char start_file[ PATH_MAX ] = "start.txt";

static const size_t max_phrase = 100;
static const size_t count_phrase = 10;
static char phrases[ count_phrase ][ max_phrase ] = {
    "\n",
    "I don't wanna spend my time on this shit\n",
    "So now we should take this derivative",
    "This is a listed derivative, you can check it in your workbook",
    "No"
};



static size_t
Getsize( int fd )
{
    struct stat buf = {};

    fstat( fd, &buf );

    return buf.st_size;
}


void
printdoc ( const char* text, ... )
{
    assert( text );

    va_list args;
    va_start( args, text );

    vfprintf( docs_out, text, args );
    va_end( args );
}


int
start_gener ( bool do_proceed )
{

    if ( !do_proceed )
        return Failure_Diff;

    docs_out = fopen( docs_path, "w" );

    checki( docs_out, "Error: can't open docs file" );

    int fd_start = open( start_file, O_RDONLY );
    checki( fd_start, "Error: can't open starting file" );

    char* data = ( char* ) mmap( NULL, Getsize( fd_start ), PROT_READ, MAP_PRIVATE, fd_start, 0 );

    checki( ( data == MAP_FAILED ), "Error: can't mmap start file." );

    fprintf( docs_out, "%s", data );

    munmap( data, Getsize( fd_start ) );
    close( fd_start );
    return Success_Diff; //TODO improve introduction.
}


void
generate_docs ( bool do_proceed, node* before, node* diff )
{
    if ( !do_proceed )
        return;

    printdoc( "\\subsection{ Step: %d }\n", steps_count++ );

    // printdoc()


}


void
exit_gener ( bool do_proceed )
{

    if ( !do_proceed )
        return;

    //TODO add ending.

    printdoc( "\\end{document}" );

    fclose( docs_out );
    docs_out = 0;

    system( "pdflatex docs.tex" );//FIXME incorrect command
    system( "pdflatex docs.tex" );//FIXME incorrect command
}
