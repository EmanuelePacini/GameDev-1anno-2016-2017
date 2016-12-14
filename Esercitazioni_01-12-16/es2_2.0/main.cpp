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
int posnem[3][2];

void azzeragriglia();
void stampagriglia();
void movimento(char mov);
void movimentonemico();
void vittoria();
void sconfitta();
void salvapos(int x, int y, int i);

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
            cout<<"muovono i mostri"<<endl;
            system("pause");
            movimentonemico();
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
            matrix[x][y]=6;
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
            salvapos(x,y,i);
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
                    if(matrix[posx-1][posy]!=1&&matrix[posx-1][posy]!=3&&matrix[posx-1][posy]!=6)
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
                        if(matrix[posx-1][posy]==6)
                        {
                            cout<<"mossa non valida"<<endl;
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                else
                {
                    if(matrix[posx][posy]!=1&&matrix[posx][posy]!=3&&matrix[posx-1][posy]!=6)
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
                        if(matrix[posx-1][posy]==6)
                        {
                            cout<<"mossa non valida"<<endl;
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
                    if(matrix[posx][posy-1]!=1&&matrix[posx][posy-1]!=3&&matrix[posx][posy-1]!=6)
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
                        if(matrix[posx][posy-1]==6)
                        {
                            cout<<"mossa non valida"<<endl;
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                else
                {
                    if(matrix[posx][0]!=1&&matrix[posx][0]!=3&&matrix[posx][posy-1]!=6)
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
                        if(matrix[posx][posy-1]==6)
                        {
                            cout<<"mossa non valida"<<endl;
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
                    if(matrix[posx+1][posy]!=1&&matrix[posx+1][posy]!=3&&matrix[posx+1][posy]!=6)
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
                        if(matrix[posx+1][posy]==6)
                        {
                            cout<<"mossa non valida"<<endl;
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                else
                {
                    if(matrix[4][posy]!=1&&matrix[4][posy]!=3&&matrix[posx+1][posy]!=6)
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
                        if(matrix[posx+1][posy]==6)
                        {
                            cout<<"mossa non valida"<<endl;
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
                    if(matrix[posx][posy+1]!=1&&matrix[posx][posy+1]!=3&&matrix[posx][posy+1]!=6)
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
                        if(matrix[posx][posy+1]==6)
                        {
                            cout<<"mossa non valida"<<endl;
                        }
                        else
                        {
                            sconfitta();
                        }
                    }
                }
                else
                {
                    if(matrix[posx][4]!=1&&matrix[posx][4]!=3&&matrix[posx][posy+1]!=6)
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
                        if(matrix[posx][posy+1]==6)
                        {
                            cout<<"mossa non valida"<<endl;
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
void salvapos(int x, int y, int i)
{
    posnem[i][0]=x;
    posnem[i][1]=y;
}

void movimentonemico()
{
    int temp;
    for(int i=0;i<3;i++)
    {
        srand(time(NULL));
        temp=rand()%4;
        switch(temp)
        {
            case 0:
                if(posnem[i][0]!=0)
                {
                    if(matrix[posnem[i][0]-1][posnem[i][1]]!=1&&matrix[posnem[i][0]-1][posnem[i][1]]!=7&&matrix[posnem[i][0]-1][posnem[i][1]]!=6)
                    {
                      posnem[i][0]--;
                      matrix[posnem[i][0]+1][posnem[i][1]]=0;
                    }

                    if(matrix[posnem[i][0]-1][posnem[i][1]]==7)
                    {
                        posnem[i][0]--;
                        matrix[posnem[i][0]+1][posnem[i][1]]=0;
                        sconfitta();
                    }
                }
                else
                {
                    if(matrix[posnem[i][0]-1][posnem[i][1]]!=1&&matrix[posnem[i][0]-1][posnem[i][1]]!=7&&matrix[posnem[i][0]-1][posnem[i][1]]!=6)
                    {
                        posnem[i][0]=4;
                        matrix[0][posnem[i][1]]=0;
                    }
                    if(matrix[posnem[i][0]-1][posnem[i][1]]==7)
                    {
                        sconfitta();
                    }
                }
                break;
            case 1:
                if(posnem[i][1]!=0)
                {
                    if(matrix[posnem[i][0]][posnem[i][1]-1]!=1&&matrix[posnem[i][0]][posnem[i][1]-1]!=7&&matrix[posnem[i][0]][posnem[i][1]-1]!=6)
                    {
                      posnem[i][1]--;
                      matrix[posnem[i][0]][posnem[i][1]+1]=0;
                    }

                    if(matrix[posnem[i][0]][posnem[i][1]-1]==7)
                    {
                        posnem[i][1]--;
                        matrix[posnem[i][0]][posnem[i][1]+1]=0;
                        sconfitta();
                    }
                }
                else
                {
                    if(matrix[posnem[i][0]][posnem[i][1]-1]!=1&&matrix[posnem[i][0]][posnem[i][1]-1]!=7&&matrix[posnem[i][0]][posnem[i][1]-1]!=6)
                    {
                        posnem[i][0]=4;
                        matrix[0][posnem[i][1]-1]=0;
                    }
                    if(matrix[posnem[i][0]][posnem[i][1]-1]==7)
                    {
                        sconfitta();
                    }
                }
                break;
            case 2:
                 if(posnem[i][0]!=0)
                {
                    if(matrix[posnem[i][0]+1][posnem[i][1]]!=1&&matrix[posnem[i][0]+1][posnem[i][1]]!=7&&matrix[posnem[i][0]+1][posnem[i][1]]!=6)
                    {
                      posnem[i][0]++;
                      matrix[posnem[i][0]-1][posnem[i][1]]=0;
                    }

                    if(matrix[posnem[i][0]][posnem[i][1]]==7)
                    {
                        posnem[i][0]++;
                        matrix[posnem[i][0]-1][posnem[i][1]]=0;
                        sconfitta();
                    }
                }
                else
                {
                    if(matrix[posnem[i][0]+1][posnem[i][1]]!=1&&matrix[posnem[i][0]+1][posnem[i][1]]!=7&&matrix[posnem[i][0]+1][posnem[i][1]]!=6)
                    {
                        posnem[i][4]=0;
                        matrix[4][posnem[i][1]]=0;
                    }
                    if(matrix[posnem[i][0]+1][posnem[i][1]]==7)
                    {
                        sconfitta();
                    }
                }
                break;
            case 3:
                if(posnem[i][0]!=0)
                {
                    if(matrix[posnem[i][0]][posnem[i][1]+1]!=1&&matrix[posnem[i][0]][posnem[i][1]+1]!=7&&matrix[posnem[i][0]][posnem[i][1]+1]!=6)
                    {
                      posnem[i][1]++;
                      matrix[posnem[i][0]][posnem[i][1]-1]=0;
                    }

                    if(matrix[posnem[i][0]][posnem[i][1]+1]==7)
                    {
                        posnem[i][1]++;
                        matrix[posnem[i][0]][posnem[i][1]-1]=0;
                        sconfitta();
                    }
                }
                else
                {
                    if(matrix[posnem[i][0]][posnem[i][1]+1]!=1&&matrix[posnem[i][0]][posnem[i][1]+1]!=7&&matrix[posnem[i][0]][posnem[i][1]+1]!=6)
                    {
                        posnem[i][4]=0;
                        matrix[4][posnem[i][1]]=0;
                    }
                    if(matrix[posnem[i][0]][posnem[i][1]+1]==7)
                    {
                        sconfitta();
                    }
                }
                break;
        }
        matrix[posnem[i][0]][posnem[i][1]]=3;
    }
}



