#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "undoandredo.h"
#include "menu.h"
#include "score.h"
#define maxboard 1000
#define maxname 30

int xmlopentrials;
char xmlpath[50]="xmltest0.txt";
int savedgames;
int begin;
int gamemode;
int startfrom;
int timespent;
time_t first,last;
int numberoftopscore=10;
int nrows=7;
int ncolomus=9;
char board[100][100];
void gotoxy(int x, int y);
void draw_box(void);
void ShowConsoleCursor(int showFlag);
void redo(char board[][100],int pin,int nrows,int ncolomus,char sign );
//void undo(char board[][100],int pin,int nrows,int ncolomus);
int score(char board[][100],int nrows,int ncoloums,char sign);
void printboard(int pin,char sign);
int nmpofmoves(char sign);
void game1();
void game2();
void printtime(int);
void printinfo();
void emptyboard();
void savefile(int i);
void topscore(char name[],int score);
int highestscore();
void showtopscore(int numtopscore);
void sort(int a[],int j,char b[][30],int c);
void lowercase(char a[][30],int c);
int removeduplicate(int a[],int j,char b[][30],int c);
int menu(void);
void delay(int ms);
void loading();
void newgame();
void loadfile();
void endtime();
void mainmenu();
void red()
{
    printf("\033[1;31m");
}
void blue()
{
    printf("\033[0;34m");
}
void yellow()
{
    printf("\033[0;33m");
}
void bold()
{
    printf("\033[0;35m");
}
void pop()
{
    printf("\033[0;36m");
}
void reset()
{
    printf("\033[0m");
}

int main()
{
    xml();

    return 0;
}

