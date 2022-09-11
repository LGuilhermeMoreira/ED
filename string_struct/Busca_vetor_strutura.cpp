// struct
#include<iostream>
#include<iomanip>
using namespace std;

struct aluno{
    int matricula;
    string nome;
    float media;

    void ler(){
        cin >> matricula;
        cin.ignore();
        getline(cin, nome);
        cin >> media;
    }
};

int main(){
    int tamanho_vetor;
    cin >> tamanho_vetor;
    cin.ignore();
    aluno *estudante = new aluno[tamanho_vetor];

    for(int i = 0; i < tamanho_vetor; i++){ //lendo vetor
        estudante[i].ler();
    }

    int matricula;
    cin >> matricula;

    for(int i = 0; i < tamanho_vetor; i++){
        if(estudante[i].matricula == matricula){
            cout << estudante[i].nome << endl;
            cout << fixed << setprecision(1) << estudante[i].media << endl;
            return 0;
        }
    }
    cout << "NAO ENCONTRADA";
}