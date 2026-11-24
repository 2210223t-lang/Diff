#include <linux/limits.h>
#include <stdio.h>
#include <assert.h>

#include "../diff_config.h"
#include "../debug/utilities.h"


static FILE* docs_out = 0;
static char docs_path[ PATH_MAX ] = "docs.tex";



void
start_gener ( bool do_proceed )
{

    if ( !do_proceed )
        return;

    docs_out = fopen( docs_path, "w" );
    
    if ( !docs_out)
        printlg( "Error: can't open docs file" );
}


void 
generate_docs ( bool do_proceed )
{
    if ( !do_proceed )
        return;

        

}


void
exit_gener ( bool do_proceed )
{

    if ( !do_proceed )
        return;

    fclose( docs_out );
    docs_out = 0;
}