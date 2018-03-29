#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void count_sort(int *ord, int tamanho, int range)
{
    int count[range]={0};
    int aux[tamanho];

    for(int i = 0; i < tamanho; i++)
        ++count[ord[i]];

    for(int j = 1; j < range; j++)
        count[j]+=count[j-1];

    for (int i = tamanho-1; i >=0; i--)
    {
        aux[count[ord[i]]-1] = ord[i];
        --count[ord[i]];
    }

    for(int j = 0; j<tamanho; j++){
        ord[j]=aux[j];
    }
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
    int range = 10000000;
    while(!in.eof()){

        in >> numero;
        ord[tamanho] = atoi(numero);
       // if(ord[tamanho] > range)
         //   range = ord[tamanho];
        tamanho++;
    }
    cout << tamanho << endl << endl;
    count_sort(ord, tamanho, range);
    cout << tamanho << endl << endl;

    print(ord, tamanho);
    return 0;
}



