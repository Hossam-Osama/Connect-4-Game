#ifndef UNDOANDREDO_H_INCLUDED
#define UNDOANDREDO_H_INCLUDED
void redo(char board[][100],int pin,int nrows,int ncolomus,char sign )
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

void undo(char board[][100],int pin,int nrows,int ncolomus )
{
    for(int i=nrows; i>0; i--)
    {
        if(board[i-1][pin-1]==' ')
        {
            board[i][pin-1]=' ';
            break;
        }
        else
        {
            if(board[0][pin-1]!=' ')
            {
                board[0][pin-1]=' ';
                break;
            }
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


#endif // UNDOANDREDO_H_INCLUDED
