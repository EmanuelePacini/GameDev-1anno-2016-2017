#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

void control(int rig,int col,int x,int y);

bool matrix[10][10]={{false,false,false,false,false,false,false,false,false,false},
                     {false,false,false,false,false,false,false,false,false,false},
                     {false,false,false,false,false,false,false,false,false,false},
                     {false,false,false,false,false,false,false,false,false,false},
                     {false,false,false,false,false,false,false,false,false,false},
                     {false,false,false,false,false,false,false,false,false,false},
                     {false,false,false,false,false,false,false,false,false,false},
                     {false,false,false,false,false,false,false,false,false,false},
                     {false,false,false,false,false,false,false,false,false,false},
                     {false,false,false,false,false,false,false,false,false,false}};
int main()
{

    char replay='y';
    int rig,col,x,y;
    do
    {
        srand(time(NULL));
        rig=rand()%10;
        col=rand()%10;
        matrix[rig][col]=true;
        do
        {
            cout<<"inserisci le righe: ";
            cin>>x;
            cout<<"inserisci le colonne: ";
            cin>>y;
        }while(x<0&&x>11&&y<0&&y>11);
        system("pause");
        system("cls");
        control(rig,col,x,y);
    }while(replay=='y');
    return 0;
}
void control(int rig, int col, int x, int y)
{
    if(matrix[x-1][y-1]==true)
    {
        cout<<"hai vinto";
    }
    else
    {
        if(fabs(sqrt((rig-(x-1))*(rig-(x-1))+(col-(y-1))*(col-(y-1))))==1)
        {
            cout<<"fuoco";
        }
        if(fabs(sqrt((rig-(x-1))*(rig-(x-1))+(col-(y-1))*(col-(y-1))))==2)
        {
            cout<<"fuochino";
        }
    }
}
