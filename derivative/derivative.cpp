#include <assert.h>
#include <cstddef>
#include <stdlib.h>

#include "../utility/mmu.h"
#include "../debug/log.h"
#include "../diff_config.h"
#include "../debug/utilities.h"
#include "dsl.h"



static node*
NewNode ( diff_man* man, int type, int value, node* left, node* right )
{
    assert( man );

    if ( !man->status )
        return nullptr;

    node* temp = locate_elem( man );

    *temp = { .data = value, .type = type, .left = left, .right = right };
    
    return temp;
}


static node*
get_diff ( diff_man* man, node* curr )
{
    assert( curr );

    switch ( curr->type )
    {
        case CONST_CODE: return NewNode( man, CONST_CODE, 0, 0, 0 );
        case VARIABLE_CODE: return NewNode( man, CONST_CODE, 1, 0, 0 );
        case OPERATION_CODE:
            switch ( curr->data )
            {
                case '+': __ADD( __DL, __DR );
                case '-': __SUB( __DL, __DR );
                case '*': __ADD( __MUL( __DL, __CR ), __MUL( __CL, __DR ) );
                case '/': __DIV( __SUB( __MUL( __DL, __CR ), __MUL( __CL, __DR ) ), __MUL( __CR, __CR ) );
                case '^': __MUL( __POW( __CL, __CR ), 
                    __ADD( __MUL( __DR, __LN( __CL ) ), __DIV( __MUL( __CR, __DL ), __CL ) ) );
                case LOG_CODE: __DIV( __MUL, __MUL( __LN( )))               

                default:
                    man->status = false;
                    printlg( "Failure: incorrect data value: <%d> with type %d\n", curr->data, curr->type );
                    return nullptr;
            }

        default:
            man->status = false;
            printlg( "Failure: incorrect datatype: <%d>\n", curr->type );
            return nullptr;
    }
}

int 
handle_diff ( diff_man* man )
{
    assert( man );

    checki( man->status, "ignore_diff" );

  

}