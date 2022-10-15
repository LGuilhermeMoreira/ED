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

ForwardList::ForwardList()
{
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList &lst)
{
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while (lstCurrent != nullptr)
    {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const
{
    return m_head->next == nullptr;
}

int ForwardList::size() const
{
    return m_size;
}

void ForwardList::clear()
{
    while (m_head->next != nullptr)
    {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList()
{
    clear();
    delete m_head;
}

Item &ForwardList::operator[](int index)
{
    int count = 0;
    Node *current = m_head->next;
    while (count < index)
    {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item &ForwardList::operator[](int index) const
{
    int count = 0;
    Node *current = m_head->next;
    while (count < index)
    {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item &val)
{
    int count = 0;
    Node *current = m_head;
    while (count < index)
    {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index)
{
    int count = 0;
    Node *current = m_head;
    while (count < index)
    {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString()
{
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while (ptr != nullptr)
    {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 1
 ***********************************************************/
Item &ForwardList::front() // 0k
{
    // retorna um referencia para o primeiro elemento na lista
    return m_head->next->value;
}

const Item &ForwardList::front() const // ok
{
    // retorna uma referencia para o primeiro elemento na lista
    return m_head->next->value;
}

void ForwardList::push_front(const Item &val) // ok
{
    Node *aux = new Node(val, m_head->next); // inserindo um elemento no inicio da lista
    m_head->next = aux;
    m_size++;
}

void ForwardList::pop_front() // ok
{
    // deleta o primeiro elemento da lista
    delete m_head->next;
    m_head = m_head->next;
    m_size--;
}

Item &ForwardList::back() // ok
{
    // retorna uma referencia para o primeiro elemento da lista
    Node *aux = m_head;

    while (aux->next != nullptr)
    {
        aux = aux->next;
    }

    return aux->value;
}

const Item &ForwardList::back() const // ok
{
    // retorna uma referencia para o primeiro elemento da lista
    Node *aux = m_head;

    while (aux->next != nullptr) // inicia aux com m_head e faz o while
    {
        aux = aux->next;
    } // dessa forma é possivel percorrer o vetor

    return aux->value;
}

void ForwardList::push_back(const Item &val) // ok
{
    // insere um elemento no final da lista

    Node *aux = m_head;

    while (aux->next != nullptr)
    {
        aux = aux->next;
    }

    Node *new_node = new Node(val, nullptr);

    aux->next = new_node;
    m_size++;
}

void ForwardList::pop_back() // ok
{
    // retira um elemento do final da lista
    Node *aux = m_head;

    while (aux->next->next != nullptr)
    {
        aux = aux->next;
    }

    delete aux->next;
    aux->next = nullptr;

    // m_head = m_head->next;
    m_size--;
}