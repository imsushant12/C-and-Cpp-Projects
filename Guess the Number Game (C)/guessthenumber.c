#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void main()
{
    system("Color 3F");
    int number,guess,numberofguess=0;                                          //number will contain random number chosen by computer.
                                                                               //guess will contain the number guessed by the user.
                                                                               //numberofguess will count the number of times user has taken to guess the correct number.

    srand(time(0));                                                            //srand function will choose random number every time.
    number=rand()%100;                                                         //to make the random number under 100,divided it by 100.

    printf("\nGuess the number between 1 and 100\n");                          //asking user to guess the number.

    do                                                                         //using a do-while loop which will work until user guesses the correct number.
    {
        scanf("%d",&guess);                                                    //input by user

        if(guess>number)                                                       //when user's guess is lower than actual number.
        {
            printf("\nLower number please!\n");
            numberofguess++;
        }

        else if(number>guess)                                                   //when user's guess is higher than actual number.
        {
            printf("\nHigher number please!\n");
            numberofguess++;
        }

        else
            printf("\nYou guessed the number in %d attempts!\n",numberofguess);
                                                                                //Printing number of times user has taken to guess the number.

    }while(guess!=number);
}
