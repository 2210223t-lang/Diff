#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../diff_config.h"
#include "../debug/log.h"
#include "../debug/utilities.h"



static int
init_zone ( zone_man* ptr, size_t elem_size )
{
    assert( ptr );

    ptr->zones = ( zone* ) calloc( MMU_INIT_QUANTITY, sizeof( zone ) );
    checki( ptr, "Failure: can't allocate enough memory" )
    
    ptr->zones[ 0 ].data = ( char* ) calloc( ZONE_MAX_QUANTITY, elem_size );
    checki( ptr->zones[ 0 ].data, "Failure: can't allocate enough memory" );

    ptr->quantity = 1;
    ptr->zones[ 0 ].quantity = 0;

    return Success_Diff;
}


int 
init_mmu ( diff_man* data )
{
    assert( data );
    
    if ( !( !data->diff_mmu.stat        && !data->diff_mmu.konst.zones && 
            !data->diff_mmu.opera.zones && !data->diff_mmu.varia.zones ) )
    {
        printdb( "Failure: mmu_initialization" );
        return Failure_Diff;
    }

    checki( init_zone( &data->diff_mmu.opera, OPERATION_ELEM_BYTESIZE ), "ignore_diff" );
    checki( init_zone( &data->diff_mmu.konst,     CONST_ELEM_BYTESIZE ), "ignore_diff" );
    checki( init_zone( &data->diff_mmu.varia,  VARIABLE_ELEM_BYTESIZE ), "ignore_diff" );
    
    return Success_Diff;
}


static int
add_zone ( zone_man* ptr, size_t size )
{
    assert( ptr );

    zone* temp = ( zone* ) realloc( ptr->zones, sizeof ( zone ) * ( 1 + ptr->quantity ) );
    checki( temp, "Failure: can't reallocate mmu's zone" );
    ptr->zones = temp;

    char* temp_arr = ( char* ) calloc( ZONE_MAX_QUANTITY, size );
    checki( temp_arr, "Failure: can't locate new zone for mmu" );
    ptr->zones[ ptr->quantity ].data = temp_arr;
    
    ptr->zones[ ptr->quantity++ ].quantity = 0;

    return Success_Diff;
}


int
free_mmu ( diff_man* data )
{
    assert( data );

    mmu temp = data->diff_mmu;

    checki( temp.stat, "Warning: attempt to free incorrect mmu struct" );



}