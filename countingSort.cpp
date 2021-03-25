#include <stdio.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void countingSort(int * tab, int n, int p, int k);
int N = 1000000;
std::string nazwa = "1000kV.txt";

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
    countingSort(tab,N,0,RAND_MAX);
    auto finnish = std::chrono::steady_clock::now();
    std::cout << nazwa << " (ms) " <<  (std::chrono::duration_cast<std::chrono::nanoseconds>(finnish - start).count())/1000000.0  <<std::endl;
    return 0;
}

void countingSort(int * tab, int n, int p, int k)
{
    int tmp_tab [k - p+1];
    for(int i = 0; i < k-p+1; i++)
        tmp_tab[i] = 0;
    for(int i = 0; i < n; i++)
    {
        if(tab[i]-p<k-p+1)
            tmp_tab[tab[i]-p]++;
        else
            printf("%d\n%d\n%d\n\n",tab[i],tab[i]-p,i);
    }
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        while(j < k-p+1 && tmp_tab[j] == 0)
            j++;
        tab[i] = p+j;
        tmp_tab[j]--;
    }
}
