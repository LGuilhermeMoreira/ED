// string
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    
    string frase;
    getline(cin, frase);

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