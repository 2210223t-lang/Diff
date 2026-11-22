#pragma once

#include <limits.h>
#include "colours.h"

const char logger_name[ PATH_MAX ] = "log.html";


#define printdb( sentence ) printlg( ERROR_DIFF_STYLE sentence " %s:%d\n" ERROR_DIFF_END, __FILE__, __LINE__ );\
                            fprintf( stderr, HCYN sentence " %s:%d\n" reset, __FILE__, __LINE__ );

int
logger_open ( void );

void
printlg ( const char* text, ... );

void
logger_close ( void );

void
putslg_debug ( const char* a );