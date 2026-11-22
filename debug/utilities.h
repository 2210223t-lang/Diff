#pragma once

#include <string.h>

#include "log.h"


#define checki( condition, sentence ) if ( !condition && !strcmp( sentence, "ignore_diff" ) ) {\
                                           printdb( sentence );\
                                           return Failure_Diff;\
                                        }
