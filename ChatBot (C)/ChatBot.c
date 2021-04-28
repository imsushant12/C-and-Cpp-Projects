#include <stdio.h>
#include <stdio.h>
#include <string.h>

int getInput(char [128]);
int removeSpaces(char [128]);

int main()
{
	char input[128];

	//basic message that will get displayed when program will run
	printf("Hello, I am ChatBot");
	printf("\nMy name is JARVIS.\nHello");

	do
	{
		printf(">>");
		gets(input);                        //gets will take input from the user as a string
		getInput(input);                    //input will be passed to the getInput function and respective answer will be displayed.
	}while(1);

}

int getInput(char input[128])
{
	char array[128];

	FILE *fp = fopen("data.txt", "r");      //opening file named data.txt using fopen() function

	while(!feof(fp))                        //checking input till the end of file
	{
		fgets(array,128,fp);                //getting input from user using predefined function.

		//if question is found in the file, it will show respective answer.
		if(strncmp(array,input,strlen(input)) == 0)
		{
			fgets(array,128,fp);
			printf("%s",array);             //printing the answer
			removeSpaces(array);            //calling function to say Hello
		}
	}
}

int removeSpaces(char array[128])
{
	printf("\nHello");
}
