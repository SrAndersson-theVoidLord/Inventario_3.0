#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED



///[LNG 2023-06-11] -Defines arrow keys:

#define Color_Red 12
#define Color_Def 15
#define Color_Yellow 14
#define Color_Green 10
#define Delay_us 0
#define Cursor 16
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
#define Max_Chars 12

/* [LNG 2023-06-11] - Struct definition */
struct Article_Struct
{
    char Name[Max_Chars];
    float Price;
    float Cost;
    int Pieces;
    float Value;
};


#endif // STRUCTS_H_INCLUDED
