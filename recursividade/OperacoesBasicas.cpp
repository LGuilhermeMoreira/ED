/*
Leia um vetor de inteiros e implemente as funções sem utilizar laço para iterar sobre os elementos

SAIDAS:
vet: o vetor
rvet: o vetor impresso ao contrário
sum: a soma dos elementos
mult: a multiplicação dos elementos
min: o menor elemento
inv: inverte o vetor, depois imprime ele invertido
*/
#include <sstream> //cabeçalho que contém o tipo de dado stringstream
#include <vector>  //cabeçalho que contém a estrutura de dados vector
#include <string>
#include <iostream>
#include <climits>
using namespace std;

// variaveis globais
vector<int> bob;

// vet
void vet(vector<int> a, int tamanho, int ini)
{ // roda o vetor do começo ao fim
    if (ini == tamanho)
    {
        cout << a[ini] << " ";
        return;
    }
    else
    {
        cout << a[ini] << " ";
        return vet(a, tamanho, ini + 1);
    }
}

void retorna_vet(vector<int> a, int tamanho, int ini)
{
    cout << "vet : [ ";
    vet(a, tamanho - 1, ini);
    cout << "]" << endl;
}

// rvet
void rvet(vector<int> a, int tamanho)
{ // roda o vetor do final para o inicio
    if (tamanho < 0)
    {
        return;
    }
    else
    {
        cout << a[tamanho] << " ";
        return rvet(a, tamanho - 1);
    }
}

void retorna_rvet(vector<int> a, int tamanho)
{
    cout << "rvet: [ ";
    rvet(a, tamanho - 1);
    cout << "]" << endl;
}

// sum
int sum(vector<int> a, int soma, int tamanho)
{ // soma os dados do vetor
    if (tamanho < 0)
    {
        return soma;
    }
    else
    {
        soma += a[tamanho];
        return sum(a, soma, tamanho - 1);
    }
}

void retorna_sum(vector<int> a, int tamanho, int soma)
{
    cout << "sum : " << sum(a, soma, tamanho - 1) << endl;
}

// mult
int mult(vector<int> a, int multi, int tamanho)
{ // multiplica os dados do vetor
    if (tamanho < 0)
    {
        return multi;
    }
    else
    {
        multi *= a[tamanho];
        return mult(a, multi, tamanho - 1);
    }
}

void retorna_mult(vector<int> a, int tamanho, int multi)
{
    cout << "mult: " << mult(a, multi, tamanho - 1) << endl;
}

// min
int min(vector<int> a, int tamanho, int resp)
{ // encontra o menor numero do vetor
    if (tamanho < 0)
    {
        return resp;
    }
    else
    {
        if (resp > a[tamanho])
        {
            resp = a[tamanho];
        }
        return min(a, tamanho - 1, resp);
    }
}

void retorna_min(vector<int> a, int tamanho, int resp)
{
    cout << "min : " << min(a, tamanho - 1, resp) << endl;
}

// inv
void inv(vector<int> a, int tamanho, int ini)
{ // inverte o novo vetor
    if (ini == tamanho)
    {
        bob.push_back(a[ini]);
        return;
    }
    else
    {
        bob.push_back(a[ini]);
        return inv(a, tamanho, ini + 1);
    }
}

void recebe_inv(vector<int> a, int tamanho)
{
    if (tamanho < 0)
        return;
    else
    {
        cout << a[tamanho] << " ";
        return recebe_inv(a, tamanho - 1);
    }
}

void printa_inv(vector<int> a, int tamanho)
{
    cout << "inv : [ ";
    recebe_inv(a, tamanho - 1);
    cout << "]" << endl;
}

// main
int main()
{
    string num_str;
    getline(cin, num_str); // lendo os numeros

    stringstream buffer;
    buffer << num_str;

    int num = 0, contador = 0, soma = 0;
    vector<int> array;

    while (buffer >> num)
    { // vector recebe os numeros digitados
        array.push_back(num);
        contador++;
    }

    // vet
    retorna_vet(array, contador, 0);
    // rvet
    retorna_rvet(array, contador);
    // sum
    retorna_sum(array, contador, 0);
    // mult
    retorna_mult(array, contador, 1);
    // min
    retorna_min(array, contador, INT_MAX);
    // inv
    inv(array, contador - 1, 0); // inverte
    printa_inv(bob, contador); // printa 
}