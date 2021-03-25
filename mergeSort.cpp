#include <stdio.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

void mergeSort(int * tab, int l, int p);
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
    mergeSort(tab, 0, N-1);
    auto finnish = std::chrono::steady_clock::now();
    std::cout << nazwa << "(ms) " <<  (std::chrono::duration_cast<std::chrono::nanoseconds>(finnish - start).count())/1000000.0  <<std::endl;
    return 0;
}

void scal(int * tab, int l, int s, int p)
{
    int A = s - l + 1;
    int B = p - s;
    int tmp_arr1[A], tmp_arr2[B];
    for(int i = 0; i < A; i++)
    {
        tmp_arr1[i] = tab[l + i];
    }
    for(int i = 0; i < B; i++)
    {
        tmp_arr2[i] = tab[s + i + 1];
    }
    int i = 0, j = 0, k = l;
    while(i < A && j < B)
    {
        if(tmp_arr1[i] < tmp_arr2[j])
        {
            tab[k] = tmp_arr1[i];
            i++;
        }
        else
        {
            tab[k] = tmp_arr2[j];
            j++;
        }
        k++;
    }
    while(i < A)
    {
        tab[k] = tmp_arr1[i];
        i++;
        k++;
    }
    while(j < B)
    {
        tab[k] = tmp_arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int * tab, int l, int p)
{
    if(l>=p)
    {
        return;
    }
    int s = ( l + p ) / 2;
    mergeSort(tab,l,s);
    mergeSort(tab,s+1,p);
    scal(tab,l,s,p);
}
