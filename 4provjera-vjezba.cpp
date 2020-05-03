#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

void NewRac(unsigned long long brRacuna[], string ime[], double stnr[], int brKlijenata)
{
    unsigned long long in;
    while(1)
    {
        try
        {
            cout << "Unesite broj racuna: ";
            cin >> in;
            if(in < 1000000000 || in > 9999999999)
            {
                throw "Neispravan unos";
            }
            break;
        }
        catch(const char *x)
        {
            cout << x << endl;
        }
    }
    brRacuna[brKlijenata] = in;
    cout << "Unesite prezime i ime: ";
    cin.ignore();
    getline(cin, ime[brKlijenata]);
    cout<<"Unesite stanje na racunu: ";
    cin>>stnr[brKlijenata];
}