void game1()
{
    int moves1;
    int timespent=0;
    int k=0;
    int redoo1=0;
    int redoo2=0;
    int pi=0;
    int po=0;
    int pr=0;
    int nredo=0;
    int nredo1=0;
    int pin;
    int prepin[100];
    char redooo[100];

    printboard(ncolomus+2,'x');
    printinfo();

    for(int i=startfrom; i<nrows*ncolomus; i++)
    {
        time(&first);
        short whichplayer=0;
        if(i%2==0)
        {
            whichplayer=1;
            int turn1=2;
            int trueinput1;
            while(turn1==2)
            {
                while(redoo1!=0)
                {
                    printinfo();
                    printf("!!player1's turn!!\n1-PLAY\n2-REDO\n");
                    char turn11[20];
                    fflush(stdin);
                    gets(turn11);
                    turn1=atoi(turn11);
                    if(turn1==2)
                    {
                        redo(board,prepin[pr],nrows,ncolomus,redooo[nredo1]);
                        redoo1--;
                        pr++;
                        po++;
                        nredo1++;
                    }
                    else if (turn1==1)
                    {
                        break;
                    }
                    else
                    {
                        printf("wrong choice\n");
                    }
                }

                printf("!!player1's turn!!\n1-PLAY\n2-UNDO\n3-SAVE & EXIT\n");
                char turn11[20];
                fflush(stdin);
                gets(turn11);
                turn1=atoi(turn11);
                switch (turn1)
                {
                case 1:
                    printf("choose a column\n");
                    redoo1=0;
                    turn1=3;
                    trueinput1=1;
                    while(trueinput1==1)
                    {

                        char pinn[20];
                        fflush(stdin);
                        gets(pinn);
                        pin=atoi(pinn);
                        prepin[pi]=pin;
                        po=pi;
                        pi++;
                        system("CLS");
                        if(pin>ncolomus||pin<=0)
                        {
                            printf("out of the borders !! choice again \n");
                        }
                        else
                        {
                            if(board[0][pin-1]=='x'||board[0][pin-1]=='o')
                            {
                                printf("column %d is occupied choice again player 1 \n",pin);
                            }
                            else
                            {
                                trueinput1=0;
                                printboard(pin,'x');
                                redooo[nredo]='x';
                                nredo++;
                                nredo1=nredo;
                                printinfo();
                            }
                        }
                    }
                    break;
                case 2:
                    undo( board,prepin[po],nrows,ncolomus );
                    pr=po;
                    po--;
                    redoo1++;
                    if(nredo1!=0)
                    {
                        nredo1--;
                    }
                    break;

                case 3:
                    savedgames++;
                    system("cls");
                    moves1=nmpofmoves('x');
                    int moves2=nmpofmoves('o');
                    int score1=score(board,nrows,ncolomus,'x');
                    int score2=score(board,nrows,ncolomus,'o');
                    savefile(i);
                    loading();
                    mainmenu();
                    break;

                default:
                    printf("wrong choice\n");
                    turn1=2;
                    break;
                }

            }
            endtime();

        }




        else
        {
            whichplayer=2;
            int turn2=2;
            int trueinput2;
            while(turn2==2)
            {
                while(redoo2!=0)
                {
                    printinfo();
                    printf("!!player2's turn!!\n1-PLAY\n2-REDO\n");
                    char turn22[20];
                    fflush(stdin);
                    gets(turn22);
                    turn2=atoi(turn22);
                    if(turn2==2)
                    {
                        redo(board,prepin[pr],nrows,ncolomus,redooo[nredo1]);
                        nredo1++;
                        redoo2--;
                        pr++;
                        po++;

                    }
                    else if (turn2==1||turn2==2)
                    {
                        break;
                    }
                    else
                    {
                        printf("wrong choice\n");
                    }
                }

                printf("!!player2's turn!!\n1-PLAY\n2-UNDO\n3-SAVE & EXIT\n");
                char turn22[20];
                fflush(stdin);
                gets(turn22);
                turn2=atoi(turn22);
                switch (turn2)
                {
                case 1:
                    printf("choose column\n");
                    redoo2=0;
                    turn2=3;
                    trueinput2=1;
                    while(trueinput2==1)
                    {

                        char pinn[20];
                        fflush(stdin);
                        gets(pinn);
                        pin=atoi(pinn);
                        prepin[pi]=pin;
                        po=pi;
                        pi++;
                        system("CLS");
                        if(pin>ncolomus||pin<=0)
                        {
                            printf("out of the borders !! choice again \n");
                        }
                        else
                        {
                            if(board[0][pin-1]=='x'||board[0][pin-1]=='o')
                            {
                                printf("column %d is occupied choice again player 2 \n",pin);
                            }
                            else
                            {
                                trueinput2=0;
                                printboard(pin,'o');
                                redooo[nredo]='o';
                                nredo++;
                                nredo1=nredo;
                                printinfo();
                            }
                        }
                    }
                    break;
                case 2:
                    undo( board,prepin[po],nrows,ncolomus );
                    pr=po;
                    po--;
                    redoo2++;
                    if(nredo1!=0)
                    {
                        nredo1--;
                    }
                    break;

                case 3:
                    savedgames++;
                    system("cls");
                    moves1=nmpofmoves('x');
                    int moves2=nmpofmoves('o');
                    int score1=score(board,nrows,ncolomus,'x');
                    int score2=score(board,nrows,ncolomus,'o');
                    savefile(i);
                    loading();
                    mainmenu();
                    break;

                default:
                    printf("wrong choice\n");
                    turn2=2;
                    break;
                }
            }
            endtime();
        }
    }
    int score=highestscore();
    if(score==0)
    {
        red();
        printf("NO WINNER IT'S A DRAW!");
        reset();
    }
    else
    {
        printf("Enter your name: ");
        char name[30];
        scanf("%s",name);
        topscore(name,score);
        reset();
    }
    printf("\nPRESS m TO MENU\n");
    if(getch()=='m') mainmenu();

}

