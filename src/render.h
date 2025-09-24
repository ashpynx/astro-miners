#ifndef RENDER_H
#define RENDER_H

#include "obj.h"
#include <raylib.h>

typedef enum
{

    PROCESS_MOVE,
    PROCESS_SIZE,
    PROCESS_TRANSPARENCY            /*WARNING!Transparency change over time is limited ony to fixed,movable and frame.*/

}ProcessType;


/*Will Remake Process Stuff...*/



typedef struct

{


    union {
        GameVector Size,Move;
        float Transparency;
    }ProcessValue;
    long id;
    ProcessType type;
    int processCount;

}Process;

bool Process_Execute(Process *pr,Explorer *exp);


#endif
