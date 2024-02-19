#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int menu(void)
{
    system("cls");
    char ch;
    HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
    draw_box();
    int pos=1;
    ShowConsoleCursor(0);
    do
    {
        SetConsoleTextAttribute(console,15);
        gotoxy(40,11);
        printf(" 1] New Game                    ");
        gotoxy(40,12);
        printf(" 2] Load Game                   ");
        gotoxy(40,13);
        printf(" 3] Top Scores                  ");
        gotoxy(40,14);
        printf(" 4] Exit                        ");
        switch(pos)
        {
        case 1:
            SetConsoleTextAttribute(console,241);
            gotoxy(40,11);
            printf(" 1] New Game                    ");
            break;
        case 2:
            SetConsoleTextAttribute(console,241);
            gotoxy(40,12);
            printf(" 2] Load Game                   ");
            break;
        case 3:
            SetConsoleTextAttribute(console,241);
            gotoxy(40,13);
            printf(" 3] Top Scores                  ");
            break;
        case 4:
            SetConsoleTextAttribute(console,244);
            gotoxy(40,14);
            printf(" 4] Exit                        ");
            break;
        }
        ch=getch();
        if(ch==-32)ch=getch();
        if(ch==72)
        {
            pos--;
            if(pos==0)pos=4;
        }
        if(ch==80)
        {
            pos++;
            if(pos==5)pos=1;
        }

    }
    while(ch!=13);
    SetConsoleTextAttribute(console,15);
    printf("\n \n \n \n");
    return pos;
}
void gotoxy(int x, int y)
{
    COORD coord= {0,0};
    coord.X= x;
    coord.Y=y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void draw_box(void)
{
    gotoxy (39,10);
    printf("%c",201);
    for(int i=1 ; i<33; i++)printf("%c",205);
    printf("%c",187);
    gotoxy(39,11);
    printf("%c",186);
    for(int i=1 ; i<33; i++)printf("%c",32);
    printf("%c",186);
    gotoxy(39,12);
    printf("%c",186);
    for(int i=1 ; i<33; i++)printf("%c",32);
    printf("%c",186);
    gotoxy(39,13);
    printf("%c",186);
    for(int i=1 ; i<33; i++)printf("%c",32);
    printf("%c",186);
    gotoxy(39,14);
    printf("%c",186);
    for(int i=1 ; i<33; i++)printf("%c",32);
    printf("%c",186);
    gotoxy(39,15);
    printf("%c",200);
    for(int i=1 ; i<33; i++)printf("%c",205);
    printf("%c",188);
}
void ShowConsoleCursor(int showFlag)
{
    HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorinfo;
    GetConsoleCursorInfo(out,&cursorinfo);
    cursorinfo. bVisible=showFlag;
    SetConsoleCursorInfo(out,&cursorinfo);
}

#endif // MENU_H_INCLUDED
