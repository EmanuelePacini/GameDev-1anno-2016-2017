#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

void evento1(vector <string>& stiva); //Il mercantile carica le seguenti merci: "vino", "lana", "avorio" e "legno".
void evento2(vector <string>& stiva); //l’ultimo carico di merce caricato cade in acqua
void evento3(vector <string>& stiva); //Aggiungere in cima alla stiva un carico di "tè"
void evento4(vector <string>& stiva); //scambi "lana" con "frumento".
void evento5(vector <string>& stiva); //attaccano dei pirati golosi di "vino".
void evento6(vector <string>& stiva); //riordina tutte le merci della stiva in ordine alfabetico
void evento7(vector <string>& stiva); //mischia casualmente l'ordine delle merci
void evento8(vector <string>& stiva); //Vendi tutte le tue merci per “oro”.

int main()
{
    vector <string> stiva;
    evento1(stiva);
    evento2(stiva);
    evento3(stiva);
    evento4(stiva);
    evento5(stiva);
    evento6(stiva);
    evento7(stiva);
    evento8(stiva);
}

void evento1(vector <string>& stiva)
{
    vector <string>::iterator it;
    stiva.push_back("vino");
    stiva.push_back("lana");
    stiva.push_back("avorio");
    stiva.push_back("legno");
    for(it=stiva.begin();it!=stiva.end();it++)
    {
        cout<<*it<<endl;
    }
    system("pause");
    system("cls");
}

void evento2(vector <string>& stiva )
{
    vector <string>::iterator it;
    stiva.pop_back();
    for(it=stiva.begin();it!=stiva.end();it++)
    {
        cout<<*it<<endl;
    }
    system("pause");
    system("cls");
}

void evento3(vector <string>& stiva)
{
    vector <string>::iterator it;
    stiva.push_back("te'");
    for(it=stiva.begin();it!=stiva.end();it++)
    {
        cout<<*it<<endl;
    }
    system("pause");
    system("cls");
}

void evento4(vector <string>& stiva)
{
    vector <string>::iterator it;
    it=find(stiva.begin(),stiva.end(),"lana");
    *it="frumento";
    for(it=stiva.begin();it!=stiva.end();it++)
    {
        cout<<*it<<endl;
    }
    system("pause");
    system("cls");

}
void evento5(vector <string>& stiva)
{
    vector <string>::iterator it;
    stiva.erase(stiva.begin());
    for(it=stiva.begin();it!=stiva.end();it++)
    {
        cout<<*it<<endl;
    }
    system("pause");
    system("cls");
}

void evento6(vector <string>& stiva)
{
    vector <string>::iterator it;
    sort(stiva.begin(),stiva.end());
    for(it=stiva.begin();it!=stiva.end();it++)
    {
        cout<<*it<<endl;
    }
    system("pause");
    system("cls");

}

void evento7(vector <string>& stiva)
{
    vector <string>::iterator it;
    srand(time(NULL));
    random_shuffle(stiva.begin(),stiva.end());
    for(it=stiva.begin();it!=stiva.end();it++)
    {
        cout<<*it<<endl;
    }
    system("pause");
    system("cls");
}

void evento8(vector <string>& stiva)
{
    vector <string>::iterator it;
    stiva.clear();
    stiva.push_back("oro");
    for(it=stiva.begin();it!=stiva.end();it++)
    {
        cout<<*it<<endl;
    }
    system("pause");
    system("cls");
}