void game2()
{
    int moves1;
    int timespent=0;
    int k=0;
    int redoo1=0;
    int redoo2=0;
    int pi=0;
    int po=0;
    int pr=0;
    int nredo=0;
    int nredo1=0;
    int pin;
    int prepin[100];
    char redooo[100];

    printboard(ncolomus+2,'x');
    printinfo();

    for(int i=startfrom; i<nrows*ncolomus; i++)
    {
        time(&first);
        short whichplayer=0;
        if(i%2==0)
        {
            whichplayer=1;
            int turn1=2;
            int trueinput1;
            while(turn1==2)
            {
                while(redoo1!=0)
                {
                    printinfo();
                    printf("!!player1's turn!!\n1-PLAY\n2-REDO\n");
                    char turn11[20];
                    fflush(stdin);
                    gets(turn11);
                    turn1=atoi(turn11);
                    if(turn1==2)
                    {
                        redo(board,prepin[pr],nrows,ncolomus,redooo[nredo1]);
                        redoo1--;
                        pr++;
                        po++;
                        nredo1++;
                    }
                    else if (turn1==1)
                    {
                        break;
                    }
                    else
                    {
                        printf("wrong choice\n");
                    }
                }

                printf("!!player1's turn!!\n1-PLAY\n2-UNDO\n3-SAVE & EXIT\n");
                char turn11[20];
                fflush(stdin);
                gets(turn11);
                turn1=atoi(turn11);
                switch (turn1)
                {
                case 1:
                    printf("choose a column\n");
                    redoo1=0;
                    turn1=3;
                    trueinput1=1;
                    while(trueinput1==1)
                    {

                        scanf("%d",&pin);
                        prepin[pi]=pin;
                        po=pi;
                        pi++;
                        system("CLS");
                        if(pin>ncolomus||pin<=0)
                        {
                            printf("out of the borders !! choice again \n");
                        }
                        else
                        {
                            if(board[0][pin-1]=='x'||board[0][pin-1]=='o')
                            {
                                printf("column %d is occupied choice again player 1 \n",pin);
                            }
                            else
                            {
                                trueinput1=0;
                                printboard(pin,'x');
                                redooo[nredo]='x';
                                nredo++;
                                nredo1=nredo;
                                printinfo();
                            }
                        }
                    }
                    break;
                case 2:
                    undo( board,prepin[po],nrows,ncolomus );
                    pr=po;
                    po--;
                    redoo1++;
                    if(nredo1!=0)
                    {
                        nredo1--;
                    }
                    break;

                case 3:
                    savedgames++;
                    system("cls");
                    moves1=nmpofmoves('x');
                    int moves2=nmpofmoves('o');
                    int score1=score(board,nrows,ncolomus,'x');
                    int score2=score(board,nrows,ncolomus,'o');
                    savefile(i);
                    loading();
                    mainmenu();
                    break;

                default:
                    printf("wrong choice\n");
                    turn1=2;
                    break;
                }

            }
            endtime();

        }

        else
        {


            if (pin%2==0&&pin!=ncolomus)
            {
                pin++;
            }
            else if(pin%2==1&&pin!=1)
            {
                pin--;
            }
            prepin[pi]=pin;
            po=pi;
            pi++;
            delay(1000);
            printboard(pin,'o');
            redooo[nredo]='o';
            nredo++;
            nredo1=nredo;
            endtime();
            printinfo();
        }
    }
    int scoree=highestscore();
    if(scoree==0)
    {
        red();
        printf("NO WINNER IT'S A DRAW!");
        reset();
    }
    else if(scoree==score(board,nrows,ncolomus,'x'))
    {
        printf("Enter your name: ");
        char name[30];
        scanf("%s",name);
        topscore(name,score);
        reset();
    }
    else
    {
        printf("Computer is winner lol");
    }
    printf("\nPRESS m TO MENU\n");
        if(getch()=='m') mainmenu();
}

void emptyboard()
{
    for(int a=0; a<nrows; a++)
    {
        for(int b=0; b<ncolomus; b++)
        {
            board[a][b]=' ';
        }
    }
}
void printboard(int pin,char sign)
{
    for(int i=nrows; i>0; i--)
    {
        if(board[i-1][pin-1]==' ')
        {
            board[i-1][pin-1]=sign;
            break;
        }
    }
    system("cls");
    for(int l=0; l<ncolomus; l++)
    {
        printf("%*d",4,l+1);
    }
    printf("\n");

    for(int d=0; d<nrows; d++)
    {
        for(int c=0; c<ncolomus; c++)
        {
            printf("|");
            if(board[d][c]=='x')
            {
                red();
            }
            else if(board[d][c]=='o')
            {
                yellow();
            }
            printf(" %c ",board[d][c]);
            reset();
        }
        printf("|\n");
        for(int l=0; l<ncolomus; l++)
        {
            printf(" ---");
        }
        printf("\n");
    }

}
int nmpofmoves(char sign)
{
    int num=0;
    for(int i=0; i<nrows; i++)
    {
        for(int l=0; l<ncolomus; l++)
        {
            if(board[i][l]==sign)
            {
                num++;
            }
        }

    }
    return num;

}


