// matriz
#include<bits/stdc++.h>
using namespace std;

int main(){
    int matrix[3][3],contador = 0;
    // lendo a matrix
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>matrix[i][j];
        }
    }

    // checando as condições
    if (matrix[0][0] > matrix[1][0])
        contador++;
    if (matrix[1][0] > matrix[2][0])
        contador++;
    if (matrix[0][1] > matrix[1][1])
        contador++;
    if (matrix[1][1] > matrix[2][1])
        contador++;
    if (matrix[0][2] > matrix[1][2])
        contador++;
    if (matrix[1][2] > matrix[2][2])
        contador++;
    
    cout << contador << endl;
}