#include <assert.h>
#include <stdlib.h>

#include "../diff_config.h"
#include "../debug/log.h"
#include "../debug/utilities.h"



//-------------------Initialization----------------------
int
init_mmu ( zone_man* ptr )
{
    assert( ptr );

    ptr->zones = ( zone* ) calloc( MMU_INIT_QUANTITY, sizeof( zone ) );
    checki( ptr, "Failure: can't allocate enough memory" )
    
    ptr->zones[ 0 ].data = ( node* ) calloc( ZONE_MAX_QUANTITY, sizeof( node ) );
    checki( ptr->zones[ 0 ].data, "Failure: can't allocate enough memory" );

    ptr->quantity = 1;
    ptr->zones[ 0 ].quantity = 0;

    return Success_Diff;
}


//---------------Locating--------------
static int
add_zone ( zone_man* ptr )
{
    assert( ptr );

    zone* temp = ( zone* ) realloc( ptr->zones, sizeof ( zone ) * ( 1 + ptr->quantity ) );
    checki( temp, "Failure: can't reallocate mmu's zone" );
    ptr->zones = temp;

    node* temp_arr = ( node* ) calloc( ZONE_MAX_QUANTITY, sizeof( node ) );
    checki( temp_arr, "Failure: can't locate new zone for mmu" );
    ptr->zones[ ptr->quantity ].data = temp_arr;
    
    ptr->zones[ ptr->quantity++ ].quantity = 0;

    return Success_Diff;
}


static node*
find_space ( zone_man* ptr )
{
    assert( ptr );

    if ( ptr->zones[ ptr->quantity - 1 ].quantity == ZONE_MAX_QUANTITY )
        if ( add_zone( ptr ) == Failure_Diff )
            return nullptr;

    return ptr->zones[ ptr->quantity - 1 ].data + ( ptr->zones[ ptr->quantity - 1 ].quantity++ - 1 );
}


node*
locate_elem ( diff_man* man )
{
    assert( man );

    if ( !man->status || !man->diff_mmu.stat)
    {
        printdb( "Failure: can't proceed locating" );
        man->status = false;
        return nullptr;
    }
    return find_space( &man->diff_mmu.zone );
}


//--------------------Destroying----------------------
static int
free_zone ( zone_man* zone )
{
    assert( zone );

    if ( zone->zones )
    {
        for ( int i = 0; i < zone->quantity; i++ )
            free( zone->zones[ i ].data );
        
        free( zone->zones );

        return Success_Diff;
    }

    return Failure_Diff;
}


int
free_mmu ( diff_man* data )
{
    assert( data );

    mmu temp = data->diff_mmu;

    checki( temp.stat , "Warning: attempt to free incorrect mmu struct" );

    checki( ( free_zone( &temp.zone ) == Success_Diff ), "Failure: incorrect mmu struct" );
   
    return Success_Diff;
}