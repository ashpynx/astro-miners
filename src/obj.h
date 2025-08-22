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


#endif
