// função
/*
o algoritomo desenvolvido calcula o numero de euler baseado em
uma função fatorial.
*/
#include<bits/stdc++.h>
using namespace std;

float factorial(int n){ // retorna o fatorial de n
    if(n == 0) return 1;
    float resp = 1;
    while(n > 0){
        resp = resp * n;
        n--;
    }
    return resp;
}

float euler(int n){ // calcula o numero de euler
    float resp = 1;
    while(n > 0){
        resp = resp + (1/factorial(n));
        n--;
    }
    return resp;
}

int main(){
    int num;
    cin >> num; // le o numero
    cout << fixed << setprecision(6) << euler(num); // printa o numero de euler
}