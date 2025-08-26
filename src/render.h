#ifndef RENDER_H
#define RENDER_H

#include "obj.h"

typedef enum
{

    PROCESS_MOVE,
    PROCESS_SIZE,
    PROCESS_TRANSPARENCY

}ProcessType;


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
