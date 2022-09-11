// função
#include<bits/stdc++.h>
using namespace std;

float factorial(int n){
    if(n == 0) return 1;
    float resp = 1;
    while(n > 0){
        resp = resp * n;
        n--;
    }
    return resp;
}

float euler(int n){
    float resp = 1;
    while(n > 0){
        resp = resp + (1/factorial(n));
        n--;
    }
    return resp;
}

int main(){
    int num;
    cin >> num;
    cout << fixed << setprecision(6) << euler(num);
}