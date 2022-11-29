#include <iostream>
#include <string>
#include <stack>
using namespace std;

void mostra_floresta(string *floresta, int linha){
    for(int i =0; i < linha; i++){
        cout << floresta[i] << endl;
    }
}

//enquanto a pilha não estiver vazia faça
    //pegue topo da pilha

//    faça uma lista com todos os vizinhos de topo que podem ser queimados
  //  se lista eh vazia
        //desempilhe
    //senão
    //  escolha um dos vizinhos
        //queime
        //empilhe

void tacar_fogo(string *floresta, int num_linha, int num_coluna,int linha_,int coluna_,stack<int> &pilha){
    // iniciando a pilha
    pilha.push(linha_);
    pilha.push(coluna_);

    while(!pilha.empty()){
        coluna_ = pilha.top();
        pilha.pop();
        linha_ = pilha.top();
        pilha.pop();

        if(linha_ < 0 || linha_ >= num_linha || coluna_ < 0 || coluna_ >= num_coluna){
            continue;
        }
        if(floresta[linha_][coluna_] != '#'){
            continue;
        }
        floresta[linha_][coluna_] = 'o';

        //tacando fogo nas linhas(horizontal) e colunas(vetical)
        pilha.push(linha_+1);
        pilha.push(coluna_);
        pilha.push(linha_-1);
        pilha.push(coluna_);
        pilha.push(linha_);
        pilha.push(coluna_+1);
        pilha.push(linha_);
        pilha.push(coluna_-1);
    }
}

int main(){
    stack<int> pilha;
    int num_linha = 0, num_coluna = 0, linha_fogo = 0, coluna_fogo = 0;
    cin >> num_linha; 
    cin >> num_coluna; 
    cin >> linha_fogo; 
    cin >> coluna_fogo;
    string* floresta = new string[num_linha];

    
    for(int i = 0; i < num_linha; ++i){
        string linha;
        cin >> linha;
        floresta[i] = linha;
    }

    tacar_fogo(floresta,num_linha,num_coluna,linha_fogo,coluna_fogo,pilha);
    mostra_floresta(floresta,num_linha);

    delete[] floresta;
}
