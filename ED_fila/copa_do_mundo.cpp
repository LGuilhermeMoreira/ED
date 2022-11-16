#include<stack>
#include<queue>
#include<iostream>
using namespace std;


int main(){
    queue<char> fila;

    for(int i = 0; i < 16; i++){
        fila.push(65 + i);
    }

    for(int i = 0; i < 15; i++){
        int num1,num2;
        char A,B;
        A = fila.front();
        fila.pop();
        B = fila.front();
        fila.pop();
        cin >> num1 >> num2;

        if(num1 > num2)
            fila.push(A);
        else
            fila.push(B);
    }
    cout << fila.front() << endl;
}