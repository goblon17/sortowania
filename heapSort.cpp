#include <stdio.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

void heapSort(int * tab, int l);
int N = 1000000;
std::string nazwa = "1000kV.txt ";

std::string tmp = "testy\\";
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
    heapSort(tab,N);
    auto finnish = std::chrono::steady_clock::now();
    std::cout << nazwa << "(ms) " <<  (std::chrono::duration_cast<std::chrono::nanoseconds>(finnish - start).count())/1000000.0  <<std::endl;
    return 0;
}

void zamien(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void stosuj(int * tab, int l, int i)
{
    int najw = i;
    int lewo = i*2 + 1;
    int prawo = i*2 + 2;

    if(lewo < l && tab[najw] < tab[lewo])
    {
        najw = lewo;
    }
    if(prawo < l && tab[najw] < tab[prawo])
    {
        najw = prawo;
    }

    if(najw != i)
    {
        zamien(tab[najw],tab[i]);
        stosuj(tab,l,najw);
    }
}

void heapSort(int * tab, int l)
{
    for(int i = l/2 - 1; i >= 0; i--)
        stosuj(tab,l,i);

    for(int i = l - 1; i >= 0; i--)
    {
        zamien(tab[i],tab[0]);
        stosuj(tab,i,0);
    }
}
