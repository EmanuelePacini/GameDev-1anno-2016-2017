#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Creature
{
    int _Health;
    int _Will;
    int _Attack;
    int _Intimidate;
    bool _IsAlive;

public:
    Creature(int, int, int, int);
    void Attack(Creature&); //attacco alla salute
    void Intimidate(Creature&); //attacco alla volontà
    void Rest();
    void TakeDamageH(int);
    void TakeDamageW(int);
    bool CheckLife();
};

Creature:: Creature(int h, int w, int a, int i)
{
    _Health=h;
    _Will=w;
    _Attack=a;
    _Intimidate=i;
    _IsAlive=true;
}

void Creature::Attack(Creature& c)
{
    int temp; //danno da passare a TakeDamage
    srand(time(NULL));
    temp=(rand()%6);
    c.TakeDamageH(_Attack+temp);
}

void Creature::Intimidate(Creature& c)
{
    int temp; //danno da passare a TakeDamage
    srand(time(NULL));
    temp=(rand()%6);
    c.TakeDamageW(_Will+temp);
}

void Creature::Rest()
{
    int temp; //valora da aggiungere a _Health  e _Will
    srand(time(NULL));
    temp=(rand()%6);
    _Health+=temp;

    srand(time(NULL));
    temp=(rand()%6);
    _Will+=temp;
}

void Creature::TakeDamageH(int h)
{
    _Health-=h;
}
void Creature::TakeDamageW(int w)
{
    _Will-=w;
}

bool Creature::CheckLife()
{
    if(_Health<=0||_Will<=0)
    {
        _IsAlive=false;
    }
    return _IsAlive;
}

void Caccia(Creature&);
void CacciaD(Creature&,Creature&);
void Riposo(Creature&);

int main()
{
    int temp;
    Creature VanHelsing(100,100,10,10);
    Creature Dracula(50,50,20,20);
    int probDracula=0;
    int scelta;
    //storia random
    do
    {
        cout<<"cosa vuoi fare?"<<endl;
        cout<<"caccia"<<endl;
        cout<<"riposo"<<endl;
        cin>>scelta;
        srand(time(NULL));
        temp=(rand()%10)+1;
        switch(scelta)
        {
            case 1: if(temp>probDracula)
                        {Caccia(VanHelsing);}
                    else
                    {
                        CacciaD(VanHelsing,Dracula);
                    }
                    probDracula++;
                break;
            case 2: Riposo(VanHelsing);
                break;
            default:
                break;
        }


    }while(VanHelsing.CheckLife()&&Dracula.CheckLife());
    return 0;
}

void Caccia(Creature& vh)
{
    int scelta;
    int temp;

        srand(time(NULL));
        temp=(rand()%1);
        if(temp==1)
        {
            Creature Servitori[3]{{12,30,12,10},{12,30,12,10},{12,30,12,10}};
            cout<<"Hain incontrato tre Servitori"<<endl;
            do
            {
                cout<<"cosa vuoi fare?"<<endl;
                cout<<"attacco"<<endl;
                cout<<"intimidire"<<endl;
                cin>>scelta;
                switch(scelta)
                {
                    case 1:for(int i=0;i<3;i++)vh.Attack(Servitori[i]);
                        break;
                    case 2:for(int i=0;i<3;i++)vh.Intimidate(Servitori[i]);
                        break;
                }
                for(int i=0;i<3;i++)Servitori[i].Attack(vh);

            }while(vh.CheckLife()&&Servitori[1].CheckLife());
        }
        else
        {
            Creature Spettri[3]{{100,12,2,20},{100,12,2,20},{100,12,2,20}};
            cout<<"Hain incontrato tre Spettri"<<endl;
            do
            {
                cout<<"cosa vuoi fare?"<<endl;
                cout<<"attacco"<<endl;
                cout<<"intiidire"<<endl;
                cin>>scelta;
                switch(scelta)
                {
                    case 1:for(int i=0;i<3;i++)vh.Attack(Spettri[i]);
                        break;
                    case 2:for(int i=0;i<3;i++)vh.Intimidate(Spettri[i]);
                        break;
                }
                for(int i=0;i<3;i++)
                {
                    int temp;
                    srand(time(NULL));
                    temp=rand()%1;
                    if(temp==1)Spettri[i]..Attack(vh);
                    else Spettri[i].Intimidate(vh);
                }

            }while(vh.CheckLife()&&Spettri[1].CheckLife());
        }
}

void Riposo(Creature& vh)
{

}

void CacciaD(Creature& vh,Creature& d)
{
    int scelta;
    cout<<"Hain incontrato Dracula"<<endl;
        do
        {
            cout<<"cosa vuoi fare?"<<endl;
            cout<<"attacco"<<endl;
            cout<<"intiidire"<<endl;
            cin>>scelta;
            switch(scelta)
            {
                case 1:for(int i=0;i<3;i++)vh.Attack(d);
                    break;
                case 2:for(int i=0;i<3;i++)vh.Intimidate(d);
                    break;
            }
            for(int i=0;i<3;i++)
            {
                int temp;
                srand(time(NULL));
                temp=rand()%1;
                if(temp==1)d.Attack(vh);
                else d.Intimidate(vh);
            }
        }while(vh.CheckLife()&&d.CheckLife());
}
