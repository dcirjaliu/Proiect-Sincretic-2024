#include<iostream>

const int n=8;    //setez 8 regine
int v[n];   //vectorul care pastreaza coloana fiecarei regine
int tabla_sah[n][n];    //matricea care reprezinta tabla de sah

/*Problema celor 8 regine: să se scrie un program care plasează 8 regine pe tabla de
șah, fără ca acestea să se atace reciproc*/

using namespace std;

//verificam daca putem plasa regina pe linia k, coloana v[k]
int PlasareCorecta(int k)
{
    for(int i=0;i<k;i++)
    {
        //verificam daca reginile sunt pe aceeasi coloana sau pe aceeasi diagonala
        if(v[i]==v[k]||v[i]-i==v[k]-k||v[i]+i==v[k]+k)
            return 0;   //plasare incorecta, reginile se ataca
    }

    return 1;   //plasare corecta, reginele nu se ataca
}

//functia de plasare a reginelor
void PlasareRegine(int k)
{
    if(k==n)    //daca am plasat toate reginele
    {
        memset(tabla_sah, 0, sizeof(tabla_sah));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i]==j)
                    tabla_sah[i][j]=1;  //plasam regina

                cout<<tabla_sah[i][j]<<" "; //afisam tabla
            }
        }

        return; //iesim din functie
    }

    //incercam sa plasam regina pe fiecare coloana a linei curente
    for(int i=0;i<n;i++)
    {
        v[k]=i; //plasam regina pe linia k, coloana i

        if(PlasareCorecta(k))   //daca plasare este sigura
            PlasareRegine(k+1); //plasam regina pe linia urmatoare
    }
}

int main()
{
    PlasareRegine(0);   //incepem cu linia 0

    return 0;
}