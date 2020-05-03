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

bool negativan(double br)
{
    if(br < 0)
    {
        return true;
    }
    return false;
}

bool tekuci(unsigned long long br)
{
    if(br/100000000 == 32)
    {
        return true;
    }
    return false;
}

void IspisPod(unsigned long long brRacuna[], string ime[], double stnr[], int brKlijenata, double &s, string &bist, int &brNegativnih, int &brTekucih)
{
    for(int i=0; i<brKlijenata; i++)
    {
        cout << "Broj racuna: " << brRacuna[i] << endl << "Ime i prezime: " << ime[i] <<endl << "Stanje na racunu: " << stnr[i] << endl << endl;
    }
    s = accumulate(stnr, stnr+brKlijenata, 0);
    int maxi = max_element(stnr, stnr+brKlijenata)-stnr;
    bist = ime[maxi];
    brNegativnih = count_if(brRacuna, brRacuna+brKlijenata, negativan);
    brTekucih = count_if(brRacuna, brRacuna+brKlijenata, tekuci);
}

void ImePrezime(unsigned long long brRacuna[], string ime[], double stnr[], int brKlijenata)
{
    cout << "Upisite prezime i ime: ";
    string pretraga;
    cin.ignore();
    getline(cin, pretraga);
    int z = 0;
    for(int i=0; i<brKlijenata; i++)
    {
        if(pretraga == ime[i])
        {
            cout << "Broj racuna: " << brRacuna[i] << endl << "Stanje na racunu: " << stnr[i]<< endl << endl;
            z++;
        }
        else if(z == 0 && i == brKlijenata-1)
        {
            cout << "Takav racun ne postoji" << endl;
        }
    }
}

void Brisanjerac(unsigned long long brRacuna[], string ime[], double stnr[], int brKlijenata, int &pr)
{
    unsigned long long dRac;
    cout << "Upisite br. racuna koji zelite izbrisati: ";
    cin >> dRac;
    int z = 0;
    for(int i=0; i<brKlijenata; i++)
    {
        if(dRac == brRacuna[i])
        {
            for(int j = i; j < brKlijenata-1; j++)
            {
                brRacuna[j] = brRacuna[j+1];
                ime[j] = ime[j+1];
                stnr[j] = stnr[j+1];
            }
            pr++;
            z++;
            cout << "Racun uspjesno izbrisan" << endl;
        }
        else if( z== 0 && i == brKlijenata-1)
        {
            cout << "Takav racun ne postoji" << endl;
        }
    }
}

