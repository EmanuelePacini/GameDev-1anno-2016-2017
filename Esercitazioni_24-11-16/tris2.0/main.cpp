#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
char replay='y';
bool check;
bool vittoria=false;
int casella,esci;
int difficolta=1;
char player;
char tabella[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
int inizializzazione();
void mostratabella();
void turnogiocatore();
void turnobot();
bool inseriscipedina(int casella,char pedina);
bool vicinovittoria();
void ostacola(int pos);
void haivinto(char pedina);

int main()
{
    do
    {
        vittoria=false;
        cout<<"Vuoi essere il primo a giocare?"<<endl;
        cin>>player;
        system("pause");
        system("cls");

        inizializzazione();

        do
        {
            if(player=='y')
            {
                turnogiocatore();
                if(vittoria)
                {
                    cout<<"hai vinto"<<endl;
                }
            }
            else
            {
                turnobot();
                if(vittoria)
                {
                    cout<<"il computer ha vinto"<<endl;
                }
            }

        }while(!vittoria);
    cout<<"vuoi rigiocare? (y / n)"<<endl;
    cin>>replay;
    if(replay=='y')
    {
        difficolta=2;
    }
    system("pause");
    }while(replay=='y');
    return 0;
}


int inizializzazione()
{
    tabella[0]= ' ';
    tabella[1]=' ';
    tabella[2]=' ';
    tabella[3]=' ';
    tabella[4]=' ';
    tabella[5]=' ';
    tabella[6]=' ';
    tabella[7]=' ';
    tabella[8]=' ';
    cout<<"-------"<<endl;
    cout<<"|"<<tabella[0]<<"|"<<tabella[1]<<"|"<<tabella[2]<<"|"<<endl;
    cout<<"-------"<<endl;
    cout<<"|"<<tabella[3]<<"|"<<tabella[4]<<"|"<<tabella[5]<<"|"<<endl;
    cout<<"-------"<<endl;
    cout<<"|"<<tabella[6]<<"|"<<tabella[7]<<"|"<<tabella[8]<<"|"<<endl;
    cout<<"-------"<<endl;
}

void turnogiocatore()
{
    cout<<" 0,1,2"<<endl;
    cout<<" 3,4,5"<<endl;
    cout<<" 6,7,8"<<endl;
    do
    {
        cout<<"Scegli il numero della casella corrispondente a dove vuoi inserire la pedina"<<endl;
        cin>> casella;
        check=inseriscipedina(casella, 'X');
        if(!check)
        {
            cout<<"casella gia' occupata"<<endl;
        }
    }while(!check);
    haivinto('X');
    mostratabella();
    player='n';
    system("cls");
}

void turnobot()
{
    if(difficolta==1)
    {
        do
        {
            srand(time(NULL));
            casella=rand()%9;
            bool check=inseriscipedina(casella, 'O');
        }while(!check);
        haivinto('O');
        mostratabella();
        player='y';
        system("cls");
    }
    else
    {
        if(!vicinovittoria())
        {
            do
            {
                srand(time(NULL));
                casella=rand()%9;
                bool check=inseriscipedina(casella, 'O');
            }while(!check);
            haivinto('O');
            mostratabella();
            player='y';
            system("cls");
        }
    }
}

bool inseriscipedina(int casella , char pedina)
{
    if(tabella[casella]==' ')
    {
        tabella[casella]=pedina;
        return true;
    }
    return false;
}

void mostratabella()
{
    cout<<"-------"<<endl;
    cout<<"|"<<tabella[0]<<"|"<<tabella[1]<<"|"<<tabella[2]<<"|"<<endl;
    cout<<"-------"<<endl;
    cout<<"|"<<tabella[3]<<"|"<<tabella[4]<<"|"<<tabella[5]<<"|"<<endl;
    cout<<"-------"<<endl;
    cout<<"|"<<tabella[6]<<"|"<<tabella[7]<<"|"<<tabella[8]<<"|"<<endl;
    cout<<"-------"<<endl;
    system("pause");


}

bool vicinovittoria()
{
    //prima riga
    if(tabella[0]=='X'&&tabella[1]=='X')
    {
        ostacola(2);
        return true;
    }
    if(tabella[1]=='X'&&tabella[2]=='X')
    {
        ostacola(0);
        return true;
    }
    if(tabella[0]=='X'&&tabella[2]=='X')
    {
        ostacola(1);
        return true;
    }
    //seconda riga
    if(tabella[3]=='X'&&tabella[4]=='X')
    {
        ostacola(5);
        return true;
    }
    if(tabella[4]=='X'&&tabella[5]=='X')
    {
        ostacola(3);
        return true;
    }
    if(tabella[3]=='X'&&tabella[5]=='X')
    {
        ostacola(4);
        return true;
    }
    //terza riga
    if(tabella[6]=='X'&&tabella[7]=='X')
    {
        ostacola(8);
        return true;
    }
    if(tabella[7]=='X'&&tabella[8]=='X')
    {
        ostacola(6);
        return true;
    }
    if(tabella[6]=='X'&&tabella[8]=='X')
    {
        ostacola(7);
        return true;
    }
    //prima colonna
    if(tabella[0]=='X'&&tabella[3]=='X')
    {
        ostacola(6);
        return true;
    }
    if(tabella[0]=='X'&&tabella[6]=='X')
    {
        ostacola(3);
        return true;
    }
    if(tabella[3]=='X'&&tabella[6]=='X')
    {
        ostacola(0);
        return true;
    }
    //seconda colonna
    if(tabella[1]=='X'&&tabella[4]=='X')
    {
        ostacola(7);
        return true;
    }
    if(tabella[4]=='X'&&tabella[7]=='X')
    {
        ostacola(1);
        return true;
    }
    if(tabella[1]=='X'&&tabella[7]=='X')
    {
        ostacola(4);
        return true;
    }
    //terza colonna
    if(tabella[2]=='X'&&tabella[5]=='X')
    {
        ostacola(8);
        return true;
    }
    if(tabella[5]=='X'&&tabella[8]=='X')
    {
        ostacola(2);
        return true;
    }
    if(tabella[2]=='X'&&tabella[8]=='X')
    {
        ostacola(5);
        return true;
    }
    //prima diagonale
    if(tabella[0]=='X'&&tabella[4]=='X')
    {
        ostacola(8);
        return true;
    }
    if(tabella[4]=='X'&&tabella[8]=='X')
    {
        ostacola(0);
        return true;
    }
    if(tabella[0]=='X'&&tabella[8]=='X')
    {
        ostacola(4);
        return true;
    }
    //seconda diagonale
    if(tabella[2]=='X'&&tabella[4]=='X')
    {
        ostacola(6);
        return true;
    }
    if(tabella[4]=='X'&&tabella[6]=='X')
    {
        ostacola(2);
        return true;
    }
    if(tabella[2]=='X'&&tabella[6]=='X')
    {
        ostacola(4);
        return true;
    }
    return false;
}

void ostacola(int pos)
{
    if(tabella[pos]==' ')
    {
        tabella[pos]='O';
    }
}

void haivinto(char pedina)
{

    //controllo righe
    if(tabella[0]==pedina&&tabella[1]==pedina&&tabella[2]==pedina)
    {
        vittoria=true;
    }
    if(tabella[3]==pedina&&tabella[4]==pedina&&tabella[5]==pedina)
    {
        vittoria=true;
    }
    if(tabella[6]==pedina&&tabella[7]==pedina&&tabella[8]==pedina)
    {
        vittoria=true;
    }

    //controllo colonne
    if(tabella[0]==pedina&&tabella[3]==pedina&&tabella[6]==pedina)
    {
        vittoria=true;
    }
    if(tabella[1]==pedina&&tabella[4]==pedina&&tabella[7]==pedina)
    {
        vittoria=true;
    }
    if(tabella[2]==pedina&&tabella[5]==pedina&&tabella[8]==pedina)
    {
        vittoria=true;
    }
    //controllo diagonali
    if(tabella[0]==pedina&&tabella[4]==pedina&&tabella[8]==pedina)
    {
        vittoria=true;
    }
    if(tabella[2]==pedina&&tabella[4]==pedina&&tabella[6]==pedina)
    {
        vittoria=true;
    }
}
