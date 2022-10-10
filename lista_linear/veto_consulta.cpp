/*
Há um vetor de strings de entrada e um vetor de strings de consulta. 
Para cada sequência de consultas, determine quantas vezes ela ocorre na lista de sequências de entrada.
*/
#include <iostream>
#include <vector>
using namespace std;

int matchString(vector<string> a, string b)
{
    int cont = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b)
        {
            cont++;
        }
    }
    // cout << "valor de cont: " << cont << endl;
    return cont;
}

int main()
{
    int con, bus;
    vector<int> vec;
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

    for (int i = 0; i < bus; i++)
    {
        vec.push_back(matchString(consulta, busca[i]));
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            cout << vec[i];
            break;
        }
        cout << vec[i] << " ";
    }
    cout << endl;
}