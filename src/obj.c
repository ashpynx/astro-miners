#include "obj.h"

bool Object_Create(Explorer *exp,objtype type)
{
    for(int i=0;i<OBJ_COUNT;i++)
        if(exp->arr[i].core.type == TYPE_NONE)
            exp->id[exp->itop]=i+1;
    if(exp->id[exp->itop]==0)
        return false;
    exp->arr[exp->otop].core.type=type;
    exp->otop++;
    exp->itop++;


    return true;
}



