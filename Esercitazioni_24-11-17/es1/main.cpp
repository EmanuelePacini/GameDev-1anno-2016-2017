#include <iostream>

using namespace std;

int main()
{
    int punteggi[10];
    for(int i=0;i<10;i++)
    {
        cout << "Inserisci il punteggio del giocatore n: " <<i+1<<" ";
        cin>>punteggi[i];
    }
    for(int i=10;i>0;i--)
    {
        cout<<"Giocatore n : "<<i<<" Punteggio: "<<punteggi[i-1]<<endl;
    }


    return 0;
}
