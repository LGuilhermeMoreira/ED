// struct
#include<iostream>
using namespace std;

struct apr_repro{
    string nome;
    int matricula;
    string cadeira;
    double media;

    void ler(string *nome,double *media,int *matricula, string *cadeira){
        getline(cin,*nome);
        cin >> *matricula;
        cin.ignore();
        getline(cin,*cadeira);
        cin >> *media;
    }

    void mostra(double med){
        if(med >= 7){
            cout << nome << " aprovado(a) em " << cadeira << endl;  
        }
        else{
            cout << nome << " reprovado(a) em " << cadeira << endl;
        }
    }
};

int main(){
    apr_repro aluno;
    aluno.ler(&aluno.nome,&aluno.media,&aluno.matricula,&aluno.cadeira);
    aluno.mostra(aluno.media);
}