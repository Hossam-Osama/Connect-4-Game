#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

int score(char board[][100],int nrows,int ncoloums,char sign)
{
    int splayer1=0;
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < (ncoloums-2); j++)
        {
            int count=0;
            for (int k = 0; k < 4; k++)
            {
                if (board[i][j + k] == sign) count++;
            }
            if (count == 4)
            {
                splayer1++;
            }
        }
    }
    for (int j = 0; j < ncoloums; j++)
    {
        for (int i = 0; i < (nrows-2); i++)
        {
            int count = 0;
            for (int k = 0; k < 4; k++)
            {
                if (board[i + k][j] ==sign ) count++;
            }
            if (count ==4)
            {
                splayer1++;
            }
        }
    }
    int ii, jj;
    for (int i =0 ; i < nrows; i++)
    {
        if(i==0)
        {
            for (int j = 0; j < ncoloums; j++)
            {
                int  count=0;
                // right-downwards:
                for (ii = i, jj = j; (ii < nrows) || (jj < ncoloums); ii++, jj++)
                {
                    if (board[ii][jj] == sign)
                    {
                        count++;
                        if (count >= 4)
                        {
                            splayer1++;
                        }
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j <1; j++)
            {
                int  count=0;
                // right-downwards:
                for (ii = i, jj = j; (ii < nrows) || (jj < ncoloums); ii++, jj++)
                {
                    if (board[ii][jj] == sign)
                    {
                        count++;
                        if (count >= 4)
                        {
                            splayer1++;
                        }
                    }
                }
            }
        }
    }
    for (int i =0 ; i < nrows; i++)
    {
        if(i==nrows-1)
        {
            for (int j = 0; j < ncoloums; j++)
            {
                int count=0;
                //right-upward:
                for (ii = i, jj = j; (ii >=0) || (jj < ncoloums); ii--, jj++)
                {
                    if (board[ii][jj] == sign)
                    {
                        count++;
                        if (count >= 4)
                        {
                            splayer1++;
                        }
                    }
                }
            }
        }
        else
        {
            int j = 0;
            int count=0;
            //right-upward:
            for (ii = i, jj = j; (ii >=0) || (jj < ncoloums); ii--, jj++)
            {
                if (board[ii][jj] == sign)
                {
                    count++;
                    if (count >= 4)
                    {
                        splayer1++;
                    }
                }
            }
        }
    }
    return splayer1;
}

#endif // SCORE_H_INCLUDED