void printtime(int sec)
{
    int h = (sec/3600);
    int m = (sec -(3600*h))/60;
    int s = (sec -(3600*h)-(m*60));
    bold();
    printf("time passed: %d:%d:%d\n",h,m,s);
    reset();
}

void printinfo()
{
    printtime(timespent);
    red();
    printf("player1's moves= %d\n",nmpofmoves('x'));
    printf("player1's score= %d\n",score(board,nrows,ncolomus,'x'));
    yellow();
    printf("player2's moves= %d\n",nmpofmoves('o'));
    printf("player2's score= %d\n",score(board,nrows,ncolomus,'o'));
    reset();
}

void savefile(int i)
{
    FILE *fp;
    savedgames%=3;
    char choice;
    printf("CHOOSE A FILE TO SAVE IN\n");
    printf("(1)gamefile1\n(2)gamefile2\n(3)gamefile3\n");
    choice=getch();
    printf("\a");
    switch(choice)
    {
    case '1':
        fp=fopen("gametestfile1.txt","w");
        break;
    case '2':
        fp=fopen("gametestfile2.txt","w");
        break;
    case '3':
        fp=fopen("gametestfile3.txt","w");
        break;
    default:
        printf("invalid input");
        delay(2000);
        if(gamemode==1) game1();
        if(gamemode==2) game2();
        break;
    }

    fprintf(fp,"%d,%d,%d,%d,%d\n",nrows,ncolomus,timespent,i,gamemode);
    for(int i=0; i<nrows; i++)
        for(int j=0; j<ncolomus; j++)
        {
            fprintf(fp,"%c",board[i][j]);
            if(j==ncolomus-1)
                fprintf(fp,"\n");
        }
    fclose(fp);
    loading();
    mainmenu();
}

void topscore(char name[],int score)
{
    FILE *fts;
    if((fts=fopen("topscore.txt","a"))==NULL)
        printf("EROR!!, IT SEEMS THAT TOP SCORE FLIE HAS BEEN DELETED!!");
    fprintf(fts,"\n%d %s\n",score,name);
    fclose(fts);

}

int highestscore()
{
    int p1=score(board,nrows,ncolomus,'x');
    int p2=score(board,nrows,ncolomus,'o');
    if(p1>p2)
    {
        red();
        printf("PLAYER1 WON.\n");
        return p1;
    }
    else if(p2>p1)
    {
        yellow();
        printf("PLAYER2 WON.\n");
        return p2;
    }
    else return 0;
}

void showtopscore(int numtopscore) //add to menu choices
{
    FILE *fts;
    int c=0;
    int j=0;
    int s;
    int scorelist[100];
    char name[30];
    char namelist[100][30]; //look here on 100 or numtopscore
    if((fts=fopen("topscore.txt","r"))==NULL)
    {
        red();
        printf("OPPS!, IT SEEMS THAT TOPSCORE FLIE HAS BEEN MOVED OR DELETED!!\nPLEASE ENTER FILE DIRECTION: ");
        char filedir[50];
        scanf("%s",&filedir);
        reset();
        if((fts=fopen(filedir,"r"))==NULL)
        {
            red();
            printf("NOT FOUND!\n");
            reset();
            delay(2000);
            loading();
            mainmenu();
        }
    }
    while(fscanf(fts,"%d",&s)!=EOF)
    {
        fgets(name,30,fts);
        strcpy(namelist[c++],name); //here we have 2 arrays one for scores with size j and another for names with size c
        scorelist[j++]=s;        //using algorithm to sort scores array descending and do every trans happens on it to names array
    }                           //do not forget insensitive case for names remove duplicate names and keep which with highest score
    fclose(fts);
    yellow();
    printf("PRESS m FOR MENU\n");
    reset();
    printf("SCORE  NAME\n");
    sort(scorelist,j,namelist,c);
    c=removeduplicate(scorelist,j,namelist,c);
    numtopscore=(c<numtopscore) ? (c) : (numtopscore) ;
    for(int i=0; i<numtopscore; i++)
        printf("%5d %s",scorelist[i],namelist[i]);
    printf("\n");
    if(getch()=='m') mainmenu();
}


