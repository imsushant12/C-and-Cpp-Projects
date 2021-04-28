#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player1[15],player2[15];
int count=0;


void box()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        printf("||");
        for(j=0;j<3;j++)
        {
            printf(" %c ||",matrix[i][j]);
        }
        printf("\n||---||---||---||\n");
    }
}



char win()
{
    if(matrix[0][0]=='X'&& matrix[1][1]=='X'&& matrix[2][2]=='X')                                //for diagonal-1
        return 'X';
    if(matrix[0][2]=='X'&& matrix[1][1]=='X'&& matrix[2][0]=='X')                                //for diagonal-2
        return 'X';
    if(matrix[0][0]=='X'&& matrix[1][0]=='X'&& matrix[2][0]=='X')                                //for column-1
        return 'X';
    if(matrix[0][1]=='X'&& matrix[1][1]=='X'&& matrix[2][1]=='X')                                //for column-2
        return 'X';
    if(matrix[0][1]=='X'&& matrix[1][1]=='X'&& matrix[2][1]=='X')                                //for column-3
        return 'X';
    if(matrix[0][0]=='X'&& matrix[0][1]=='X'&& matrix[0][2]=='X')                                //for row-1
        return 'X';
    if(matrix[1][0]=='X'&& matrix[1][1]=='X'&& matrix[1][2]=='X')                                //for row-2
        return 'X';
    if(matrix[2][0]=='X'&& matrix[2][1]=='X'&& matrix[2][2]=='X')                                //for row-3
        return 'X';
    else if(matrix[0][0]=='O'&& matrix[1][1]=='O'&& matrix[2][2]=='O')                           //for diagonal-1
        return 'O';
    else if(matrix[0][2]=='O'&& matrix[1][1]=='O'&& matrix[2][0]=='O')                           //for diagonal-2
        return 'O';
    else if(matrix[0][0]=='O'&& matrix[1][0]=='O'&& matrix[2][0]=='O')                           //for column-1
        return 'O';
    else if(matrix[0][1]=='O'&& matrix[1][1]=='O'&& matrix[2][1]=='O')                           //for column-2
        return 'O';
    else if(matrix[0][1]=='O'&& matrix[1][1]=='O'&& matrix[2][1]=='O')                           //for column-3
        return 'O';
    else if(matrix[0][0]=='O'&& matrix[0][1]=='O'&& matrix[0][2]=='O')                           //for row-1
        return 'O';
    else if(matrix[1][0]=='O'&& matrix[1][1]=='O'&& matrix[1][2]=='O')                           //for row-2
        return 'O';
    else if(matrix[2][0]=='O'&& matrix[2][1]=='O'&& matrix[2][2]=='O')                           //for row-3
        return 'O';
    else
        return '$';
}


void input()
{
    int i,j;
    char n,a;
    while(1)
    {
        printf("\n\n\nTurn for %s....\n",player1);
        count ++;
        scanf("%c",&n);
        fflush(stdin);
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(n==matrix[i][j])
                {
                    if(count%2==0)
                        matrix[i][j]='O';
                    else
                        matrix[i][j]='X';
                 }
            }
        }
        system("cls");
        box();
        a=win();
        if(a=='X')
        {
            printf("\n\nCongratulation %s! You have won the game!!!!",player1);
            count=0;
            break;
        }
        else if(a=='$' && count==9)
        {
            printf("\n\n\n\t\rIt's a tie!!!!!");
        count=0;
        break;
        }
        printf("\n\n\nTurn for %s....\n",player2);
        count++;
        scanf("%c",&n);
        fflush(stdin);
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(n==matrix[i][j])
                {
                    if(count%2==0)               //helps in checking whose turn (player 2 as again turn will be at even position so at even it will consider O)
                        matrix[i][j]='O';
                    else
                        matrix[i][j]='X';
                }
            }
        }
        system("cls");
        box();
        a=win();
        if(a=='O')
        {
            printf("\n\n\n\t\tCongratulation %s!You have won the game!!!!",player2);
            break;
        }
    }
}

int main()
{
    system("Color 3F");
    int ch,gd=0,gm,maxX,m,i;
    char c;
    //graphics stars

    initgraph(&gd,&gm,"C:\\TC\\BGI");

    settextstyle(1,HORIZ_DIR,6);
    setcolor(14);
    outtextxy(90,150,"T I C     T A C");
    outtextxy(200,240,"T O E");
    delay(1000);
    maxX=getmaxx();
    m=maxX-400;
    for(i=0;i<m;i++)
    {
        settextstyle(3,HORIZ_DIR,4);
        setcolor(10);
        outtextxy(200,240,"Loading......");
        setcolor(12);
        outtextxy(150+i,300,"||||||||||||||||||||||||");
        delay(5);
        if(i<m)
           cleardevice();
    }
    closegraph();        //graphics end.

    int choice;
    Label1:
    system("cls");
    printf("\n1.Start the game.");
    printf("\n2.How to play?");
    printf("\n3.Quit the game.");
    printf("\n\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        fflush(stdin);
        system("cls");
        printf("\nEnter player's name who is choosing 'X'.  : ");
        fflush(stdin);
        gets(player1);
        printf("\nWelcome %s! your icon is 'X'.",player1);
        printf("\nEnter player's name who is choosing 'O'.  : ");
        fflush(stdin);
        gets(player2);
        printf("\nWelcome %s! your icon is 'X'.",player2);
        system("pause");
        system("cls");
        box();
        input();
        printf("\n\n\n\t\t\t\tGAME OVER\n");
        system("pause");
        goto Label1;
        break;

    case 2:
        system("cls");
        printf("\n\n\t\t\t\t\t:_INSTRUCTIONS:_\n");
        printf("\n\tThe game is played on a grid that's 3 squares by 3 squares.\n");
        printf("\tYou are X,your friend is O. Players take turns putting their marks in empty squares.\n");
        printf("\tThe first player to get 3 of her marks in a row (up,down,across,or diagonally) is the winner.\n");
        printf("\tWhen all 9 squares are full, the game is over.\n\n\t\t\t");
        system("pause");
        goto Label1;
        break;

    case 3:
        exit(1);
        break;

    default:
        printf("\nInvalid Choice\n");
    }
}





/*
void input()
{
    int i,j;
    char a,b;
    while(1)
    {

    }
    scanf("%d",&spot);
    if(spot<=3)
    {
        i=spot-1;
        matrix[0][i]='X';
    }
    else if(spot>3 && spot<=6)
    {
        i=spot-1;
        i=i%3;
        matrix[1][i]='X';
    }
    else if(spot>5 && spot<=9)
    {
        i=spot-1;
        i=i%6;
        matrix[2][i]='X';
    }
    for(i=0;i<3;i++)
    {
        printf("");
        for(j=0;j<3;j++)
        {
            printf(" %c ",matrix[i][j]);
        }
        printf("\n--------\n");
    }
}
*/



