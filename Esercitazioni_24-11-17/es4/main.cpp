#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void esplorazione();
void difesa();
void scorta();

int fuel=100;
int ammo=50;
int stocks=100;
int main()
{

    string id;
    do
    {


        cout<<"carburante: "<<fuel<<endl<<"munuzioni: "<<ammo<<endl<<"scorte: "<<stocks<<endl;
        do
        {
            cout<<"inserire id missione: ";
            cin>>id;
        }while(id.compare("esplorazione")==0&&id.compare("difesa")==0&&id.compare("scorta")==0);

        if(id.compare("esplorazione")==0)
        {
            esplorazione();
        }
        if(id.compare("difesa")==0)
        {
            difesa();
        }
        if(id.compare("scorta")==0)
        {
            scorta();
        }
    }while(fuel>0&&ammo>0&&stocks>0);
    return 0;
}

void esplorazione()
{
    fuel=fuel-20;
    stocks=stocks-20;
    system("pause");
    system("cls");
}
void difesa()
{
    fuel=fuel-5;
    stocks=stocks-5;
    ammo=ammo-20;
    system("pause");
    system("cls");
}
void scorta()
{
    fuel=fuel-10;
    stocks=stocks-10;
    ammo=ammo-10;
    system("pause");
    system("cls");
}
