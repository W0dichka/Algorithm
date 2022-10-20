#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{  
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    // long long* mas = new long long[n];
    long long mas[300001];
    for(int i = 0; i < n; i++)
    {
        fin >> mas[i];
    }
    int q;
    string s;
    fin >> q;
    long long sum =0;
    int index1, index2;
    long long x;
    while(q != 0)
    {
        fin  >> s;
        if(s == "FindSum")
        {
            sum = 0;
            fin >> index1;
            fin >> index2;
            for(int i = index1; i < index2; i++)
            {
                sum += mas[i];
            }
            fout << sum <<endl;
        }
        else
        {
            fin >> index1;
            fin >> x;
            mas[index1] += x;
        }
        q--;
    }
}