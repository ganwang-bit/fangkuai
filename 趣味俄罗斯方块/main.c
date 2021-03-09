#include"head.h"
int main()
{
    int choice,again=1;
    while(again)
    {
        menu();
        choice=choose();
        switch(choice)
        {
        case 1:
            system("cls");
            game();
            system("cls");
            break;
        case 2:
            system("cls");
            anjian();
            system("cls");
            break;
        case 3:
            system("cls");
            guize();
            system("cls");
            break;
        case 4:
            again=0;
            break;
        }
    }
    return 0;
}
