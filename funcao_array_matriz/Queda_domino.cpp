// array
#include<iostream>
using namespace std;


int main(){
    int tamanho_vetor;
    cin >> tamanho_vetor;
    int v[tamanho_vetor]; // criando o array
    int contador = 0;

    for(int i=0; i<tamanho_vetor; i++){ // lendo o array
        cin >> v[i];
    }

    for(int i=1; i<tamanho_vetor; i++){ // verificando
        if(v[i] >= v[i-1]){
            contador++;
        }
    }

    if(contador == tamanho_vetor-1){
        cout << "ok" << endl;
    }else{
        cout << "precisa de ajuste" << endl;
    }
}