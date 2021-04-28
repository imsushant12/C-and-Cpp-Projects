/*#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int height=20,width=20,x,y,fx,fy,flag,gameend,score;
int tx[100],ty[100];
int piece=0;

void snake()
{
    int i;
    int prevx,prevy,prev2x,prev2y;
    prevx=tx[0];
    prevy=ty[0];
    tx[0]=x;
    ty[0]=y;
    for (i=1;i<=piece;i++)
    {
        prev2x=tx[i];
        prev2y=ty[i];
        tx[i]=prevx;
        ty[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(flag)
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    }
    if(x==0 || x==height || y==0 || y==width)
    {
        gameend=1;
    }
    if(x==fx && y==fy)
    {
    label3:
    fx=rand()%20;
    if(fx==0)
        goto label3;
    label4:
    fy=rand()%20;
    if(fy==0)
        goto label4;
        score=score+10;
        piece++;
    }
}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'w' :
                flag=1;
                break;
        case 's' :
                flag=2;
                break;
        case 'a' :
                flag=3;
                break;
        case 'd' :
                flag=4;
                break;
        }
    }
}

void setup()
{
    x=height/2;
    y=width/2;

    label1:
    fx=rand()%20;
    if(fx==0)
        goto label1;
    label2:
    fy=rand()%20;
    if(fy==0)
        goto label2;

    gameend=0;
    score=0;
}

void draw()
{
    system("cls");
    int i,j,k,ch;
    for(i=0;i<=height;i++)
    {
        for(j=0;j<=width;j++)
        {
            if(i==0 || j==0 || i==height || j==width)
            {
                printf("*");
            }
            else
            {
                if(i== x && j==y)
                {
                    printf("O");
                }
                else if(i==fx && j==fy)
                {
                    printf("@");
                }
                else
                {
                    ch=0;
                    for(k=0;k<piece;k++)
                    {
                        if(i==tx[k]  &&  j==ty[k])
                            printf("o");
                            ch=1;
                    }
                    if(ch==0)
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\nYour score is %d ",score);
}

main()
{
    setup();
    while(gameend != 1)
    {
        input();
        draw();
        snake();
    }
}


/*#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int height=20,width=20,x,y,fx,fy,flag,gameend,score;
int tx[100],ty[100];
int piece=0;

void snake()
{
    int i;
    int prevx,prevy,prev2x,prev2y;
    prevx=tx[0];
    prevy=ty[0];
    tx[0]=x;
    ty[0]=y;
    for (i=1;i<=piece;i++)
    {
        prev2x=tx[i];
        prev2y=ty[i];
        tx[i]=prevx;
        ty[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(flag)
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    }
    if(x==0 || x==height || y==0 || y==width)
    {
        gameend=1;
    }
    if(x==fx && y==fy)
    {
    label3:
    fx=rand()%20;
    if(fx==0)
        goto label3;
    label4:
    fy=rand()%20;
    if(fy==0)
        goto label4;
        score=score+10;
        piece++;
    }
}

void input()
{
    if(GetAsyncKeyState(VK_UP))
        flag=1;
    else if(GetAsyncKeyState(VK_DOWN))
        flag=2;
    else if(GetAsyncKeyState(VK_LEFT))
        flag=3;
    else if(GetAsyncKeyState(VK_RIGHT))
        flag=4;
}

void setup()
{
    x=height/2;
    y=width/2;

    label1:
    fx=rand()%20;
    if(fx==0)
        goto label1;
    label2:
    fy=rand()%20;
    if(fy==0)
        goto label2;

    gameend=0;
    score=0;
}

void draw()
{
    system("cls");
    int i,j,k,ch;
    for(i=0;i<=height;i++)
    {
        for(j=0;j<=width;j++)
        {
            if(i==0 || j==0 || i==height || j==width)
            {
                printf("*");
            }
            else
            {
                if(i== x && j==y)
                {
                    printf("O");
                }
                else if(i==fx && j==fy)
                {
                    printf("@");
                }
                else
                {
                    ch=0;
                    for(k=0;k<piece;k++)
                    {
                        if(i==tx[k]  &&  j==ty[k])
                            printf("o");
                            ch=1;
                    }
                    if(ch==0)
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\nYour score is %d ",score);
}

main()
{
    setup();
    while(gameend != 1)
    {
        input();
        draw();
        snake();
    }
}*/






















































#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define N 20
#define M 40

int i,j,Field[N][M],x,y,Gy,Head,Tail,Game,Frogs,a,b,var,dir,score,HighScore,Speed;

FILE *f;

void snakeInitialization(){
    f=fopen("highscore.txt","r");
    fscanf(f,"%d",&HighScore);
    fclose(f);

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            Field[i][j]=0;
        }
    }

    x=N/2;y=M/2; Gy = y; Head = 5; Tail =1; Game = 0,Frogs = 0,dir='d',score=0,Speed = 99;

    for(i=0;i<Head;i++){
        Gy++;
        Field[x][Gy-Head] = i+1;
    }
}

