#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define F1 11  //??????ɫ
#define F2 14  //??ɫ
#define F3 10  //????ɫ
#define F4 5  //??ɫ
#define F5 12  //??ɫ
#define WIDTH 40
#define HEIGHT 25
#define STARTX 10
#define STARTY 0
typedef struct fangkuai
{
    int mfx;
    int mfy;
    int fx2;
    int fy2;
    int fx3;
    int fy3;
    int fx4;
    int fy4;
}fang;
typedef struct setting
{
    int curi;
    int curj;
    int nexti;
    int nextj;
    int score;
    int speed;
    int leval;
}st;
typedef struct flag_fang
{
    int up_flag;
    int space_flag;
    int f_flag;
    int again_flag;
    int next;
}ffang;
void color(int n);
void gotoxy(int x,int y);
void menu();
int choose();
void anjian();
void guize();
void game();
void gamemenu();
void show(st*p);
void initst(st*p);
void draw(st*tmp);
void del();
void fmove();
void changenext(st*p);
int F(int n);
void xiao(st*p);
int pan();
void endmenu();
int endchoose();
#endif // HEAD_H_INCLUDED
