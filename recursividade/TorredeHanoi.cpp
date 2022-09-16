/*
o algoritomo desenvolvido descreve todos os paços para resolver uma torre\
de hanoi de n peças
*/

#include <iostream>
using namespace std;

void hanoi(int qte, char ini, char aux, char fim){
    if (qte == 0)
        return;
    if (qte == 1)
        cout << ini << " -> " << fim << endl;
    else
    {
        hanoi(qte - 1, ini, fim, aux);
        cout << ini << " -> " << fim << endl;
        hanoi(qte - 1, aux, ini, fim);
    }
}

int main(){
    int qte; 
    cin >> qte; // le a quantidade de peças
    hanoi(qte, 'A', 'B', 'C');
    return 0;
}