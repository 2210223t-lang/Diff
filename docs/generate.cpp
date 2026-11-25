#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../diff_config.h"
#include "../debug/utilities.h"


static FILE* docs_out = 0;
static char docs_path[ PATH_MAX ] = "docs.tex";
static size_t steps_count = 1;

static const size_t max_phrase = 100;
static const size_t count_phrase = 10;
static char phrases[ count_phrase ][ max_phrase ] = {
    "\n",
    "I don't wanna spend my time on this shit\n",
    "So now we should take this derivative",
    "This is a listed derivative, you can check it in your workbook",
    "No"
};


void
printdoc ( const char* text, ... )
{
    assert( text );

    va_list args;
    va_start( args, text );
    vfprintf( docs_out, text, args );
    va_end( args );
}


void
start_gener ( bool do_proceed )
{

    if ( !do_proceed )
        return;

    docs_out = fopen( docs_path, "w" );

    if ( !docs_out)
        printlg( "Error: can't open docs file" );

    printdoc( "\\documentclass{article}\n"
              "\\usepackage[T2A]{fontenc}\n"
              "\\usepackage[russian]{babel}\n"
              "\\usepackage{amsmath}\n"
              "\\usepackage[unicode]{hyperref}\n"
              "\\begin{document}\n\n" );
}


void
generate_docs ( bool do_proceed, node* before, node* diff )
{
    if ( !do_proceed )
        return;

    printdoc( "%d: ", steps_count++ );

    printdoc()


}


void
exit_gener ( bool do_proceed )
{

    if ( !do_proceed )
        return;

    printdoc( "\end{document}" );

    fclose( docs_out );
    docs_out = 0;

    system( "pdflatex docs.tex" );
    system( "pdflatex docs.tex" );
}
