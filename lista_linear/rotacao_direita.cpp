/*desloca os elementos do vetor a direita*/
#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int> &vet, int nrot)
{
    if (nrot == 0)
        return;

    int aux = vet[vet.size() - 1]; // aux guarda o ultimo numero de vet

    for (int i = vet.size() - 1; i > 0; i--)
    {
        vet[i] = vet[i - 1];
    }

    vet[0] = aux; // girando uma unica vez o numero da direita

    nrot--;

    if (nrot > 0)
    {
        right_rotation(vet, nrot);
    }
}

void show(vector<int> &vet)
{
    cout << "[ ";
    for (int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main()
{
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for (int i = 0; i < size; i++)
        cin >> vet[i];

    right_rotation(vet, nrot);
    show(vet);
}