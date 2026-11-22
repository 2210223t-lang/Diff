#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../diff_config.h"
#include "../debug/log.h"



int 
init_mmu ( tree_diff* data )
{
    assert( data );
    
    if ( data->diff_mmu.stat == Success_Diff && !data->diff_mmu.konst.zones && !data->diff_mmu.opera.zones && !data->diff_mmu.varia.zones )
    {

        return Success_Diff;
    }

    printlg("asdas" );
    return Failure_Diff;
}