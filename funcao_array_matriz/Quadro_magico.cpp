// matriz
#include<iostream>
using namespace std;

int main(){
    int matrix[3][3];
    
    // lendo a matrix
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>matrix[i][j];
        }
    }

    int constante = matrix[0][0] + matrix[1][0] + matrix[2][0];

    if(constante == matrix[0][1] + matrix[1][1] + matrix[2][1]){
        if(constante == matrix[0][2] + matrix[1][2] + matrix[2][2]){
            if(constante == matrix[0][0] + matrix[0][1] + matrix[0][2]){
                if(constante == matrix[1][0] + matrix[1][1] + matrix[1][2]){
                    if(constante == matrix[2][0]+ matrix[2][1]+ matrix[2][2]){
                        if (constante == matrix[0][0] + matrix[1][1] + matrix[2][2] && constante == matrix[0][2] + matrix[1][1] + matrix[2][0]){
                            cout << "sim" << endl;
                        }else cout << "nao" << endl;
                    }else cout << "nao" << endl;
                }else cout << "nao" << endl;
            }else cout << "nao" << endl;
        }else cout << "nao" << endl;
    }else cout << "nao" << endl;
}