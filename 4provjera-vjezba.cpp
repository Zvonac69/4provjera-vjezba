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

int Binarnopret(unsigned long long brRacuna[], int l, int r, unsigned long long x)
{
    while(l <= r)
    {
        int m = l+(r-l)/2;
        if(brRacuna[m] == x)
        {
            return m;
        }
        if(brRacuna[m] < x)
        {
            l = m+1;
        }
        else
        {
            r = m-1;
        }
    }
    return -1;
}
void Izmrac(unsigned long long brRacuna[], string ime[], double stnr[], int brKlijenata)
{
    unsigned long long dRac;
    cout << "Upisite br. racuna koji zelite promijeniti: ";
    cin >> dRac;
    if(Binarnopret(brRacuna, 0, brKlijenata-1, dRac)>-1)
    {
        unsigned long long novira = brRacuna[Binarnopret(brRacuna, 0, brKlijenata-1, dRac)];
        cout << "Upisite novi broj racuna: ";
        cin >>novira;
        cout << "Upisite prezime i ime: ";
        cin.ignore();
        getline(cin, ime[Binarnopret(brRacuna, 0, brKlijenata-1, dRac)]);
        cout << "Upisite novo stanje na racunu: ";
        cin >> stnr[Binarnopret(brRacuna, 0, brKlijenata-1, dRac)];
        cout << "Racun uspjesno izmjenjen!" << endl;
        brRacuna[Binarnopret(brRacuna, 0, brKlijenata-1, dRac)] = novira;
    }
    else if(Binarnopret(brRacuna, 0, brKlijenata-1, dRac) <= -1)
    {
        cout << "Takav racun ne postoji" << endl;
    }
}

void Sortit(unsigned long long brRacuna[], string ime[], double stnr[], int brKlijenata)
{
    unsigned long long *sortBrRac = new unsigned long long[1000];
    string *sortIme = new string[1000];
    double *sortStnr = new double[1000];
    for(int i = 0; i < brKlijenata; i++)
    {
        sortBrRac[i] = brRacuna[i];
        sortIme[i] = ime[i];
        sortStnr[i] = stnr[i];
    }
    for(int i = 0; i < brKlijenata-1; i++)
    {
        for(int j = 0; j < brKlijenata-1-i; j++)
        {
            if(ime[j] > ime[j+1])
            {
                unsigned long long temp = sortBrRac[j];
                sortBrRac[j] = sortBrRac[j+1];
                sortBrRac[j+1] = temp;

                string tomp = sortIme[j];
                sortIme[j] = sortIme[j+1];
                sortIme[j+1] = tomp;

                double timp = sortStnr[j];
                sortStnr[j]  =sortStnr[j+1];
                sortStnr[j+1] = timp;
            }
        }
    }
    for(int i=0; i<brKlijenata; i++)
    {
        cout << "Broj racuna: " << sortBrRac[i] << endl << "Ime i prezime: " << sortIme[i] << endl << "Stanje na racunu: " << sortStnr[i] << endl << endl;
    }
}

int main()
{
    int brKlijenta = 0;
    unsigned long long *brRacuna = new unsigned long long[1000];
    string *ime = new string[1000];
    double *stnr = new double[1000];
    int chs;
    while(1)
    {
        cout << "1. Unos novog racuna" << endl;
        cout << "2. Ispis svih podataka" << endl;
        cout << "3. Pretraga po prezimenu i imenu" << endl;
        cout << "4. Brisanje racuna" << endl;
        cout << "5. Izmjena po broju racuna" << endl;
        cout << "6. Sortiranje po imenu" << endl;
        cout << "7. Izlaz" << endl;
        cin >> chs;
        if(chs==1)
        {
            NewRac(brRacuna, ime, stnr, brKlijenta);
            brKlijenta++;
        }
        if(chs == 2)
        {
            if(brKlijenta>0)
            {
                double s;
                string bist;
                int brNegativnih;
                int brTekucih;
                IspisPod(brRacuna, ime, stnr, brKlijenta, s, bist, brNegativnih, brTekucih);
                cout << "Zbroj novaca: " << s << endl << "Racun sa najvise novaca: " << bist << endl << "Negativni racuni: " << brNegativnih << endl << "Broj tekucih racuna: " << brTekucih << endl;
            }
            else
            {
                cout << "Nema racuna koje mozemo prikazati" << endl;
            }
        }
        if(chs == 3)
        {
            ImePrezime(brRacuna, ime, stnr, brKlijenta);
        }
        if(chs == 4)
        {
            int pr = 0;
            Brisanjerac(brRacuna, ime, stnr, brKlijenta, pr);
            brKlijenta-=pr;
        }
        if(chs == 5)
        {
            Izmrac(brRacuna, ime, stnr, brKlijenta);
        }
        if(chs == 6)
        {
            Sortit(brRacuna, ime, stnr, brKlijenta);
        }
        if(chs == 7)
        {
            break;
        }
    }
    return 0;

}