void sort(int a[],int j,char b[][30],int c)
{
    int temp;
    char tempn[30];
    for(int i=0; i<j-1; i++)
    {
        if(a[i]<a[i+1])
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            strcpy(tempn,b[i]);
            strcpy(b[i],b[i+1]);
            strcpy(b[i+1],tempn);
        }
    }
    while(j--) sort(a,j,b,c);
}

void lowercase(char a[][30],int c)
{
    for(int i=0; i<c; i++)
        strcpy(a[i],strlwr(a[i]));
}

int removeduplicate(int a[],int j,char b[][30],int c)
{
    lowercase(b,c);
    for(int i=0; i<c; i++)
    {
        for(int k=i+1; k<c; k++)
        {
            if(strcmp(b[i],b[k])==0)
            {
                for(int s=k; s<c; s++)
                {
                    strcpy(b[s],b[s+1]);
                    a[s]=a[s+1];
                }
                k--;
                c--;
            }
        }
    }

    return c;
}



void delay(int ms)
{
    clock_t start = clock();
    while(clock()<start+ms);
}

void loading()
{
    system("cls");
    for(int i=0; i<3; i++)
    {
        system("cls");
        printf("loading.");
        delay(1000);
        system("cls");
        printf("loading..");
        delay(1000);
    }
}


void loadfile()
{
    system("cls");
    char choice;
    pop();
    printf("PRESS m FOR MENU\n[CHOOSE A SAVED GAME]\n");
    printf("[1]GAME1\n[2]GAME2\n[3]GAME3\n");
    reset();
    choice=getch();
    int c=0;
    int s;
    char ch;
    int row;
    int col;
    int a[5];
    FILE *fp_in;
    switch(choice)
    {
    case '1':
        if((fp_in=fopen("gametestfile1.txt","r"))==NULL)
        {
            printf("NO DATA!!\n");
            delay(2000);
            loadfile();
        }
        break;
    case '2':
        if((fp_in=fopen("gametestfile2.txt","r"))==NULL)
        {
            printf("NO DATA!!\n");
            delay(2000);
            loadfile();
        }
        break;
    case '3':
        if((fp_in=fopen("gametestfile3.txt","r"))==NULL)
        {
            printf("NO DATA!!\n");
            delay(2000);
            loadfile();
        }
        break;
    default:
        printf("invalid input\n");
        delay(2000);
        loadfile();
        break;

    }



    while(fscanf(fp_in,"%d,",&s)!=0) a[c++]=s;
    fclose(fp_in);
    nrows=a[0];
    ncolomus=a[1];
    timespent=a[2];
    startfrom=a[3];
    gamemode=a[4];

    FILE *fp;
    switch(choice)
    {
    case '1':
        fp=fopen("gametestfile1.txt","r");
        break;
    case '2':
        fp=fopen("gametestfile2.txt","r");
        break;
    case '3':
        fp=fopen("gametestfile3.txt","r");
        break;
    }
    int i=0;
    int j=0;
    while((ch=getc(fp))!=EOF)
    {
        if(ch=='x' || ch=='o' || ch==' ')
        {
            board[i][j++]=ch;
            if(j==ncolomus)
            {
                i++;
                j=0;
            }
        }

    }
    fclose(fp);
    switch (gamemode)
    {
    case 1:
        loading();
        game1();
        break;
    case 2:
        loading();
        game2();
        break;
    default:
        printf("NO DATA FOUND");
        delay(2000);
        mainmenu();
    }

}

void newgame() //add to menu choices
{
    timespent=0;
    startfrom=0;
    int mode;
    int wrongchoice=1;
    printf("\n\n\n\n\n\n\n\n1- Human VS Human \n2- Human vs Computer\n");
    while(wrongchoice!=0)
    {
        char modee[20];
        fflush(stdin);
        gets(modee);
        mode=atoi(modee);
        switch(mode)
        {
        case 1:
            wrongchoice=0;
            emptyboard();
            gamemode=1;
            game1();

            break;
        case 2:
            wrongchoice=0;
            emptyboard();
            gamemode=2;
            game2();

            break;
        default:
            system("CLS");
            printf("Wrong Choice\nchoice Again !!\n1- Human VS Human \n2- Human vs Computer\n");
            break;
        }
    }
}

