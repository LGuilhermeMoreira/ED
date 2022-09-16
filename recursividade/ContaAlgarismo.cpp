/*
o algoritomo conta quantos caracteres n estão presentes na frase
digitada pelo usuário
*/
#include <iostream>
#include <string>
using namespace std;
int resp = 0;

int contaCaracteres(string str, int n, char c){
    if(n == 0){ // caso for o ultimo caractere da frase
        if(str[0] == c) // se ele for igual, eu incremento o contador
            resp++;
        return resp; // retorno a resposta
    }else{ // caso nõa for o ultimo caractere da frase
        if(str[n] == c){ // se ele for igual, eu incremento o contador
            resp++;
        }
        return contaCaracteres(str,n-1,c);
    }
}

int main(){
    string frase;
    getline(cin,frase); // lendo a frase
    
    char letra;
    cin >> letra; // lendo caractere

    cout << contaCaracteres(frase,frase.length(),letra); // printando a qantidade de caractere n estão presentes na frase
}