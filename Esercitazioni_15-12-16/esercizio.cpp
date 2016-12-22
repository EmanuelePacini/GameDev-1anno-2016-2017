#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
const int MAXTANK=5;
class Tiger
{
    int salute;
    int carburante;
    int munizioni;
    bool vita;

    int getsalute() {return salute;}
    int getcarburante() {return carburante;}
    int getmunizioni() {return munizioni;}


    void setsalute(int);
    void setcarburante(int);
    void setmunizioni(int);
    void setvita(bool);

    public:
        Tiger();
        bool getvita() {return vita;}
        void pattugliamento();
        void attaccoPosizioneNemica();
        void rifornimentoERiparazioni();
        void controllacarro();
        void print();

};

Tiger::Tiger ()
{
    salute=100;
    carburante=100;
    munizioni=100;
    vita=true;
}

void Tiger::setsalute(int x)
{
    salute=x;
}

void Tiger::setcarburante(int x)
{
    carburante=x;
}

void Tiger::setmunizioni(int x)
{
    munizioni=x;
}

void Tiger::setvita(bool x)
{
    vita=x;
}

void Tiger::pattugliamento()
{
    int temp;
    srand(time(NULL));
    temp=(rand()%3)+2;

    setsalute(salute-(temp*2));
    setcarburante(carburante-(temp*8));
    setmunizioni(munizioni-(temp*2));
}

void Tiger::attaccoPosizioneNemica()
{
    int temp;
    srand(time(NULL));
    temp=(rand()%3)+2;

    setsalute(salute-(temp*2));
    setcarburante(carburante-(temp*8));
    setmunizioni(munizioni-(temp*2));
}

void Tiger::rifornimentoERiparazioni()
{
    int temp;
    srand(time(NULL));
    temp=(rand()%3)+2;
    if(salute+(temp*5)>100)
    {
        setsalute(100);
        setcarburante(100);
        setmunizioni(100);
    }
    else
    {
        setsalute(salute+(temp*5));
        setcarburante(carburante+(temp*5));
        setmunizioni(munizioni+(temp*5));
    }

}

void Tiger::controllacarro()
{
    int a=getsalute();
    if(a<=0){setvita(false);}
    a=getcarburante();
    if(a<=0){setvita(false);}
    a=getmunizioni();
    if(a<=0){setvita(false);}
}

void Tiger::print()
{
    cout<<" salute:"<<getsalute()<<endl;
    cout<<" carburante"<<getcarburante()<<endl;
    cout<<" munizioni"<<getmunizioni()<<endl;
}
int main()
{
    Tiger tank[MAXTANK];
    int scelta;
    int temp=0;
    int punteggio=0;
    bool gameOver=false;

    do
    {
        cout<<"\ncosa vuoi fare?"<<endl;
        cout<<"1.Pattugliamento"<<endl;
        cout<<"2.Attacco a base nemica"<<endl;
        cout<<"3.Rifornimento"<<endl;
        cin>>scelta;
        switch(scelta)
        {
            case 1:
                for(int i=0;i<MAXTANK;i++)
                {
                    if(tank[i].getvita())
                    {
                        tank[i].pattugliamento();
                        tank[i].controllacarro();
                        punteggio++;
                    }
                }
                break;
            case 2:
                for(int i=0;i<MAXTANK;i++)
                {
                    if(tank[i].getvita())
                    {
                        tank[i].pattugliamento();
                        tank[i].controllacarro();
                        punteggio+=2;
                    }
                }
                break;
            case 3:
                for(int i=0;i<MAXTANK;i++)
                {
                    if(tank[i].getvita())
                    {
                        tank[i].pattugliamento();
                        tank[i].controllacarro();
                    }
                }
                punteggio-=5;
                break;
        }

        for(int i=0;i<MAXTANK;i++)
        {
            if(tank[i].getvita())
            {
                cout<<"\ntank"<<i+1<<endl;
                tank[i].print();
            }
            else
            {
                cout<<"\nil tank n "<<i+1<<" è morto"<<endl;
            }
        }

        cout<<"\nil tuo punteggio e: "<<punteggio<<endl;

        for(int i=0;i<MAXTANK;i++)
        {
            if(!tank[i].getvita())
            {
                temp++;
            }
        }

        if (temp==MAXTANK)
        {
            gameOver=true;
        }
    }while(punteggio<100&&!gameOver);

    return 0;
}
