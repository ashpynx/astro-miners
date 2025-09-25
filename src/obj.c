#include "obj.h"
#include <math.h>
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
                for(int a =0; a<OBJ_COUNT;a++)
                {
                    if(exp->objid[a] == 0)
                    {
                        exp->objid[a] = i+1;
                        exp->obj[i].core.id = a;
                        break;
                    }

                }
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

/*include error messages*/
bool Obj_Remove(long id,Explorer *exp)
{
    if(exp->obj[exp->objid[id]-1].core.type != TYPE_NONE && id == exp->obj[exp->objid[id]-1].core.id)
    {
        exp->obj[exp->objid[id]-1].core.type = TYPE_NONE;
        exp->obj[exp->objid[id]-1].core.id = -1;

        exp->objid[id] =0;
        return true; 
    }
    
    return false;
}