void endtime(){
    time(&last);
    timespent+=difftime(last,first);
}

void xml()
{

    if(xmlopentrials==3)
    {
        printf("loading default\nHEIGHT=7\nWIDTH=9\nHIGHSCORE=10\n");
        delay(2000);
        loading();
        mainmenu();
    }
    system("cls");
    FILE *px;
    char s[2048];
    char *p1;
    int c=0;
    if((px=fopen(xmlpath,"r"))==NULL)
    {
        red();
        printf("can't open file\nENTER THE FILE PATH:");
        scanf("%s",&xmlpath);
        xmlopentrials++;
        reset();
        xml();
    }
    //check all tags
  while(!feof(px))
    {
        fgets(s,2047,px);

        if((p1 = strstr(s, "<Configurations>"))!=NULL) c++;
        if (p1 = strstr(s, "</Configurations>")!=NULL) c++;
        if((p1 = strstr(s, "<Height>"))!=NULL) c++;
        if (p1 = strstr(s, "</Height>")!=NULL) c++;
        if((p1 = strstr(s, "<Width>"))!=NULL) c++;
        if (p1 = strstr(s, "</Width>")!=NULL) c++;
        if((p1 = strstr(s, "<Highscores>"))!=NULL) c++;
        if (p1 = strstr(s, "<Highscores>")!=NULL) c++;
    }
   fclose(px);
   if(c!=8)
   {
       red();
       printf("XML is corrupted\nENTER A NEW FILE PATH:");
       scanf("%s",&xmlpath);
       reset();
       xmlopentrials++;
       xml();
   }
   char ch;
   char allstr[2048];
   int g=0;
   FILE *pxml;
   pxml=fopen(xmlpath,"r");
   while((ch=getc(pxml))!=EOF)
        if(ch!=' ' && ch!='\t' && ch!='\n')
            allstr[g++]=ch;
   fclose(pxml);

   int start,end;
   start=idx("<Configurations>",allstr);
   end=idx("</Configurations>",allstr);
   int consi=end-start-16;
   char wotconf[consi];
   for(int i=0;i<consi;i++) wotconf[i]=allstr[start+16+i];
                                            //15<Height>700</Height><Width>9</Width><Highscores>10</Highscores>13
                                            //start=2 end=13 word letters=8 13-2=11==>11-8=3 end-start-8+1 ==>1 for '\0'
  int h=extractXML("<Height>",wotconf,"</Height>");
  int w=extractXML("<Width>",wotconf,"</Width>");
  int hs=extractXML("<Highscores>",wotconf,"</Highscores>");
  if(h==-1 || w==-1 || hs==-1)
  {
      red();
      printf("XML FILE IS NOT VALID\nENTER THE FILE PATH:");
      scanf("%s",&xmlpath);
      reset();
      xmlopentrials++;
      xml();
  }
  nrows=h;
  ncolomus=w;
  numberoftopscore=hs;
  mainmenu();
}

int extractXML(char str1[],char str2[],char str3[])
{
   int h=-1;
   int start=idx(str1,str2);
   int end=idx(str3,str2);
   int len=strlen(str1);
   int rowsdigits=end-start-len+1;
   char rows[rowsdigits];
   for(int i=0;i<rowsdigits-1;i++)
        rows[i]=str2[start+len+i];
   rows[rowsdigits-1]='\0';
   if(start!=-1 && end!=-1&&(end-start)>=len && atoi(rows)>3) h=atoi(rows);
   return h;
}

//return index of first occurrence
int idx(char str1[],char str2[])
{
    int c=-1,i=0;

    while(str2[i]!='\0')
    {
        int j=0;
        if(str1[j]==str2[i])
        {
            int k=i;
            while(str1[j]==str2[k] && str1[j]!='\0')
            {
                k++;
                j++;
            }
            if(str1[j]=='\0') c=i;
        }
        i++;
    }
    return c;
}

void mainmenu()
{
    startfrom=0;
    timespent=0;
    int selection;
    selection=menu();
    switch(selection)
    {
    case 1:
        newgame();
        break;
    case 2:
        loadfile();
        break;
    case 3:
        system("CLS");
        showtopscore(numberoftopscore);
        break;

    case 4:
        exit(0);
    }
}
