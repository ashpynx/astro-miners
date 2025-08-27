#ifndef OBJ_H
#define OBJ_H

#define OBJ_COUNT 1024 

#include <raylib.h>
#include "ui.h"
#include "player.h"
#include "enemy.h"

typedef struct
{
    struct
    {
        float ratio;
        int offset;
    }x;
    struct
    {
        float ratio;
        int offset;
    }y;

}GameVector;

typedef enum 
{
    TYPE_NONE =0, 
    TYPE_FRAME,
    TYPE_BUTTON,
    TYPE_TEXT,
    TYPE_MOVABLE,
    TYPE_FIXED,
    TYPE_PLAYER

}objtype;

struct FrameExtra
{

    Color BackroundColor; 
    short BackgroundTransparency;
};

struct ButtonExtra 
{
    Color BackgroundColor;
    short BackGroundTransparency;
    short TextTransparency;
    Color TextColor;
    char *text;

};

struct TextExtra 
{
    Color TextColor;
    short TextTransparency;
    char *text;
};

struct MovableExtra
{
    GameVector Speed;
    bool cancollide;
    short Transparency;

};

struct FixedExtra
{
    
    bool cancollide;
    short Transparency;
};


struct PlayerExtra
{

   PlayerState state;
   int hp;
   long coin;
   GameVector Speed;

};

typedef union
{
    struct FrameExtra frame;
    struct ButtonExtra button;
    struct TextExtra text;
    struct MovableExtra movable;
    struct FixedExtra fixed;
    struct PlayerExtra player;
}ObjExtras;

typedef struct 
{
    
    GameVector Position,Size;

    objtype type;

}CoreObj;  /*Core Materials of a physical object*/

typedef struct 
{
    
    CoreObj core;
    ObjExtras extra;


}Object;        /*combining both core and the type's own properties resulting in a whole object */

typedef struct 
{

    Object arr[OBJ_COUNT];
    long id[OBJ_COUNT];
    long parentid[OBJ_COUNT];
    int otop;   /*total for arr[]*/
    int itop;   /*top for id[]*/
}Explorer;

bool Object_Create(Explorer *exp,objtype type);

#endif
