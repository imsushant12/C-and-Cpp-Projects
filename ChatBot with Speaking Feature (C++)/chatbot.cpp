#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

void speak(string phrase)
{
    string command = "espeak -v +f3 \""+phrase+"\"";
    const char* charCommand = command.c_str();
    system(charCommand);
    cout<<phrase;
}

int userInput()
{
	cout<<"\n>>>";
}

int getInput(char input[128])
{
	char array[128];

	FILE *fp = fopen("data.txt", "r");

	while(!feof(fp))
	{
		fgets(array,128,fp);

		if(strncmp(array,input,strlen(input)) == 0)
		{
			fgets(array,128,fp);
			speak(array);
		}
		else if(feof(fp))
        {
            string phrase = "I don't know its answer. But I will try to learn this new thing. Thank you Dear Human!\n";
            speak(phrase);
        }
	}
}

int main()
{
	char input[128];

	string phrase = "Hello, I am Chat Bot.\n";
    speak(phrase);

    phrase = "My name is JARVIS.\n";
    speak(phrase);

    phrase = "I am learning how to chat with humans. How can I help you?";
    speak(phrase);

	do
	{
		userInput();
		gets(input);
		getInput(input);
	}while(1);

}



