#include <iostream>

using namespace std;
void azzeragriglia(int*matrix[5][5]);
void stampagriglia(int(*matrix)[5][5]);
void movimento(int(&matrix)[5][5],char mov);

int main()
{
    int *matrix[5][5];
    bool errore=false;
    char mov;
    char replay='y';
    do
    {
        azzeragriglia(matrix[5][5]);
        stampagriglia(matrix);
        do
        {
            cout<<"Dove ti vuoi muovere? (usa i tasti wasd per muoiverti)"<<endl;
            cin>>mov;
            switch(mov)
            {
                case 'w':
                    movimento(matrix,mov);
                    stampagriglia(matrix);
                    break;
                case 'a':
                    movimento(matrix,mov);
                    stampagriglia(matrix);
                    break;
                case 's':
                    movimento(matrix,mov);
                    stampagriglia(matrix);
                    break;
                case 'd':
                    movimento(matrix,mov);
                    stampagriglia(matrix);
                    break;
                default:
                    cout<<"Comando non valido"<<endl;
                    errore=true;
                    break;

            }
        }while(errore);
        cout<<"Vuoi rigiocare? (y / n)"<<endl;
        cin>>replay;
    }while(replay=='y');
    return 0;
}
