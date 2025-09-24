#include "obj.h"
#include <stdio.h>



Object * Obj_Create(objtype type,Explorer *exp)
{

    if(type == TYPE_BUTTON || type == TYPE_FRAME || type == TYPE_TEXT)
    {
        for(int u = 0;u<UI_COUNT;u++)
        {
            if(exp->UI[u].core.type == TYPE_NONE)
            {
                exp->UI[u].core.type = type;
                return &(exp->UI[u]);

            }

        }

    }
    else if(type != TYPE_NONE) 
    {

        for(int i=0;i<OBJ_COUNT;i++)
        {
            if(exp->obj[i].core.type == TYPE_NONE)
            {
                exp->obj[i].core.type = type;
                return &(exp->obj[i]);

            }

        }

    }
    else if(type == TYPE_NONE)
    {
        perror("\nCANNOT CREATE OBJECT WITH NO TYPE(obj.c->Obj_Create)\n");
    }
    return NULL;
}
