// string
#include<bits/stdc++.h>
using namespace std;

int main(){
    string frase,armazena,compara;
    getline(std::cin, frase);
    
    stringstream buffer;
    buffer << frase;
    buffer >> armazena;

    while(buffer >> compara){
        if(armazena < compara){
            armazena = compara;
        }else{
            cout << "nao" << endl;
            return 0;
        }
    }

    cout << "sim" << endl;
}