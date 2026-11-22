#pragma once

#include <cstddef>
#include <stdlib.h>

//----------mmu presets-------------
const size_t ZONE_MAX_QUANTITY = 20;
const size_t MMU_INIT_QUANTITY = 1;
//----------------------------------

enum
DIFF_ERROR
{
    Success_Diff = 0,
    Failure_Diff = -1,
};


struct
zone
{
    char* data;
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
    zone_man konst;
    zone_man opera;
    zone_man varia;
    bool      stat;
};

struct
node
{
    char*  data;
    int    type;
    node*  left;
    node* right;
};

struct
tree_diff
{
    node* top;
    size_t quantity;
    mmu diff_mmu;
};

struct
diff_man
{
    tree_diff func;


};
