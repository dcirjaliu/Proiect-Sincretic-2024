#include<iostream>

int n=8;    //setez 8 regine

/*Problema celor 8 regine: să se scrie un program care plasează 8 regine pe tabla de
șah, fără ca acestea să se atace reciproc*/

using namespace std;

//voi marca tabla cu 0 intial, iar daca o regina este asezata voi inlocui cu 1

void InitializareMatrice(int n,int a[][8])  //intializarea matrice cu 0
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
}

int ReginaPlasataCorect(int n,int v[],int k)
{
    //v[]-vector care pastreaza coloanele in care sunt plasate reginele pe fiecare linie a tablei
    //v[i]=3 regina de pe linia i este plasata in coloana 3

    //verificam daca reginele se ataca pe aceeasi coloana sau diagonala
    for(int i=0;i<k;i++)
    {
        if(v[i]==v[k]||v[i]==v[k]+(k-i)||v[i]==v[k]-(k-i))
        {
            
        }
    }
}

int main()
{
   
    return 0;
}