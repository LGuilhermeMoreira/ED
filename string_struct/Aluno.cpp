// struct
/*
Ação: Seu programa deve então ler os dados de um aluno usando registro
 e fazer uso da função que determina se o aluno foi aprovado ou não, 
 gerando o resultado correto.
*/
#include<iostream>
using namespace std;

struct apr_repro{
    string nome;
    int matricula;
    string cadeira;
    double media;

    void ler(string *nome,double *media,int *matricula, string *cadeira){ // criando a função de leitura
        getline(cin,*nome);
        cin >> *matricula;
        cin.ignore();
        getline(cin,*cadeira);
        cin >> *media;
    }

    void mostra(double med){ // criando a função de mostrar
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
    aluno.mostra(aluno.media); // determina se foi aprovado ou não
}