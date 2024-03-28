#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

struct Votant
{
    string nume;
    vector<string> prenume;
    string adresa;
    string cnp;
    string serie_ci;
    bool a_votat = false;
};

bool exista_in_baza(map<string, struct Votant> vt, string cnp)
{
    if(vt.find(cnp) != vt.end()) return true;
    return false;
}

bool e_minor(string cnp)
{
    if(cnp[0] == '1' || cnp[0] == '2') return false;
    if(cnp[1] == '0' && cnp[2] == '0' && cnp[3] == '0' && cnp[4] < '5') return false;
    return true;
}

int main()
{
    map<string, struct Votant> votanti;
    struct Votant v;
    string pn;
    fstream f("evidenta.csv");
    while(v.serie_ci != "FO975560")
    {
        f >> v.nume;
        char guard = getchar();
        while(guard != ',')
        {
            f >> pn;
            v.prenume.push_back(pn);
            guard = getchar();
        }
        getline(f, v.adresa, ',');
        getline(f, v.cnp, ',');
        getline(f, v.serie_ci);
        votanti[v.cnp] = v;
    }
    char sgn;
    string cnp_votant;
    string nume_candidat;
    int incercari_frauda = 0;
    map<string, int> candidati;
    while(cin >> sgn)
    {
        if(sgn == '+')
        {
            cin >> cnp_votant;
            getline(cin, nume_candidat);
            if(!exista_in_baza(votanti, cnp_votant))
            {
                cout << "CNP invalid\n";
                incercari_frauda++;
            }
            if(exista_in_baza(votanti, cnp_votant) && !(votanti[cnp_votant].a_votat))
            {
                votanti[cnp_votant].a_votat = true;
                candidati[nume_candidat]++;
            }
            if(exista_in_baza(votanti, cnp_votant) && (votanti[cnp_votant].a_votat))
            {
                cout << "Vot deja inregistrat\n";
                incercari_frauda++;
            }
            if(exista_in_baza(votanti, cnp_votant) && e_minor(cnp_votant))
            {
                cout << "Persoana minora\n";
            }
        }
        if(sgn == '?')
        {
            cout << "Statistici\n==========\n";
            cout << "Incercari de frauda: " << incercari_frauda << endl;

        }
        if(sgn == '*')
        {
            cout << "Statistici\n==========\n";
            cout << "Incercari de frauda: " << incercari_frauda << endl;
            break;
        }
    }
    return 0;
}