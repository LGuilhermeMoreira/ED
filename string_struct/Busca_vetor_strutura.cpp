// struct
/*
Ação: Leia um vetor de alunos e uma matrícula m,
 e em seguida percorra o vetor de alunos procurando o primeiro aluno que possui matrícula igual a m. 
 Ao encontrar o aluno com matrícula m, imprima o nome e a média do aluno. 
 Se nenhum aluno tem matrícula m, imprima "NAO ENCONTRADA".
*/
#include<iostream>
#include<iomanip>
using namespace std;

struct aluno{
    int matricula;
    string nome;
    float media;

    void ler(){ // criando a função de ler
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
        if(estudante[i].matricula == matricula){ // determina se tem matricula
            cout << estudante[i].nome << endl;
            cout << fixed << setprecision(1) << estudante[i].media << endl;
            return 0;
        }
    }
    cout << "NAO ENCONTRADA";
}