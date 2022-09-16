// string 
/*
Analise cada palavra.

Regras:

Float tem o ponto.
Int não tem ponto.
Int e float podem ser negativos.
Se existir pelo menos um alfabético então é string.
*/
#include<bits/stdc++.h>
using namespace std;

bool eh_letra(char n){
    if((n > 64 && n < 91) || (n > 96 && n < 123)) return true;
    return false;
}

int main(){
    string frase,analizadora;
    getline(std::cin, frase);
    
    stringstream buffer;
    buffer << frase;

    
    while(buffer >> analizadora){
        int letra = 0,ponto = 0;
        for(int i = 0; i < analizadora.size(); i++){
            if(eh_letra(analizadora[i]) == true) letra++;
            else if(analizadora[i] == '.') ponto++;
        }
        if(ponto == 1 && letra == 0){
            cout << "float ";
        }
        else if(letra > 0){
            cout << "str ";
        }
        else{
            cout << "int ";
        }
    }
}