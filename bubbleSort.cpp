#include <stdio.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

void bubbleSort(int * tab, int l);
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
    bubbleSort(tab,N);
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

void bubbleSort(int * tab, int l)
{
    for(int i = 0; i < l-1; i++)
    {
        for(int j = i+1; j < l; j++)
        {
            if(tab[i] > tab[j])
            {
                zamien(tab[i], tab[j]);
            }
        }
    }
}
