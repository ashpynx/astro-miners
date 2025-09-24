#include <raylib.h>
#include <stdio.h>
#include "main.h"



int main(void)
{
    
    Camera2D cam;
    InitWindow(960,960,"Test");
    Explorer b;

    printf("\nHello!%p\n",Obj_Create(TYPE_PLANET,&b));
    printf("\n%p\n",Obj_Create(TYPE_FRAME,&b));
    printf("\n%p\n",Obj_Create(TYPE_NONE,&b));
    while(!WindowShouldClose())
    {
        BeginDrawing(); 
        DrawRectangle(480, 480, 500, 400, RED);
        EndDrawing();


    }



    return 0;
}
