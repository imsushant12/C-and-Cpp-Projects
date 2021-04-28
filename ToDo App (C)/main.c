#include <stdio.h>
#include <stdlib.h>
typedef struct ToDo todo;

struct ToDo
{
 char buffer[101];
 todo *next;
 int count;
};
todo *start=NULL;

int main()
{
    int choice;
    interface();
    while(1)
    {
        system("Color 3F");
        system("cls");
        printf("1. To see your ToDo list\n");
        printf("2. To create new ToDo\n");
        printf("3. To delete your ToDo\n");
        printf("4. Exit");
        printf("\n\n\nEnter your choice\t:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                  seetodo();
                  break;
            case 2:
                  createtodo();
                  break;
            case 3:
                  deletetodo();
                  break;
            case 4:
                  exit(1);
                  break;
            default:
                printf("\nInvalid Choice :-(\n");
                system("pause");
        }
    }
    return 0;
}

void interface()
{
   system("color 4F");
   printf("\n\n\n\n");
   printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
   printf("\t} : } : } : } : } : } : } : } : } :   WELCOME TO the TODO APP    : { : { : { : { : { : { : { : { : {\n\n");
   printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t       @Sushant_Gaurav\n\n\n\n\n\n\n\t");
   system("pause");
}

void seetodo()
{
    system("cls");
    todo *temp;
    temp=start;
    if(start==NULL)
           printf("\n\nEmpty ToDo :-( \n\n");

    while(temp!=NULL)
    {
        printf("%d.)",temp->count);
        puts(temp->buffer);
        fflush(stdin);
        temp=temp->next;
    }
    printf("\n\n\n");
    system("pause");
}

void createtodo()
{
    char c;
    todo *add,*temp;
    system("cls");
    while(1)
    {
        printf("\nWant to add new ToDo ?? Press 'y' for Yes and 'n' for No  :-)\n\t\t");
        fflush(stdin);
        scanf("%c",&c);
        if(c=='n')
            break;
        else
        {
            if(start==NULL)
            {
                add=(todo *)calloc(1,sizeof(todo));
                start=add;
                printf("\nType it.....\n");
                fflush(stdin);
                gets(add->buffer);
                add->count=1;
                start->next=NULL;
            }
            else
            {
                temp=(todo *)calloc(1,sizeof(todo));
                printf("\nType it.....\n");
                fflush(stdin);
                gets(temp->buffer);
                temp->next=NULL;
                add->next=temp;
                add=add->next;
            }
            adjustcount();
        }
   }
}

void deletetodo()
{
    system("cls");
    int x;
    todo *del,*temp;
    printf("\nEnter the ToDo's number that you want to remove.\n\t\t");
    if(start == NULL)
        printf("\n\nThere is no ToDo for today :-)\n\n\n");
    else
    {
        scanf("%d",&x);
        del=start;
        temp=start->next;
        while(1)
        {
            if(del->count == x)
            {
                start=start->next;
                free(del);
                adjustcount();
                break;
            }
            if(temp->count == x)
            {
                del->next=temp->next;
                free(temp);
                adjustcount();
                break;
            }
            else
            {
                del=temp;
                temp=temp->next;
            }
        }
    }
    system("pause");
}

void adjustcount()
{
    todo *temp;
    int i=1;
    temp=start;
    while(temp!=NULL)
    {
        temp->count=i;
        i++;
        temp=temp->next;
    }
}
