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

bool Object_Delete(Explorer *exp,long id)
{
    if(exp->id[id] != 0 && exp->arr[exp->id[id]].core.type != TYPE_NONE)
        exp->arr[exp->id[id]].core.type= TYPE_NONE;
    else 
    return false;
    return true;
}

objtype Object_GetType(Explorer *exp,long id)
{
    if(exp->id[id]!=0)
        return exp->arr[exp->id[id]].core.type;


    return TYPE_NONE;

}
