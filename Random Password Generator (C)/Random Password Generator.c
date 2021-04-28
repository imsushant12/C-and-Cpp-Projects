#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    system("color 3F");
    int i = 0;
    int n = 0;
    int randomizer = 0;
    srand(time(0));
    //srand((unsigned int)(time(NULL))); /* Seed the random-number
                              // generator with current time so that
                            //the numbers will be different every time we run. */
    char numbers [] = "1234567890";
    char letter [] = "abcdefghijklmnoqprstuvwyzx";
    char letterr [] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    char symbols [] = "!@#$^&*?";
    printf("\n\nHow long password : \n");
    scanf("%d",&n);
    char password[n];
    randomizer = rand() % 4;
    for (i=0;i<n;i++)
    {
        if(randomizer == 1)
        {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 2)
        {
            password[i] = symbols[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 3)
        {
            password[i] = letterr[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else
        {
            password[i] = letter[rand() % 21];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
    }
    return main();
}
