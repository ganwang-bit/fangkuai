#include"head.h"
int fangarr[HEIGHT][WIDTH/2]={0};
fang fn[5][4]={{{STARTX,STARTY,0,1,0,2,1,1},{STARTX,STARTY,1,0,-1,0,0,1},{STARTX,STARTY,0,1,0,2,-1,1},{STARTX,STARTY,0,1,1,1,-1,1}},
               {{STARTX,STARTY,-1,0,0,1,1,1},{STARTX,STARTY,0,1,-1,1,-1,2},{STARTX,STARTY,-1,0,0,1,1,1},{STARTX,STARTY,0,1,-1,1,-1,2}},
               {{STARTX,STARTY,-1,0,0,1,-1,1},{STARTX,STARTY,-1,0,0,1,-1,1},{STARTX,STARTY,-1,0,0,1,-1,1},{STARTX,STARTY,-1,0,0,1,-1,1}},
               {{STARTX,STARTY,0,1,0,2,0,3},{STARTX,STARTY,-2,0,-1,0,1,0},{STARTX,STARTY,0,1,0,2,0,3},{STARTX,STARTY,-2,0,-1,0,1,0}},
               {{STARTX,STARTY,0,1,-1,1,-2,1},{STARTX,STARTY,0,1,0,2,1,2},{STARTX,STARTY,1,0,-1,0,-1,1},{STARTX,STARTY,-1,0,0,1,0,2}}};
