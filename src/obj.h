#ifndef OBJ_H
#define OBJ_H

#include <raylib.h>


typedef struct
{
    struct
    {
        float ratio;
        int offset;
    }x;
    struct
    {
        float ratio;
        int offset;
    }y;

}GameVector;

typedef enum 
{
    
    TYPE_FRAME,
    TYPE_BUTTON,
    TYPE_TEXT,
    TYPE_MOVABLE,
    TYPE_FIXED

}objtype;

typedef struct 
{
    
    GameVector Position,Size;
    long Id;
    long parentId;          /*-1 for none*/
    objtype type;

}CoreObj;  /*Core Materials of a physical object, rather than an ui object.*/



#endif
