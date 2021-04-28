#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int game(char,char);                    //Declaration of the function used in the program.

void main()
{
    int n;                              //n will receive the random number from computer.
    char you,computer,result;           //you denotes user's input and computer denotes choice of computer. Result will contain the final result of the game.

    srand(time(0));                     //srand function will choose random number every time.
    n=rand()%100;                       //to make the random number under 100, divided it by 100.

    if(n<33)                            //using simple probability 100 is roughly divided among stone,paper and scissor.
        computer='s';                   //s is denoting stone.

    else if(n>33 && n<66)
        computer='p';                   //p is denoting paper.

    else
        computer='z';                   //z is denoting scissor.

    printf("\n\n\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");

    scanf("%c",&you);                    //input from the user

    result=game(you,computer);           //calling function "game" which will return 1 if user wins,0 if draw and -1 if loss.

    if(result==0)
        printf("\n\n\t\t\t\tGame Draw!\n");

    else if(result==1)
        printf("\n\n\t\t\t\tWow! You have won the game!\n");

    else
        printf("\n\n\t\t\t\tOh! You have lost the game!\n");

    printf("\t\t\t\tYOu choose : %c and Computer choose : %c\n",you,computer);

}

int game(char you,char computer)        //Definition of the function.
{
    if(you==computer)                   //if both user and computer has chose the same thing.
        return 0;

    if(you=='s'&& computer=='p')        //user's choice is stone and computer's choice is paper.
        return -1;

    else if(you=='p'&& computer=='s')   //user's choice is paper and computer's choice is stone.
        return 1;

    if(you=='s'&& computer=='z')        //user's choice is stone and computer's choice is scissor.
        return 1;

    else if(you=='z'&& computer=='s')   //user's choice is scissor and computer's choice is stone.
        return -1;

    if(you=='p'&& computer=='z')        //user's choice is paper and computer's choice is scissor.
        return -1;

    else if(you=='z'&& computer=='p')   //user's choice is scissor and computer's choice is paper.
        return 1;
}
