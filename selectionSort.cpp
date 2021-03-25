#include <stdio.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

void selectionSort(int * tab, int l);
int N = 1000000;
std::string nazwa = "1000kV.txt ";

std::string tmp = "‪testy\\";
std::string sciezka = tmp+nazwa;

int main()
{
    std::ifstream plik;
    plik.open(sciezka);
    int * tab = new int [N];
    for(int i = 0; i < N; i++)
    {
        plik>>tab[i];
    }
    plik.close();
    auto start = std::chrono::steady_clock::now();
    selectionSort(tab,N);
    auto finnish = std::chrono::steady_clock::now();
    std::cout << nazwa << "(ms) " <<  (std::chrono::duration_cast<std::chrono::nanoseconds>(finnish - start).count())/1000000.0  <<std::endl;
    return 0;
}

int minimum(int * tab, int p, int l)
{
    int w = p, m = tab[p];
    for(int i = p+1; i < l; i++)
    {
        if(tab[i] < m)
        {
            m = tab[i];
            w = i;
        }
    }
    return w;
}

void selectionSort(int * tab, int l)
{
    int tmp;
    for(int i = 0; i < l-1; i++)
    {
        int j = minimum(tab,i,l);
        tmp = tab[j];
        tab[j] = tab[i];
        tab[i] = tmp;
    }
}
