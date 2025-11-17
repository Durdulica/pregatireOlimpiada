#ifndef EXERCITII_H
#define EXERCITII_H
#include <iostream>
using namespace std;

/*
Doi copii vopsesc un gard alcătuit din n scânduri (numerotate de la 1 la n, cu n ≤ 100000).
Primul copil ia o cutie de vopsea roșie și vopsește scândurile cu numărul p, 2p, 3p etc.
Al doilea copil procedează la fel, dar folosește vopsea albastră și vopsește din q în q scânduri.
După terminarea vopsirii, unele scânduri rămân nevopsite, unele sunt roșii, altele albastre, iar cele vopsite de amândoi devin violet.
Cunoscând numerele n, p și q, scrieți un program care să afișeze:
câte scânduri rămân nevopsite;
câte scânduri sunt vopsite în roșu;
câte scânduri sunt vopsite în albastru;
câte scânduri sunt vopsite în violet.
Exemplu: pentru n = 25, p = 4, q = 6 se vor afișa valorile 17 4 2 2.
CLASA a VI-a
*/


void ex1() {
    int n, p, q;
    cin >> n >> p >> q;
    int v[n];
    int ct0 = n, ct1 = 0, ct2 = 0, ct3 = 0;

    for(int i = 0; i < n; i++) {
        if(i % p == 0) {
            v[i] = 1;
            ct1++;
            ct0--;
        }
        if(i % q == 0) {
            if (v[i] == 1) {
                v[i] = 3;
                ct3++;
                ct1--;
            }else{
                v[i] = 2;
                ct2++;
                ct0--;
            }
        }
    }

    cout << ct0 << " " << ct1 << " " << ct2 << " " << ct3;
}

void ex1Optim() {
    long int n, m, p, q, a, b, r, nec, ros, alb, vio;
    cin >> n >> p >> q;
    a = p;  //facem 2 variabile auxiliare
    b = q;
    while(b) {
        r = a % b;  //calculam cmmmc
        a = b;
        b = r;
    }
    m = p * q / a;  // (a,b)*[a,b]=a*b =>[a.b]=a*b/(a,b);
    vio = n/m;      //
    ros = n/p - vio;    //scadem din nr. de scanduri rosii pe cele care si-au schimbat culoarea
    alb = n/q - vio;    //scadem din nr. de scanduri albastre pe cele care si-au schimbat culoarea
    nec = n -ros-alb-vio;   //scadem toate scandurile vopsite pt. a le afla pe cele nevopsite
    cout << nec << " " << ros <<  " " << alb << " " << vio << endl;     //afisam raspunsurile
}

// Problema excursiei
// La Olimpiada Națională de Informatică, organizatorii vor să realizeze o excursie în care să participe toți cei n concurenți.
// Fiecare concurent are asociat un număr între 1 și n.
// Sponsorii au pus la dispoziție trei mijloace de transport, impunând însă o condiție:
// Suma numerelor de ordine ale participanților din fiecare mijloc de transport să fie aceeași,
// în caz contrar excursia nu va avea loc.
// Scrieți un program care să distribuie pe cei n concurenți în cele trei mijloace de transport.
// (Concursul Interjudețean „Urmășii lui Moisil”, Iași, 2001)

void ex2() {
    int n;
    cin >> n;

    int suma = n * (n + 1) / 2;
    if(suma % 3 != 0) {
        cout << "Nu se poate";
        return;
    }

    int rez = suma / 3;

    int sum[3] = {0,0,0};
    int ctSum[3] = {0,0,0};
    int mat[3][100] = {};

    for(int x = n; x > 0; x--) {
        for(int i = 0; i < 3; i++) {
            if(sum[i] + x <= rez) {
                sum[i] += x;
                mat[i][ctSum[i]++] = x;
                break;
            }
        }
    }

    if(sum[0] != rez || sum[1] != rez || sum[2] != rez) {
        cout << "Suma inegala";
        return;
    }

    for(int i = 0; i < 3; i++) {
        cout << ctSum[i] << ": ";
        for(int j = 0; j < ctSum[i]; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Să ne imaginăm o pădure nemțească dispusă pe o rețea ortogonală de n × n puncte (n ≤ 100),
// astfel încât distanța dintre două puncte vecine pe orizontală sau verticală este 1.
// În toate punctele se află pomi, cu excepția unui singur punct (x₀, y₀) în care se află pădurarul.
// Presupunând că pomii sunt punctiformi, pădurarul vede doar o parte din pomi —
// pe oricare linie dreaptă care trece prin poziția sa pădurarul vede cel mult 2 pomi (câte unul în fiecare direcție).
// Scrieți un program care citește n, x₀ și y₀ și afișează numărul de pomi pe care îi vede pădurarul.
// Exemplu: pentru n = 4, x₀ = 0, y₀ = 0, pădurarul vede 9 pomi.

int cmmdc(int a, int b) {
    if (b == 0) return a;
    return cmmdc(b, a % b);
}

void ex3() {
    int n,x,y,ct=0;
    cin >> n >> x >> y;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((x - i == 1 || i - x == 1) && (y - j == 1 || j - y == 1)) {
                ct++;
            }
        }
    }
    cout << ct;
}
#endif //EXERCITII_H
