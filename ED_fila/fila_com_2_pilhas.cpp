#include<stack>
#include<iostream>
using namespace std;

int main(){
    int tamanho;
    cin >> tamanho;
    stack<int> prateleira,deposito;
    for(int i = 0; i < tamanho; i++){
        int num;
        cin >> num;

        if(num == 1){
            int num2;
            cin >> num2;
            deposito.push(num2);
        }
        else if(num == 2){
            prateleira.pop();
        }
        else if(num == 3){
            cout << prateleira.top() << endl;
        }
        if(prateleira.empty()){
            while(!deposito.empty()){
                prateleira.push(deposito.top());
                deposito.pop();
            }
        }
    }
}