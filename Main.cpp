#include <iostream>
using namespace std;

/**
Să se plaseze n regine pe o tablă de şah de dimensiune nxn astfel încât oricare două regine
să nu se atace. Conform regulilor de şah două regine se atacă dacă sunt pe aceeaşi linie, 
coloană sau diagonală
*/

void init(int n, int a[][8]) { // initializeaza matricea cu 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
}

bool valid(int n, int v[], int k) {
    for (int i = 0; i < k; i++) {
        // Verifica daca reginele se ataca pe aceeasi coloana sau diagonale
        if (v[i] == v[k] || v[i] == v[k] + (k - i) || v[i] == v[k] - (k - i)) {
            return false;
        }
    }
    if (k >= n) // Verifica daca regina e in afara tablei
        return false;
    return true;
}

bool solutie(int n, int v[], int k) {
    return k == n; // Verifica daca am plasat toate reginele
}

void afisare(int n, int a[][8], int v[]) {
    init(n, a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == v[i]) {
                a[i][j] = 1; // Plaseaza regina
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------\n";
}

void back(int n, int a[][8], int v[], int k) {
    for (int i = 0; i < n; i++) {
        v[k] = i; // Plaseaza regina pe linia k, coloana i
        if (valid(n, v, k)) { // Verifica plasarea reginei
            if (solutie(n, v, k)) { // Verifica daca solutia e completa
                afisare(n, a, v);
            } else {
                back(n, a, v, k + 1); // Plaseaza urmatoarea regina
            }
        }
    }
}

int main() {
    int n = 8; // Setam n pentru 8 regine
    cout << "Plasarea celor " << n << " regine pe tabla\n";
    
    int a[8][8]; // Matrice de 8x8
    int v[8]; // Vector care retine pozitiile reginelor pe fiecare linie
    for (int i = 0; i < 8; i++) {
        v[i] = -1; // Initializare a vectorului v
    }
    
    back(n, a, v, 0);
    return 0;
}