void print(){
    for(i=0;i<=M+1;i++){
        if(i==0){
            printf("%c",201);
        }else if(i==M+1){
            printf("%c",187);
        }else{
            printf("%c",205);
        }
    }
    printf("   Current Score: %d  HighScore: %d",score,HighScore);
    printf("\n");

    for(i=0;i<N;i++){
        printf("%c",186);

        for(j=0;j<M;j++){
            if(Field[i][j]==0) printf(" ");
            if(Field[i][j]>0 && Field[i][j]!=Head) printf("%c",176);
            if(Field[i][j]==Head) printf("%c",178);
            if(Field[i][j]==-1) printf("%c",15);
            if(j==M-1) printf("%c\n",186);
        }
    }

    for(i=0;i<=M+1;i++){
        if(i==0){
            printf("%c",200);
        }else if(i==M+1){
            printf("%c",188);
        }else{
            printf("%c",205);
        }
    }
}
void ResetScreenPosition(){
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut,Position);
}


void Random(){
    srand(time(0));
    a = 1+ rand() % 18;
    b = 1 + rand() % 38;

    if(Frogs == 0 && Field[a][b]==0){
        Field[a][b]= -1;
        Frogs = 1;
        if(Speed>10 && score!=0) Speed = Speed - 5;
    }
}

int getch_noblock(){
    if(_kbhit())
        return _getch();
    else
        return -1;
}

void movement(){
    var = getch_noblock();
    var = tolower(var);

    if(((var=='d'||var=='a')||(var=='w'||var=='s'))
       &&(abs(dir-var)>5)) dir = var;
    if(dir =='d'){
        y++;
        if(y==M-1) y = 0;
        if(Field[x][y]!=0 && Field[x][y]!=-1) GameOver();
        if(Field[x][y]==-1){
            Frogs = 0;
            score+=5;
            Tail -= 1;
        }

        Head++;
        Field[x][y] = Head;
    }

    if(dir =='a'){
        y--;
        if(y==0) y = M-1;
        if(Field[x][y]!=0 && Field[x][y]!=-1) GameOver();
        if(Field[x][y]==-1){
            Frogs = 0;
            score+=5;
            Tail -= 1;
        }
        Head++;
        Field[x][y] = Head;
    }

    if(dir =='w'){
        x--;
        if(x==-1) x = N-1;
        if(Field[x][y]!=0 && Field[x][y]!=-1) GameOver();
        if(Field[x][y]==-1){
            Frogs = 0;
            score+=5;
            Tail -= 1;
        }
        Head++;
        Field[x][y] = Head;
    }

    if(dir =='s'){
        x++;
        if(x==N-1) x = 0;
        if(Field[x][y]!=0 && Field[x][y]!=-1) GameOver();
        if(Field[x][y]==-1){
            Frogs = 0;
            score+=5;
            Tail -= 1;
        }
        Head++;
        Field[x][y] = Head;
    }
}

void TailRemove(){
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(Field[i][j]==Tail){
                Field[i][j] = 0;
            }
        }
    }
    Tail++;
}

void GameOver(){
    printf("\a");
    Sleep(1500);
    system("Cls");

    if(score>HighScore){
        printf("  New HighScore %d!!!!!!\n\n",score);
        system("pause");
        f=fopen("highscore.txt","w");
        fprintf(f,"%d",score);
        fclose(f);
    }

    system("Cls");
    printf("\n\n         GAME OVER !!!!!!\n");
    printf("             Score : %d \n\n",score);
    printf("             Press ENTER to play again or ESC to exit ... \n");


    while(1){
        var = getch_noblock();
        if(var == 13){
            Game = 0;
            snakeInitialization();
            break;
        }else if(var == 27){
            Game = 1;
            break;
        }
    }
    system("Cls");
}
void main()
{
    system("Color 3F");

    snakeInitialization();

    while(Game == 0){
        print();
        ResetScreenPosition();
        Random();
        movement();
        TailRemove();
        Sleep(Speed);
    }
}





/*#include<stdio.h>
#include<stdlib.h>

#define N 20
#define M 40

int i,j,x,y,head,tail,gy;
int area[N][M];    //our area of play

void snake()
{
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
            area[M][N]=0;
    }

    x=N/2;    //starting area of snake i.e. middle part of our field area
    y=M/2;
    head=5;
    tail=1;
    gy=y;

    for(i=0;i<head;i++)
    {
        gy++;
        area[x][gy-head]=i+1;
    }
}


void outputbox()
{
    for(i=0;i<M+2;i++)
    {
        if(i==0)                  //topmost left character
            printf("%c",201);
        else if(i==M+1)           //topmost right character
            printf("%c",187);
            else
                printf("%c",205);   //all the rest places on topmost breadth of the rectangle
    }
    printf("\n");

    for(i=0;i<N;i++)
    {
        printf("%c",186);
        for(j=0;j<M;j++)
        {
            if(area[i][j] == 0)  // our field area which will be blank
                printf(" ");

            if(area[i][j] > 0 && area[i][j] != head)
                printf("%c",176);

            if(area[i][j] == head)
                printf("%c",178);

            if(j == M-1)
                printf("%c\n",186);
        }
    }

    for(i=0;i<M+2;i++)
    {
        if(i==0)
            printf("%c",200);
        else if(i==M+1)
            printf("%c",188);
            else
                printf("%c",205);
    }
}


void main()
{
    system("Color 3F");
    outputbox();
}
*/
