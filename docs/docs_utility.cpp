#include "assert.h"

#include "../diff_config.h"
#include "generate.h"
#include "docs_utility.h"
#include "../debug/utilities.h"



bool
func_seq ( node* curr )
{
    if ( curr->type == OPERATION_CODE && ( curr->data.opera == SUM_CODE || curr->data.opera == MUL_CODE || curr->data.opera == DIF_CODE ) )
        return true;

    return false;
}


static int
print_function_label ( int code )
{
    if ( code == '+' || code == '*' || code == '-' || code == '^' )
    {
        printdoc( "%c", code );
        return Success_Diff;
    }

    switch( code )
    {
        case COS_CODE: printdoc( "cos" );
        case SIN_CODE: printdoc( "sin" );
        case TAN_CODE: printdoc( "tan" );
        case CTG_CODE: printdoc( "ctg" );
        case LOG_CODE: printdoc( "log" );

        default:
            printlg( ERROR_DIFF_STYLE "Error: incorrect data type in %s:%d" ERROR_DIFF_END, __FILE__, __LINE__ );
            return Failure_Diff;
    }
    return Success_Diff;
}


static int
handle_func_out ( node* curr )
{
    assert( curr );

    if ( curr->data.varia == DIV_CODE )
    {
        printdoc( "\\frac{" );
        checki( ( print_function( curr->left ) == Success_Diff ), "Error: printing function into docs" );
        printdoc( "}{" );
        checki( ( print_function( curr->right ) == Success_Diff ), "Error: printing function into docs" );
        printdoc( "}" );
        return Success_Diff;
    }

    if ( func_seq( curr ) )
    {
        checki( ( print_function( curr->left ) == Success_Diff ), "Error: printing function into docs" );
        print_function_label( curr->data.opera );
        checki( ( print_function( curr->right ) == Success_Diff ), "Error: printing function into docs" );
        return Success_Diff;
    }
    else
    {
        print_function_label( curr->data.opera );
        checki( ( print_function( curr->left ) == Success_Diff ), "Error: printing function into docs" );
        return Success_Diff;
    }
}


int
print_function ( node* curr )
{
    assert( curr );

    bool sequence = ( curr->type == OPERATION_CODE ) ? func_seq( curr ) : true;

    printdoc( "\\( " );

    switch( curr->type )
    {
        case OPERATION_CODE:
            checki( ( handle_func_out( curr ) == Success_Diff ), "Error: incorrect func handling return value" );
            return Success_Diff;

        case CONST_CODE: printdoc( "%f", curr->data.konst );

        case VARIABLE_CODE: printdoc( "%c", curr->data.varia );

        default:
            printlg( ERROR_DIFF_END "Error: incorrect data type in %s:%d " ERROR_DIFF_END, __FILE__, __LINE__ );
            return Failure_Diff;
    }

    printdoc( "\\) " );

    return Success_Diff;
}
