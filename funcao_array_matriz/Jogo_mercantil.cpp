// array
/*
o algoritomo desenvolvido ler 3 vetores
sendo o primeiro que determina os valores reais,
o segundd que determina o chute do jogador1 e
o terceiro que determina o chute do jogador2.

condições de pontuação:
- caso o chute do jogador1 seja igual o valor real, o jogador1 pontua.
- caso o chute do jogador1 seja maior que o valor real e o jogador2 chute um valor maior,
  o jogador 2 porntua.
- caso o chute do jogador1 seja menor que o valor real e o jogador2 chute um valor menor,
  o jogador 2 porntua.
- caso o chute do jogador2 seja erado em relação o chute do jogador 1 e o valor real,
  o jogador 1 porntua.
*/
#include<iostream>
using namespace std;

int main(){
    // criando vetor
    int tamanho_vetor = 0;
    cin >> tamanho_vetor;
    float valor_real[tamanho_vetor];
    float chute_p1[tamanho_vetor];
    char chute_p2[tamanho_vetor];
    
    // lendo vetor
    for(int i=0; i<tamanho_vetor; i++){
        cin >> valor_real[i];
    }for(int i=0; i<tamanho_vetor; i++){
        cin >> chute_p1[i];
    }for(int i=0; i<tamanho_vetor; i++){
        cin.ignore() >> chute_p2[i];
    }
    
    // verificando as condições

    int jogador1 = 0, jogador2 = 0;
    for(int i=0; i<tamanho_vetor; i++){
        if(valor_real[i] == chute_p1[i]) jogador1++;
        else if(valor_real[i] > chute_p1[i] && chute_p2[i] == 'm') jogador1++;
        else if(valor_real[i] < chute_p1[i] && chute_p2[i] == 'M') jogador1++;
        else jogador2++;
    }
    
    // printando os resultados 
    if(jogador1 > jogador2) cout << "primeiro" << endl;
    else if(jogador1 == jogador2) cout << "empate" << endl;
    else cout << "segundo" << endl;
}