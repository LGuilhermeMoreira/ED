// string
#include <bits/stdc++.h>
using namespace std;

int eh_maiusculo(char n){
    if(isupper(n) == 1) return 1;
    return 0;
}

int eh_dif_letra(char n){
    if(isalpha(n) == 1) return 1;
    return 0;
}

int eh_letra(char n){
    if(isblank(n) == 1) return 1;
    return 0;
}


int eh_vogal(char n){
    if(n == 'A' || n == 'E' || n == 'I' || n == 'O' || n == 'U') return 1;
    return 0;
}

char retorna_direito(char n){
    if(n >= 97 && n <= 122)
        return n - 32;
    else
        return n+32;
}

int main(){ 
    string frase,print;
    getline(std::cin, frase);  
    char modular;
    cin >> modular;

    if(modular == 'M'){
        for(int i = 0; i < frase.size(); i++){
            if(frase[i] >= 97 && frase[i] <= 122){
                frase[i] -= 32;
            }
        }

    }
    else if(modular == 'm'){
        for(int i = 0; i < frase.size(); i++){
            if(frase[i] >= 65 && frase[i] <= 90){
                frase[i] += 32;
            }
        }

    }
    else if(modular == 'i'){
        for(int i = 0; i < frase.size(); i++){
            if(frase[i] >= 97 && frase[i] <= 122){
                frase[i] -= 32;
            }
            else if(frase[i] >= 65 && frase[i] <= 90){
                frase[i] += 32;
            }
        }

    }
    else if(modular == 'p'){
        frase[0] += 32;
        for(int i = 1; frase[i]; i++){
            if(isblank(frase[i]) != 0 && isalpha(frase[i+1]) != 0 && isblank(frase[i+2]) == 0){
                if(isupper(frase[i+1]) != 0){
                    i++;
                }else{
                frase[i+1] -= 32;
                }
            }
        }
    }
    cout << frase;
}