fang fangtmp;
ffang flag_tmp={0,0,0,0,0};
void initst(st*p)
{
    srand((unsigned)time(NULL));
    p->curi=rand()%5;
    p->curj=rand()%4;
    p->leval=1;
    p->nexti=rand()%5;
    p->nextj=rand()%4;
    p->score=0;
    p->speed=300;
    fangtmp=fn[p->curi][p->curj];
}
void color(int n)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),n);
}
void gotoxy(int x,int y)
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void menu()
{
    int i;
    color(15);
    gotoxy(45,2);
    printf("Ȥ ζ �� �� ˹ �� ��\n");
    color(F1);
    gotoxy(37,4);
    printf("��");
    gotoxy(37,5);
    printf("����");
    gotoxy(37,6);
    printf("��");
    color(F2);
    gotoxy(45,5);
    printf("����");
    gotoxy(47,6);
    printf("����");
    color(F3);
    gotoxy(55,5);
    printf("����");
    gotoxy(55,6);
    printf("����");
    color(F4);
    gotoxy(63,4);
    printf("��");
    gotoxy(63,5);
    printf("��");
    gotoxy(63,6);
    printf("��");
    gotoxy(63,7);
    printf("��");
    color(F5);
    gotoxy(73,5);
    printf("��");
    gotoxy(69,6);
    printf("������");
    color(14);
    gotoxy(27,9);
    printf("======================================================");
    for(i=10;i<22;i++)
    {
        gotoxy(26,i);
        printf("��                                                    ��");
    }
    gotoxy(27,22);
    printf("======================================================");
    gotoxy(37,13);
    color(4);
    printf("[1]��ʼ��Ϸ          [2]����˵��");
    gotoxy(37,17);
    printf("[3]��Ϸ����          [4]�˳�����");
    gotoxy(42,24);
    color(1);
    printf("��ѡ��[1 2 3 4]:[ ]");
    gotoxy(59,24);
}
int choose()
{
    int tmp;
    while((tmp=getch()))
    {
        if(tmp=='1')
        {
            printf("1");
            Sleep(1000);
            return 1;
        }
        else if(tmp=='2')
        {
            printf("2");
            Sleep(1000);
            return 2;
        }
        else if(tmp=='3')
        {
            printf("3");
            Sleep(1000);
            return 3;
        }
        else if(tmp=='4')
        {
            printf("4");
            Sleep(1000);
            return 4;
        }
        else
        {
            gotoxy(40,25);
            color(12);
            printf("��ʾ:������1-4֮�������");
            color(1);
            gotoxy(59,24);
        }
    }
}
void anjian()
{
    int i;
    color(13);
    gotoxy(49,4);
    printf("����˵��");
    color(14);
    gotoxy(27,6);
    printf("======================================================");
    for(i=7;i<19;i++)
    {
        gotoxy(26,i);
        printf("��                                                    ��");
    }
    gotoxy(27,19);
    printf("======================================================");
    color(9);
    gotoxy(29,8);
    printf("tip1����ҿ���ͨ��������������ƶ�����");
    color(11);
    gotoxy(29,10);
    printf("tip2����ҿ���ͨ����ʹ������ת");
    color(14);
    gotoxy(29,12);
    printf("tip3����ҿ���ͨ�������ٷ�������");
    color(10);
    gotoxy(29,14);
    printf("tip4�����ո����ͣ��Ϸ���ٰ��ո������");
    color(12);
    gotoxy(29,16);
    printf("tip5����ESC���˳���Ϸ");
    color(7);
    gotoxy(29,20);
    printf("�������������һ����");
    getch();
}
void guize()
{
    int i;
    color(13);
    gotoxy(49,4);
    printf("����˵��");
    color(14);
    gotoxy(27,6);
    printf("======================================================");
    for(i=7;i<20;i++)
    {
        gotoxy(26,i);
        printf("��                                                    ��");
    }
    gotoxy(27,20);
    printf("======================================================");
    color(12);
    gotoxy(29,8);
    printf("tip1����ͬ��״��С�������Ļ�Ϸ����䣬���ͨ������");
    gotoxy(35,10);
    printf("�����λ�úͷ�����������Ļ�ײ�ƴ��������һ");
    gotoxy(35,12);
    printf("�л���");
    color(9);
    gotoxy(29,14);
    printf("tip2��ÿ����һ�У���������100");
    color(13);
    gotoxy(29,16);
    printf("tip3��ÿ�ۼ�1000�֣�������һ���ȼ�");
    color(10);
    gotoxy(29,18);
    printf("tip4�������ȼ���ʹ���������ٶȼӿ죬��Ϸ�ѶȼӴ�");
    color(7);
    gotoxy(29,21);
    printf("�������������һ����");
    getch();
}
void game()
{

    st jilu;
    int changtmpx,changtmpy,changtmp;
    initst(&jilu);
    gamemenu();
    int i,j;
    while(1)
    {
        xiao(&jilu);
        if(flag_tmp.again_flag)
        {
            system("cls");
            gamemenu();
            initst(&jilu);
            for(i=0;i<HEIGHT;i++)
                for(j=0;j<WIDTH/2;j++)
                    fangarr[i][j]=0;
            flag_tmp.next=0;
            flag_tmp.again_flag=0;
            flag_tmp.f_flag=0;
            flag_tmp.space_flag=0;
            flag_tmp.up_flag=0;
        }
        if(jilu.score>=jilu.leval*1000)
        {
            jilu.leval++;
            jilu.speed=jilu.speed/2+1;
        }
        draw(&jilu);
        show(&jilu);
        if(flag_tmp.space_flag)
        {
            color(7);
            gotoxy(16+WIDTH,20);
            printf("����ո����");
            while(1)
            {
                if(getch()==32)
                    break;
            }
            gotoxy(16+WIDTH,20);
            printf("            ");
            flag_tmp.space_flag=0;
        }
        Sleep(jilu.speed);
        if(!flag_tmp.next)
            del();
        else
        {
            if(pan())
            {
                system("cls");
                endmenu();
                if(endchoose())
                {
                    break;
                }
                else
                {
                    flag_tmp.again_flag=1;
                    continue;
                }
                system("cls");
            }
            changenext(&jilu);
            continue;
        }
        fmove();
        if(flag_tmp.up_flag)
        {
            changtmp=jilu.curj;
            jilu.curj=(jilu.curj+1)%4;
            changtmpx=fangtmp.mfx;
            changtmpy=fangtmp.mfy;
            fangtmp=fn[jilu.curi][jilu.curj];
            fangtmp.mfx=changtmpx;
            fangtmp.mfy=changtmpy;
            if(fangtmp.mfy>HEIGHT-1||fangtmp.mfy+fangtmp.fy2>HEIGHT-1||fangtmp.mfy+fangtmp.fy3>HEIGHT-1||fangtmp.mfy+fangtmp.fy4>HEIGHT-1)
            {
                jilu.curj=changtmp;
                fangtmp=fn[jilu.curi][jilu.curj];
                fangtmp.mfx=changtmpx;
                fangtmp.mfy=changtmpy;
                flag_tmp.up_flag=0;
                continue;
            }
            if(fangarr[fangtmp.mfy][fangtmp.mfx]||fangarr[fangtmp.mfy+fangtmp.fy2][fangtmp.mfx+fangtmp.fx2]
               ||fangarr[fangtmp.mfy+fangtmp.fy3][fangtmp.mfx+fangtmp.fx3]||fangarr[fangtmp.mfy+fangtmp.fy4][fangtmp.mfx+fangtmp.fx4])
            {
                jilu.curj=changtmp;
                fangtmp=fn[jilu.curi][jilu.curj];
                fangtmp.mfx=changtmpx;
                fangtmp.mfy=changtmpy;
                flag_tmp.up_flag=0;
                continue;
            }
            while(fangtmp.mfx>WIDTH/2-1||(fangtmp.fx2+fangtmp.mfx>WIDTH/2-1)||(fangtmp.fx3+fangtmp.mfx>WIDTH/2-1)||(fangtmp.fx4+fangtmp.mfx>WIDTH/2-1))
                fangtmp.mfx--;
            while(fangtmp.mfx<0||(fangtmp.fx2+fangtmp.mfx<0)||(fangtmp.fx3+fangtmp.mfx<0)||(fangtmp.fx4+fangtmp.mfx<0))
                fangtmp.mfx++;
            flag_tmp.up_flag=0;
        }
    }
}
void gamemenu()
{
    int i;
    color(1);
    gotoxy(25,2);
    printf("Ȥζ����˹����");
    gotoxy(10,4);
    color(12);
    printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");//��������������
    for(i=0;i<HEIGHT;i++)
    {
        gotoxy(10,i+5);
        printf("�U                                         �U");
    }
    gotoxy(10,30);
    printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
    color(10);
    gotoxy(16+WIDTH,8);
    printf("�T�T�T�T�T�T�T�T�T�T");
    color(11);
    printf(" ��һ���ַ���");
    color(10);
    gotoxy(16+WIDTH,14);
    printf("�T�T�T�T�T�T�T�T�T�T");
    color(12);
}
void show(st*p)
{
    int k,l;
    color(12);
    gotoxy(16+WIDTH,5);
    printf("�ȼ���%d",p->leval);
    gotoxy(16+WIDTH,6);
    printf("������%d",p->score);
    gotoxy(16+WIDTH,7);
    printf("�ٶȣ�%dms",p->speed);
    for(k=0;k<HEIGHT;k++)
    {
        for(l=0;l<WIDTH/2;l++)
            if(fangarr[k][l])
            {
                color(fangarr[k][l]);
                gotoxy(12+l*2,5+k);
                printf("��");
            }
    }
    gotoxy(16+WIDTH,9);
    for(k=0;k<4;k++)
    {
        printf("          ");
        gotoxy(16+WIDTH,10+k);
    }
    switch(p->nexti)
    {
    case 0:
        color(F1);
        break;
    case 1:
        color(F2);
        break;
    case 2:
        color(F3);
        break;
    case 3:
        color(F4);
        break;
    case 4:
        color(F5);
        break;
    }
    gotoxy(20+WIDTH,9);
    printf("��");
    gotoxy((fn[p->nexti][p->nextj].fx2)*2+20+WIDTH,9+fn[p->nexti][p->nextj].fy2);
    printf("��");
    gotoxy((fn[p->nexti][p->nextj].fx3)*2+20+WIDTH,9+fn[p->nexti][p->nextj].fy3);
    printf("��");
    gotoxy((fn[p->nexti][p->nextj].fx4)*2+20+WIDTH,9+fn[p->nexti][p->nextj].fy4);
    printf("��");
}
void draw(st*tmp)
{
    fangarr[fangtmp.mfy][fangtmp.mfx]=F(tmp->curi);
    fangarr[fangtmp.mfy+fangtmp.fy2][fangtmp.mfx+fangtmp.fx2]=F(tmp->curi);
    fangarr[fangtmp.mfy+fangtmp.fy3][fangtmp.mfx+fangtmp.fx3]=F(tmp->curi);
    fangarr[fangtmp.mfy+fangtmp.fy4][fangtmp.mfx+fangtmp.fx4]=F(tmp->curi);
}
void del()
{
    int k,l;
    for(k=0;k<HEIGHT;k++)
    {
        for(l=0;l<WIDTH/2;l++)
            if(fangarr[k][l])
            {
                color(fangarr[k][l]);
                gotoxy(12+l*2,5+k);
                printf("  ");
            }
    }
    fangarr[fangtmp.mfy][fangtmp.mfx]=0;
    fangarr[fangtmp.mfy+fangtmp.fy2][fangtmp.mfx+fangtmp.fx2]=0;
    fangarr[fangtmp.mfy+fangtmp.fy3][fangtmp.mfx+fangtmp.fx3]=0;
    fangarr[fangtmp.mfy+fangtmp.fy4][fangtmp.mfx+fangtmp.fx4]=0;

}
void fmove()
{
    int tmp;
    if(kbhit())
    {
        tmp=getch();
        if(tmp==32)
        {
            flag_tmp.space_flag=1;
        }
        else if(tmp==27)
        {
            system("cls");
            exit(0);
        }
        else if(tmp==224)
        {
            tmp=getch();
            if(tmp==77&&(fangtmp.mfx!=WIDTH/2-1)&&(fangtmp.fx2+fangtmp.mfx!=WIDTH/2-1)&&(fangtmp.fx3+fangtmp.mfx!=WIDTH/2-1)&&(fangtmp.fx4+fangtmp.mfx!=WIDTH/2-1)&&
               !fangarr[fangtmp.mfy][fangtmp.mfx+1]&&!fangarr[fangtmp.mfy+fangtmp.fy2][fangtmp.fx2+fangtmp.mfx+1]&&!fangarr[fangtmp.mfy+fangtmp.fy3][fangtmp.fx3+fangtmp.mfx+1]
               &&!fangarr[fangtmp.mfy+fangtmp.fy4][fangtmp.fx4+fangtmp.mfx+1])
            {
                fangtmp.mfx++;
                flag_tmp.f_flag=1;
            }
            else if(tmp==75&&fangtmp.mfx!=0&&(fangtmp.fx2+fangtmp.mfx!=0)&&(fangtmp.fx3+fangtmp.mfx!=0)&&(fangtmp.fx4+fangtmp.mfx!=0)&&
                    !fangarr[fangtmp.mfy][fangtmp.mfx-1]&&!fangarr[fangtmp.mfy+fangtmp.fy2][fangtmp.fx2+fangtmp.mfx-1]&&!fangarr[fangtmp.mfy+fangtmp.fy3][fangtmp.fx3+fangtmp.mfx-1]
               &&!fangarr[fangtmp.mfy+fangtmp.fy4][fangtmp.fx4+fangtmp.mfx-1])
            {
                fangtmp.mfx--;
                flag_tmp.f_flag=1;
            }
            else if(tmp==80&&fangtmp.mfy!=HEIGHT-1&&fangtmp.mfy+fangtmp.fy2!=HEIGHT-1&&fangtmp.mfy+fangtmp.fy3!=HEIGHT-1&&fangtmp.mfy+fangtmp.fy4!=HEIGHT-1
           &&!fangarr[fangtmp.mfy+1][fangtmp.mfx]&&!fangarr[fangtmp.mfy+fangtmp.fy2+1][fangtmp.mfx+fangtmp.fx2]
           &&!fangarr[fangtmp.mfy+fangtmp.fy3+1][fangtmp.mfx+fangtmp.fx3]&&!fangarr[fangtmp.mfy+fangtmp.fy4+1][fangtmp.mfx+fangtmp.fx4]
           &&fangtmp.mfy+2<=HEIGHT-1&&(fangtmp.mfy+fangtmp.fy2+2)<=HEIGHT-1&&(fangtmp.mfy+fangtmp.fy3+2)<=HEIGHT-1&&(fangtmp.mfy+fangtmp.fy4+2)<=HEIGHT-1
           &&!fangarr[fangtmp.mfy+3][fangtmp.mfx]&&!fangarr[fangtmp.mfy+fangtmp.fy2+3][fangtmp.mfx+fangtmp.fx2]
           &&!fangarr[fangtmp.mfy+fangtmp.fy3+3][fangtmp.mfx+fangtmp.fx3]&&!fangarr[fangtmp.mfy+fangtmp.fy4+3][fangtmp.mfx+fangtmp.fx4])
            {
                fangtmp.mfy+=2;
                flag_tmp.f_flag=1;
            }
            else if(tmp==72&&fangtmp.mfy!=HEIGHT-1&&fangtmp.mfy+fangtmp.fy2!=HEIGHT-1&&fangtmp.mfy+fangtmp.fy3!=HEIGHT-1&&fangtmp.mfy+fangtmp.fy4!=HEIGHT-1
           &&!fangarr[fangtmp.mfy+1][fangtmp.mfx]&&!fangarr[fangtmp.mfy+fangtmp.fy2+1][fangtmp.mfx+fangtmp.fx2]
           &&!fangarr[fangtmp.mfy+fangtmp.fy3+1][fangtmp.mfx+fangtmp.fx3]&&!fangarr[fangtmp.mfy+fangtmp.fy4+1][fangtmp.mfx+fangtmp.fx4])
            {
                flag_tmp.up_flag=1;
                flag_tmp.f_flag=1;
                fangtmp.mfy++;
            }
            else if(fangtmp.mfy!=HEIGHT-1&&fangtmp.mfy+fangtmp.fy2!=HEIGHT-1&&fangtmp.mfy+fangtmp.fy3!=HEIGHT-1&&fangtmp.mfy+fangtmp.fy4!=HEIGHT-1
           &&!fangarr[fangtmp.mfy+1][fangtmp.mfx]&&!fangarr[fangtmp.mfy+fangtmp.fy2+1][fangtmp.mfx+fangtmp.fx2]
           &&!fangarr[fangtmp.mfy+fangtmp.fy3+1][fangtmp.mfx+fangtmp.fx3]&&!fangarr[fangtmp.mfy+fangtmp.fy4+1][fangtmp.mfx+fangtmp.fx4])
               fangtmp.mfy++;
        }
    }
    else if(fangtmp.mfy==HEIGHT-1||fangtmp.mfy+fangtmp.fy2==HEIGHT-1||fangtmp.mfy+fangtmp.fy3==HEIGHT-1||fangtmp.mfy+fangtmp.fy4==HEIGHT-1
       ||fangarr[fangtmp.mfy+1][fangtmp.mfx]||fangarr[fangtmp.mfy+fangtmp.fy2+1][fangtmp.mfx+fangtmp.fx2]
       ||fangarr[fangtmp.mfy+fangtmp.fy3+1][fangtmp.mfx+fangtmp.fx3]||fangarr[fangtmp.mfy+fangtmp.fy4+1][fangtmp.mfx+fangtmp.fx4])
    {
        flag_tmp.next=1;
    }
    else
        fangtmp.mfy++;
    if(flag_tmp.f_flag)
        while(kbhit())
            getch();
}
void changenext(st*p)
{
    srand((unsigned int)time(NULL));
    fangtmp=fn[p->nexti][p->nextj];
    flag_tmp.next=0;
    p->curi=p->nexti;
    p->curj=p->nextj;
    p->nexti=rand()%5;
    p->nextj=rand()%4;
}
int F(int i)
{
    switch(i)
    {
    case 0:
        return F1;
    case 1:
        return F2;
    case 2:
        return F3;
    case 3:
        return F4;
    case 4:
        return F5;
    }
}
void xiao(st*p)
{
    int i,j,k;
    for(i=1;i<HEIGHT;i++)
    {
        for(j=0;j<WIDTH/2;j++)
            if(!fangarr[i][j])
                break;
        if(j==WIDTH/2)
        {
            for(k=i;k>0;k--)
                for(j=0;j<WIDTH/2;j++)
                {
                    fangarr[k][j]=fangarr[k-1][j];
                }
            for(k=0;k<HEIGHT;k++)
            {
                gotoxy(12,5+k);
                printf("                                        ");
            }
            p->score+=100;
        }
    }
}
int pan()
{
    int i;
    for(i=0;i<WIDTH/2;i++)
    {
        if(fangarr[0][i])
            break;
    }
    if(i!=WIDTH/2)
    {
        return 1;
    }
    else
        return 0;
}
void endmenu()
{
    int x=42,y=8,tmp;
    color(12);
    gotoxy(x,y);
    printf("��������    ��      ��    ����");
    gotoxy(x,y+1);
    printf("��          ����    ��    ��  ��");
    gotoxy(x,y+2);
    printf("������      ��  ��  ��    ��   ��");
    gotoxy(x,y+3);
    printf("��          ��    ����    ��  ��");
    gotoxy(x,y+4);
    printf("��������    ��      ��    ����");
    gotoxy(x-10,y+8);
    printf("[1]---���¿�ʼ                          [2]---�˳���Ϸ");
    gotoxy(x+10,y+10);
    printf("ѡ��[1/2]:");
    gotoxy(x+20,y+10);
}
int endchoose()
{
    int tmp;
    while((tmp=getch()))
    {
        if(tmp=='1')
        {
            gotoxy(62,18);
            printf("1");
            return 0;
        }
        else if(tmp=='2')
        {
            gotoxy(62,18);
            printf("2");
            return 1;
        }
        else
        {
            gotoxy(52,20);
            printf("��ʾ:������1��2");
            gotoxy(62,18);
        }
    }
    Sleep(1000);
}
