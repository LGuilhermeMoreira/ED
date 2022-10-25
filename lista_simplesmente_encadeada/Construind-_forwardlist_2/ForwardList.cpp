/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
//#include<iostream>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 2
 ***********************************************************/

void ForwardList::concat(ForwardList& lst) { // ok
    Node *aux = m_head; 
    Node *aux_lst = lst.m_head->next; // apos o fim 

    while(aux->next != nullptr){ // chegando no final da lista aux OK
        aux = aux->next;
    }

    while(lst.m_size != 0){ // passando aux_lst para aux
        Node *new_node = new Node(aux_lst->value,nullptr);
        aux->next = new_node;
        aux_lst = aux_lst->next;
        aux = aux->next;
        lst.m_size--;
    }

    while (lst.m_head->next != nullptr) // OK
    {
        Node *clear = lst.m_head->next;
        lst.m_head->next = clear->next;
        delete clear;
    }
    
    lst.m_size = 0;
}

void ForwardList::remove(const Item& val) { // 
    if(m_head->next != nullptr){ // caso a lista n esteja vazia 
        Node *ant = m_head; //inicializa atrás do aux  
        Node *aux = ant->next;

        /*
        while(aux->next != nullptr){
            if(aux->value == val){
                ant = aux->next;
                m_head->next = ant;
                delete aux;
                aux = ant->next;
            }
            if(ant->value == val){
                m_head->next = aux;
                delete ant;
                ant = aux->next;
            }
            else{
                aux = aux->next;
            }
        }*/

        while(aux != nullptr){
            if(aux->value == val){
                ant->next = aux->next;
                delete aux;
                aux = ant->next;
            }else{
                aux = aux->next;
                ant = ant->next;
            }
        }
    }
}

ForwardList* ForwardList::clone() { // ok
    // cria nova lista e clona LITERALMENTE :(

    // Devolve um ponteiro para uma copia desta lista.
    // Veja que uma copia nao eh a mesma lista, ela contem uma copia dos dados
    // Esta funcao deve ter complexidade O(n) no pior caso
    // Restrição: está proibido usar funções auxiliares nesta questão,
    // inclusive qualquer dos operadores sobrecarregados

    ForwardList *nova_lst = new ForwardList(); // criando lista

    Node *aux = m_head;
    Node *aux_lst = nova_lst->m_head;

    while(aux->next != nullptr){
        Node *novo = new Node(aux->next->value,nullptr);
        aux_lst->next = novo;
        aux = aux->next;
        aux_lst = aux_lst->next;
    }
   
    nova_lst->m_size = this->m_size;
    return nova_lst;
}

void ForwardList::appendVector(const std::vector<Item>& vec) { // ok
    // Copia os elementos do vector vec para o final da lista.
    // Esta funcao deve ter complexidade O(n) no pior caso
    // Restrição: está proibido usar funções auxiliares nesta questão,
    // inclusive qualquer dos operadores sobrecarregados
    // sequenica de pushback
    /*
         pushback 
        Node *aux = m_head;

        while (aux->next != nullptr)
        {
            aux = aux->next;
        }

        Node *new_node = new Node(val,nullptr);

        aux->next = new_node;
        m_size++;
    */
    Node *aux = m_head; // c1

    while(aux->next != nullptr){ // c2*n
        aux = aux->next;
    }

    for(int i = 0; i < vec.size(); i++){ // c3*n
        Node *new_node = new Node (vec[i],nullptr);
        aux->next = new_node;
        m_size++;
        aux = aux->next;
    }

}


void ForwardList::swap(ForwardList& lst) { // ok
    // Troca o conteudo dessa lista pelo conteudo de lst.
    // Os tamanhos das listas podem diferir.
    // Apos a chamada para esta funcao, os elementos nesta lista
    // sao aqueles que estavam em lst antes da chamada,
    // e os elementos de lst sao aqueles que estavam nesta lista.

    Node *aux = this->m_head;
    this->m_head = lst.m_head;
    lst.m_head = aux;
    
}

bool ForwardList::equals(const ForwardList& lst) const { //ok
    // Determina se a lista lst, passada por parametro, eh igual
    // a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho
    // e o valor do k-esimo elemento da primeira lista eh igual ao
    // k-esimo valor da segunda lista.
    // Restrição: está proibido usar funções auxiliares nesta questão,
    // inclusive qualquer dos operadores sobrecarregados
    if(this->m_size == lst.m_size){
        Node *aux = m_head;
        Node *aux_lst = lst.m_head;

        while(aux->next != nullptr){
            if(aux->next->value != aux_lst->next->value){ return false;}
            aux_lst = aux_lst->next;
            aux = aux->next;
        }

        return true;
    }
    return false;
}

void ForwardList::reverse() { // ok
    // preciso fazer o m_head ir para o final da lista e falar que o next dele recebe o anterior
    
    Node *percorre = m_head;
    Node *dps = nullptr; // depois
    Node *ants = nullptr; // antes
    Node *aux = nullptr;

    while(percorre->next != nullptr){ // percorre agr ta no final.
        percorre = percorre->next;
    }

    aux = m_head->next;

    while(aux != nullptr){ // trocando a ordem dos ponteiros
        dps = aux->next;
        aux->next = ants;
        ants = aux;
        aux = dps;
    }

    

    m_head->next = ants;
    
}

Item& ForwardList::get(int index) { //ok
    // retorna o elemento na posicao 'index'
    // Se index < 0 ou index >= m_size então lance uma excecao std::range_error com a
    // mensagem de erro "index out of range". Caso contrario retorne o elemento.
    // Sera preciso incluir o cabecalho <stdexcept> para a excecao ser reconhecida
    if(index < 0 || index >= m_size) std::range_error("index out of range");
    Node *aux = m_head->next;

    for(int i = 0; i < index; i++){
        aux = aux->next;    
    }

    return aux->value;
}

const Item& ForwardList::get(int index) const { //ok
    // retorna o elemento na posicao 'index'
    // Se index < 0 ou index >= m_size então lance uma excecao std::range_error com a
    // mensagem de erro "index out of range". Caso contrario retorne o elemento.
    // Sera preciso incluir o cabecalho <stdexcept> para a excecao ser reconhecida
    if(index < 0 || index >= m_size) std::range_error("index out of range");
    Node *aux = m_head->next;

    for(int i = 0; i < index; i++){
        aux = aux->next;    
    }

    return aux->value;
}