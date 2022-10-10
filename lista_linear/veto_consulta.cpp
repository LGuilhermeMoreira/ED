/*
Há um vetor de strings de entrada e um vetor de strings de consulta. 
Para cada sequência de consultas, determine quantas vezes ela ocorre na lista de sequências de entrada.
*/
#include <iostream>
#include <vector>
using namespace std;

int compara_string(vector<string> a, string b)
{
    int cont = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b)
        {
            cont++;
        }
    }
    return cont;
}

int *matchString(vector<string> a, vector<string> b)
{
    int *aux = new int[b.size()];

    for (int i = 0; i < b.size(); i++)
    {
        aux[i] = compara_string(a, b[i]);
    }

    return aux;
}

int main()
{
    int con, bus;
    int *v = nullptr;
    cin >> con;
    cin.ignore();

    vector<string> consulta(con);

    for (int i = 0; i < con; i++)
    {
        cin >> consulta[i];
        cin.ignore();
    }

    cin >> bus;
    vector<string> busca(bus);

    for (int i = 0; i < bus; i++)
    {
        cin >> busca[i];
        cin.ignore();
    }

    v = matchString(consulta, busca);

    for (int i = 0; i < bus; i++)
    {
        if (i == bus - 1)
        {
            cout << v[i];
            break;
        }
        cout << v[i] << " ";
    }

    cout << endl;
}