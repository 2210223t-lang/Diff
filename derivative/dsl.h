#pragma once

#define __CR curr->right
#define __CL curr->left
#define __DR get_diff( man, curr->right )
#define __DL get_diff( man,  curr->left )
#define __ONE NewNode( man, CONST_CODE, 1, 0, 0 )

#define __CONST NewNode( man, CONST_CODE, value, 0, 0 )
#define __VARIA NewNode( man, CONST_CODE,     1, 0, 0 )

#define __ADD( left, right ) NewNode( man, OPERATION_CODE, '+', left, right )
#define __MUL( left, right ) NewNode( man, OPERATION_CODE, '*', left, right )
#define __SUB( left, right ) NewNode( man, OPERATION_CODE, '-', left, right )
#define __DIV( left, right ) NewNode( man, OPERATION_CODE, '/', left, right )
#define __POW( left, right ) NewNode( man, OPERATION_CODE, '^', left, right )
#define __LN( left )  NewNode( man, OPERATION_CODE, 'l', left,     0 )