#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
adicionar as virgulas e tem que printar no final o vetor inicial no fim
*/
void piramide(vector<int> a, int size)
{
    if (size - 1 == 0)
        return;

    vector<int> aux;

    for (int i = 1; i <= size - 1; i++)
    {
        aux.push_back(a[i] + a[i - 1]);
    }

    piramide(aux, aux.size());

    cout << "[";
    for (int i = 0; i < aux.size(); i++)
    {
        if (i == aux.size() - 1)
        {
            cout << aux[i];
            break;
        }
        cout << aux[i] << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    int tamanho;
    cin >> tamanho;
    vector<int> vetor;

    for (int i = 0; i < tamanho; i++)
    {
        int resp;
        cin >> resp;
        vetor.push_back(resp);
    }

    piramide(vetor, vetor.size());

    cout << "[";
    for (int i = 0; i < tamanho; i++)
    {
        if (i == tamanho - 1)
        {
            cout << vetor[i];
            break;
        }
        cout << vetor[i] << ", ";
    }
    cout << "]" << endl;
}