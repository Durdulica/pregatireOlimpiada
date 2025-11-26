#ifndef EXERCITII_H
#define EXERCITII_H
#include <iostream>
#include <fstream>
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
            if(x == i && y == j) {
                continue;
            }
            int dx=abs(x-i), dy = abs(y-j);
            if(cmmdc(dx,dy) == 1) {
                ct++;
            }
        }
    }
    cout << ct << endl;
}

// Problema „Euro-dolar”
// Ion are 100 de euro și un prieten care îl ajută să obțină ratele de schimb euro-dolar pentru următoarele n zile (n ≤ 100).
// Pentru fiecare zi, se dau două numere D și E, ceea ce înseamnă că:
// în ziua respectivă, cu 100 de euro se pot cumpăra D dolari;
// iar cu E dolari se pot cumpăra 100 de euro.
// Scrieți un program care să determine suma maximă (în euro) pe care Ion o poate acumula după n zile,
// efectuând tranzacții euro-dolar (cumpără sau vinde în oricare zi).
// Se citește n și apoi n perechi (D, E).

void ex4() {
    ifstream fin("D:/info/c++/clion/pregatireOlimpiada/file.in");
    int n;
    float depozit = 100, D,E;
    fin >> n;
    for(int i = 0; i < n; i++) {
        fin >> D >> E;

        if(D / E > 1) {
            depozit = depozit * D / E;
        }
    }

    cout << depozit << endl;
}

// Problema „Șef”
// O firmă face angajări.
// Fiecărei persoane angajate îi corespunde un număr natural nenul, a cărui reprezentare binară ocupă 16 biți.
// Acest număr reprezintă codul persoanei în ierarhia firmei.
// Fiind date două numere a și b, se consideră că persoana a este „șeful” lui b dacă, pentru orice
// poziție binară 0 a lui a, poziția corespunzătoare a lui b este 0.
// (adică toate biții de 1 ai lui a se regăsesc și în b)
// Evident, orice persoană este propriul ei șef.
// Se citește n, un număr natural care reprezintă codul unei persoane.
// Să se afișeze numărul șefului ei.
// De exemplu, pentru n = 255 se va afișa 256.

int toBinary(int n) {
    int p = 1, rez = 0;
    while(n) {
        rez = rez + n % 2 * p;
        p *= 10;
        n /= 2;
    }
    return rez;
}

int binaryToDecimal(int n) {
    int p = 1, rez = 0;
    while(n) {
        rez = rez + n % 10 * p;
        p *= 2;
        n /= 10;
    }
    return rez;
}

void ex5() {
    int n, p = 1;
    cin >> n;

    while(p <= n) {
        p *= 2;
    }

    cout << p;
}

//dreptunghi de suma maxima
//fie A o matr. cu n linii si m coloana cu elem intregi (n,m <= 50)
//Sa se det. o zona dreptunghiulara in matr. pt. care suma elem. din aceasta zona este max.
//In cazul in care exista mai multe solutii, veti afisa o zona de arie maxima

int chenarMin(int mat[50][50], int n, int m, int grad) {
    int i1 = grad, j1 = grad, i2 = n - 1 - grad, j2 = m - 1 - grad;
    int suma1 = 0, suma2 = 0, suma3 = 0, suma4 = 0;
    for(int k = j1; k <= j2; k++) {
        suma1 += mat[i1][k];
    }
    for(int k = i1+1; k <= i2; k++) {
        suma2 += mat[k][j2];
    }
    for(int k = j2-1; k >= j1; k--) {
        suma3 += mat[i2][k];
    }
    for(int k = i2-1; k > i1; k--) {
        suma4 += mat[k][j1];
    }
    int rez = min(min(suma1, suma2), min(suma3, suma4));
    if(rez == suma1) return 1;
    if(rez == suma2) return 2;
    if(rez == suma3) return 3;
    if(rez == suma4) return 4;
}

void ex6() {
    ifstream fin("D:/info/c++/clion/pregatireOlimpiada/file.in");
    int mat[50][50];
    int n, m;
    fin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fin >> mat[i][j];
        }
    }

    int p = chenarMin(mat, n, m, 0);
    int i1 = 0, i2 = n, j1 = 0, j2 = m;
    if(p == 1) {
        i1++;
    }
    if(p == 2) {
        j2--;
    }
    if(p == 3) {
        i2--;
    }
    if(p == 4) {
        j1++;
    }
    for(int i = i1; i < i2; i++) {
        for(int j = j1; j < j2; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void ex6Optim() {
    int n, m;
    int sum[100][100], a[100][100];

    ifstream fin("D:/info/c++/clion/pregatireOlimpiada/file.in");
    fin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            fin >> a[i][j];
        }
    }
    int smax = a[0][0], x1max = 0, x2max = 0, y1max = 0, y2max = 0;

    for(int x1 = 1; x1 <= n; x1++) {
        for(int y1 = 1; y1 <= m; y1++) {
            for(int i = 1; i <= x1; i++) {
                for(int j = 1; j <= y1; j++) {
                    sum[x1][y1]+=a[i][j];
                }
            }
        }
    }

    for(int x1 = 1; x1 <= n; x1++){
        for(int y1 = 1; y1 <=m; y1++) {
            for(int x2 = x1; x2 <= n; x2++) {
                for(int y2 = y1; y2 <= m; y2++) {
                    int s = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
                    if(s > smax) {
                        smax = s;
                        x1max = x1;
                        y1max = y1;
                        x2max = x2;
                        y2max = y2;
                    }else if(s == smax && (x2-x1+1)*(y2-y1+1) > (x2max-x1max+1)*(y2max-y1max+1)) {
                        x1max = x1;
                        y1max = y1;
                        x2max = x2;
                        y2max = y2;
                    }
                }
            }
        }
    }

    cout << smax << " " << (x2max-x1max+1)*(y2max-y1max+1) << endl;
    cout << x1max << ", " << y1max << endl;
    cout << x2max << ", " << y2max << endl;
}
#endif //EXERCITII_H