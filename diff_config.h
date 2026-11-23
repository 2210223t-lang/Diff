#pragma once

#include <cstddef>
#include <stdlib.h>

//----------mmu presets-------------
const size_t ZONE_MAX_QUANTITY = 20;
const size_t MMU_INIT_QUANTITY = 1;
//----------------------------------

//-------------default sizes-------------
const size_t VARIABLE_ELEM_BYTESIZE  = 4;
const size_t OPERATION_ELEM_BYTESIZE = 1; 
const size_t CONST_ELEM_BYTESIZE     = 8;
//---------------------------------------

//--------Type's codes--------
const char VARIABLE_CODE  = 1;
const char OPERATION_CODE = 2;
const char CONST_CODE     = 3;
//----------------------------

//-----------Global const------------
const size_t MAX_OPERATOR_LENGTH = 5;
//-----------------------------------


enum
DIFF_ERROR
{
    Success_Diff = 0,
    Failure_Diff = -1,
};


union
diff_elem
{
    int opera;
    int varia;
    int konst;
};

struct
node
{
    diff_elem  data;
    int    type;
    node*  left;
    node* right;
};

struct
zone
{
    node* data;
    size_t quantity;
};

struct
zone_man
{
    zone* zones;
    size_t quantity;
};

struct 
mmu
{
    zone_man zone;
    bool     stat;
};

struct
tree_diff
{
    node* top;
    size_t quantity;
};

struct
diff_man
{
    tree_diff func;
    mmu diff_mmu;
    bool status;


};
