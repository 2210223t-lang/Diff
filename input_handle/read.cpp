#include <stdio.h>
#include <assert.h>

#include "../utility/mmu.h"
#include "../diff_config.h"



static node*
read_elem ( FILE* istream )
{
    assert( istream );

    char opera[ MAX_OPERATOR_LENGTH ] = "";
    int temp = 0;

    while ( ( ( temp = getc( istream ) ) == ')' || temp =='(' ) && temp != EOF );

    while ( ( ( temp = getc( istream ) ) != ')' && temp !='(' ) && temp != EOF )
    {


    }

}
//FIXME whole file

static node*
get_node ( FILE* istream )
{
    assert( istream );


}