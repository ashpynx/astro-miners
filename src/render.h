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

    float ProcessValue;
    long id;
    ProcessType type;


}Process;

bool Process_Execute();


#endif
