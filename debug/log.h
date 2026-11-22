#pragma once

#include <limits.h>

const char logger_name[ PATH_MAX ] = "log.html";


#define printlgb( sentence ) printlg( sentence "%s:%d\n", __FILE__, __LINE__ );

int
logger_open ();

void
printlg ( const char* text, ... );

void
logger_close ( void );

void
putslg_debug ( const char* a );