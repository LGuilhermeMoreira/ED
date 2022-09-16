// string
/*
Ação: Que tal fazer um código que faz isso? Dado uma entrada de texto (max 100 char), 
apenas com minúsculo e espaço, faça o liaison das palavras. 
Há apenas um espaço entre as palavras e não existe espaço no começo ou fim da frase.
Se tiver 3 ou mais vogais juntas, então junte todas.
*/
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    
    string frase;
    getline(cin, frase); // lendo a frase

    for(int i = 0; i < frase.size();i++){
        // primeira condicional
        if(frase[i+1] == ' '){
            if(frase[i] != frase[i+2]){
                cout << frase[i];
            }else{
                cout << frase[i];
                i++;
                i++;
            }
        }else if(frase[i] == ' '){
            if(frase[i-1] != frase[i+1]){
                cout << frase[i];
            }

        }else if(frase[i-1] == ' '){
            if(frase[i] != frase[i-2]){
                cout << frase[i];
            }
        }else{
            cout << frase[i];
        }
    }

}