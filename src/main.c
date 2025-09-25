#include <raylib.h>
#include <stdio.h>
#include "main.h"



int main(void)
{
    
    Camera2D cam;
    InitWindow(960,960,"Test");
    Explorer b;
    b.objid[0] = 0;
    Object * ptr;
    ptr =   Obj_Create(TYPE_PLAYER,&b); 
    printf("\nPtr : %p\t",ptr);

    printf("Id:%ld,%ld\n",ptr->core.id,b.objid[9]);

    if(Obj_Remove(ptr->core.id,&b))
    {
        printf("Removed Obj successfully...\n");
    }
        
    while(!WindowShouldClose())
    {
        BeginDrawing();
        DrawRectangle(480, 480, 500, 400, RED);
        EndDrawing();


    }



    return 0;
}
