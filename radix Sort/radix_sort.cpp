#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int getMax(int *ord, int tamanho)
{
    int maax = ord[0];
    for (int i = 1; i < tamanho; i++)
        if (ord[i] > maax)
            maax = ord[i];
    return maax;
}

void countSort(int *ord, int tamanho, int ex)
{
    int output[tamanho]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < tamanho; i++)
        count[ (ord[i]/ex)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = tamanho - 1; i >= 0; i--)
    {
        output[count[ (ord[i]/ex)%10 ] - 1] = ord[i];
        count[ (ord[i]/ex)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < tamanho; i++)
        ord[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radix_sort(int ord[], int tamanho)
{
    // Find the maximum number to know number of digits
    int maximo = getMax(ord, tamanho);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int ex = 1; maximo/ex > 0; ex *= 10)
        countSort(ord, tamanho, ex);
}

void print(int *num, int tamanho ){
      for (int i = 0; i < tamanho; i++)
      {
           cout << num[i] << "\t";
      }
      cout << endl;
}

int main()
{
    int ord[100000];
    string file;
    cout << "Digite o nome do arquivo a ser ordenado: ";
    cin >> file;
    ifstream in(file);
    char numero[10];
    int tamanho = 0;
    while(!in.eof()){

        in >> numero;
        ord[tamanho] = atoi(numero);
       // if(ord[tamanho] > range)
         //   range = ord[tamanho];
        tamanho++;
    }

    radix_sort(ord, tamanho);
    print(ord, tamanho);
    return 0;
}
