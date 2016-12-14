#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int matrix [5][5];
bool endGame=true;
int posx=4;
int posy=2;
int giocatore=7;

void azzeragriglia();
void stampagriglia();
void movimento(char mov);
void vittoria();
void sconfitta();

int main()
{
    char mov;
    char replay='y';
    do
    {
        azzeragriglia();
        stampagriglia();
        do
        {
            cout<<"Dove ti vuoi muovere? (usa i tasti wasd per muoiverti)"<<endl;
            cin>>mov;
            movimento(mov);
            stampagriglia();
        }while(endGame);

        cout<<"Vuoi rigiocare? (y / n)"<<endl;
        cin>>replay;
    }while(replay=='y');
    return 0;
}

void azzeragriglia()
{
    int x;
    int y;
    int i=0;

    for(int i=0;i<5;i++)
    {
        for(int j=0;i<5;i++)
        {
            matrix[i][j]=0;
        }
    }
    matrix[posx][posy]=giocatore;

    while(i!=1)
    {
        srand(time(NULL));
        x=rand()%5;
        y=rand()%5;
        if(matrix[x][y]==0)
        {
            matrix[x][y]=1;
            i++;
        }
    }
    i=0;

    while(i!=3)
    {
        srand(time(NULL));
        x=rand()%5;
        y=rand()%5;
        if(matrix[x][y]==0)
        {
            matrix[x][y]=3;
            i++;
        }
    }

}

void stampagriglia()
{
    for(int i=0;i<5;i++)
    {
        cout<<"-----------\n";
        for(int j=0;j<5;j++)
        {
            cout<<'|'<<matrix[i][j];
        }
        cout<<"|\n";
    }
    cout<<"-----------\n";

}

void movimento(char mov)
{

    switch(mov)
        {
            case 'w':
                if(posx!=0)
                {
                    if(matrix[posx-1][posy]!=1&&matrix[posx-1][posy]!=3)
                    {
                      posx--;
                      matrix[posx+1][posy]=0;
                    }
                    else
                    {
                        if(matrix[posx-1][posy]==1)
                        {
                            vittoria();
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                else
                {
                    if(matrix[posx][posy]!=1&&matrix[posx][posy]!=3)
                    {
                        posx=4;
                        matrix[0][posy]=0;
                    }
                    else
                    {
                        if(matrix[posx-1][posy]==1)
                        {
                            vittoria();
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                break;
            case 'a':
                if(posy!=0)
                {
                    if(matrix[posx][posy-1]!=1&&matrix[posx][posy-1]!=3)
                    {
                      posy--;
                      matrix[posx][posy+1]=0;
                    }
                    else
                    {
                        if(matrix[posx][posy-1]==1)
                        {
                            vittoria();
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                else
                {
                    if(matrix[posx][0]!=1&&matrix[posx][0]!=3)
                    {
                        posy=4;
                        matrix[posx][0]=0;
                    }
                    else
                    {
                        if(matrix[posx][posy-1]==1)
                        {
                            vittoria();
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                break;

            case 's':
                 if(posx!=4)
                {
                    if(matrix[posx+1][posy]!=1&&matrix[posx+1][posy]!=3)
                    {
                      posx++;
                      matrix[posx-1][posy]=0;
                    }
                    else
                    {
                        if(matrix[posx+1][posy]==1)
                        {
                            vittoria();
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                else
                {
                    if(matrix[4][posy]!=1&&matrix[4][posy]!=3)
                    {
                        posx=0;
                        matrix[4][posy]=0;
                    }
                    else
                    {
                        if(matrix[posx+1][posy]==1)
                        {
                            vittoria();
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                break;
            case 'd':
                if(posy!=4)
                {
                    if(matrix[posx][posy+1]!=1&&matrix[posx][posy+1]!=3)
                    {
                      posy++;
                      matrix[posx][posy-1]=0;
                    }
                    else
                    {
                        if(matrix[posx][posy+1]==1)
                        {
                            vittoria();
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                else
                {
                    if(matrix[posx][4]!=1&&matrix[posx][4]!=3)
                    {
                        posy=0;
                        matrix[posx][4]=0;
                    }
                    else
                    {
                        if(matrix[posx][posy+1]==1)
                        {
                            vittoria();
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                break;
        }
        matrix[posx][posy]=giocatore;
}

void vittoria()
{
    cout<<"hai vinto"<<endl;
    endGame=false;
}

void sconfitta()
{
    cout<<"hai perso"<<endl;
    endGame=false;
}
