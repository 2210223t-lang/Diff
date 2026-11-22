#pragma once

#include "../diff_config.h"


char*
locate_elem ( diff_man* man, char type );

int
free_mmu ( diff_man* data );

int 
init_mmu ( diff_man* data );