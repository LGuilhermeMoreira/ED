/*Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas 
para compra de ingressos aumentou consideravelmente.
Como as filas estão cada vez maiores, pessoas menos pacientes tendem a 
desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga para outras pessoas.
Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela dão um passo a frente, 
sendo assim nunca existe um espaço vago entre duas pessoas.
A fila inicialmente contém N pessoas, cada uma com um identificador diferente.

Joãozinho sabe o estado inicial dela e os identificadores em ordem 
das pessoas que deixaram a fila.
Sabendo que após o estado inicial nenhuma pessoa entrou mais na fila, 
Joãozinho deseja saber o estado final da fila.

Seu programa deve imprimir uma linha contedo N-M inteiros com os 
identificadores das pessoas que permaneceram na fila, em ordem de chegada.
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> retonra_retirada(vector<int> &lista,vector<int> &retirada){
    for(int i = 0; i < retirada.size(); i++){
        auto it = lista.begin();
        int aux = retirada[i];
        
        for(int j = 0; j < lista.size(); j++){
            if(*it == aux){
                lista.erase(it);
            }else{
                it++;
            }
        }
    }

    return lista;
}



int main(){
    int num_fila,num_retirada;
    cin >> num_fila; // lento o tamanho da fila
    vector<int> fila; // criando vector
    
    for(int i=0;i<num_fila;i++){
        int temp;
        cin >> temp;
        fila.push_back(temp); // adicionando elementos na fila
    }

    cin >> num_retirada; // lendo o numero de retiradas

    vector<int> retirada; // criando vector

    for(int i=0;i<num_retirada;i++){ // vendo os numeros que deseja retirar
        int temp;
        cin >> temp;
        retirada.push_back(temp);
    }

    fila = retonra_retirada(fila,retirada); // retirando os numeros desejados

    for(int i = 0; i < fila.size(); i++){ // printando
        cout << fila[i] << " ";
    }

    cout << endl;
}