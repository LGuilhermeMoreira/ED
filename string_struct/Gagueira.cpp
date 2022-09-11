//string
#include <bits/stdc++.h>
using namespace std;

int eh_vogal(char n){
    if(n == 'A' || n == 'E' || n == 'I' || n == 'O' || n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u') return 1;
    return 0;
}

int main(){ 
    string frase,str_final = "";
    getline(std::cin, frase);
    stringstream buffer;
    buffer << frase;

    while(buffer >> frase){
        int contador = 0,caso_especifico_ = 0;
        string sub_str = "";
        if(frase.size() < 4){
            str_final += frase + " ";
        }
        else{
            for(int i =0 ; i < 1; i++){
                if(eh_vogal(frase[i]) == 0 && eh_vogal(frase[i+1]) == 0 && eh_vogal(frase[i+2]) == 1 && eh_vogal(frase[i+3]) ==1) contador = 0;
                else if(eh_vogal(frase[i]) == 0 && eh_vogal(frase[i+1]) == 0 && eh_vogal(frase[i+2]) == 1) contador = 1; 
                else if(eh_vogal(frase[i]) == 1 && eh_vogal(frase[i+1]) == 0 && eh_vogal(frase[i+2]) == 0) contador = 2;
                else if(eh_vogal(frase[i]) == 0 && eh_vogal(frase[i+1]) == 1 && eh_vogal(frase[i+2]) == 1) contador = 1;
                else if(eh_vogal(frase[i]) == 0 && eh_vogal(frase[i+1]) == 1 && eh_vogal(frase[i+2]) == 0) contador = 4;
            }

            if(contador == 0){
                str_final += frase + " ";
            }
            else if(contador == 1){
                for(int i=0; i<3; i++){
                    sub_str += frase[i];
                }
                str_final += sub_str+sub_str+frase + " ";
            }
            else if(contador == 2){
                sub_str = frase[0];
                str_final += sub_str+sub_str+frase + " ";
            }
            else{
                for(int i=0; i<2; i++){
                    sub_str += frase[i];
                }
                str_final += sub_str+sub_str+frase + " ";
            }
        }
    }
    for(int i=0; i+1 < str_final.length(); i++){
        cout << str_final[i];
    }
}