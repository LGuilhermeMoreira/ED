// struct
/*
Ação: Seu programa deve então ler os valores dos registros dos dois alunos
 e fazer uso da função que imprime o nome do aluno e a maior nota
*/
#include<iostream>
#include<iomanip>
using namespace std;

struct boletin{
    string nome;
    int matricula;
    string cadeira;
    double media;

    void ler(){ // criando a função de ler
        getline(cin, nome);
        cin >> matricula;
        cin.ignore();
        getline(cin, cadeira);
        cin >> media;
        cin.ignore();
    }
};

int main(){
    boletin p1;
    boletin p2;
    p1.ler();
    p2.ler();

    // determinando quem tem maior nota
    if(p1.media > p2.media){
        cout << p1.nome << " , " << fixed << setprecision(1) << p1.media;
    }else if(p1.media < p2.media){
        cout << p2.nome << " , " << fixed << setprecision(1) << p2.media;
    }else if(p1.media == p2.media){
        cout << p1.nome << " e " << p2.nome << " , " << fixed << setprecision(1) << p1.media;
    }
}