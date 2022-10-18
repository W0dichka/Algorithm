#include <iostream>
#include <fstream>

using namespace std;  

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt"); // 0-n 1-m
    int n;
    fin >> n;
    int** matrix;
    matrix = new int* [n+1];
    int** dim;
    dim = new int* [n+1];
    for (int i = 1; i < n+1; i++) 
    {
        matrix[i] = new int[n+1];
    }
    for (int i = 1; i < n+1; i++)
    {
        dim[i] = new int[2];
    }
    for (int i = 0; i < n; i++)
    {
        fin >> dim[i+1][0];
        fin >> dim[i+1][1];
    }
    for (int i = 1; i < n+1; i++)
    {
        matrix[i][i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        matrix[i][i + 1] = dim[i][0] * dim[i][1] * dim[i+1][1];
    }

    for(int j = 1; j < n - 1; j++)
    {
        for (int i = 1; i < n - j; i++)
        {
            matrix[i][i + 1 + j] = min(matrix[i][i+j] + dim[i][0] * dim[i + 1 + j][1] * dim[i + 1 + j][0] , matrix[i+1][i+j+1] + dim[i+j+1][1] * dim[i][0] * dim[i][1]);
        }
    }
    fout << matrix[1][n];
}