#include "render.h"
#include "obj.h"



bool Process_Execute(Process *pr,Explorer *exp)
{

    GameVector v;
    Object obj;
    if(pr->id!=0 && exp->id[pr->id] !=0 && exp->arr[exp->id[pr->id]].core.type !=0)
        
    switch(pr->type)
    {

        case PROCESS_MOVE:
            v= pr->ProcessValue.Move;
            obj=exp->arr[exp->id[pr->id]];
            GameVector p=obj.core.Position;
            p= (GameVector){.x={.offset=p.x.offset + v.x.offset,.ratio= p.x.ratio + v.x.ratio},.y={.offset=p.y.offset + v.y.offset,.ratio= p.y.ratio + v.y.ratio}};
            break;
        case PROCESS_SIZE:

            v=pr->ProcessValue.Size;
            obj = exp->arr[exp->id[pr->id]];
            GameVector s= obj.core.Size;
            s=(GameVector){.x={.offset=s.x.offset + v.x.offset,.ratio=s.x.ratio + v.x.ratio},.y= {.offset = s.y.offset + v.y.offset , .ratio = s.y.ratio + v.y.ratio}};
            break;
        case PROCESS_TRANSPARENCY:
                        


            break;
         default:
   
            return false;
    
    }
    (pr->processCount)--;
    return true;
}

void ChangeTransparency(Object *obj,float val)
{
    switch(obj->core.type)

    {
        case TYPE_FIXED:
            obj->extra.fixed.Transparency -=val;
            break;
        case TYPE_FRAME:
            
            obj->extra.frame.BackgroundTransparency -=val;
            break;
        case TYPE_MOVABLE:
            obj->extra.movable.Transparency -=val;
            break;
        default:
            return;


    }

    return;
}
