/*
mplementar uma lista usando alocação sequencial (array). Sua lista deve ser redimensionável, 
ou seja, deve aumentar de tamanho automaticamente sempre que for necessário 
incluir um elemento e ela estiver cheia
*/
#include <iostream>
#include <sstream>
using namespace std;

// classe que implementa uma lista redimensionável
#include <iostream>
#include <sstream>
using namespace std;

// classe que implementa uma lista redimensionável
class Vector
{
private:
    int m_capacity{0}; // esse {} é o modo de inicializar default do c++ a partir do c++11
    int m_size{0};
    int *m_data{nullptr}; // inicializar pra não conter lixo

public:
    // construtor vazio
    Vector()
    {
        m_size = 0;
        m_capacity = 10;
        m_data = new int[m_capacity];
    }

    // construtor
    Vector(int capacity)
    {
        if (capacity <= 0)
            m_capacity = 10;
        else
            m_capacity = capacity;
        m_size = 0;
        m_data = new int[m_capacity];
    }

    // destrutor
    ~Vector()
    {
        delete[] m_data;
    }

    int size()
    {
        return m_size;
    }

    int capacity()
    {
        return m_capacity;
    }

    Vector(Vector &other)
    {
        this->m_capacity = other.m_capacity;
        this->m_size = other.m_size;

        if (m_data != nullptr)
        {
            delete[] this->m_data;
            m_data = nullptr;
        }
        this->m_data = new int[m_capacity];

        for (int i = 0; i < this->m_size; i++)
        {
            this->m_data[i] = other.m_data[i];
        }
    }

    const Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            this->m_capacity = other.m_capacity;
            this->m_size = other.m_size;

            if (this->m_data != nullptr)
                delete[] this->m_data;

            this->m_data = new int[m_capacity];

            for (int i = 0; i < this->m_size; i++)
            {
                this->m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }

    void push_back(int value)
    {
        if (m_capacity == m_size)
        {
            m_capacity = m_capacity * 2;
            int *new_ = new int[m_capacity];

            for (int i = 0; i < m_size; i++)
            {
                new_[i] = m_data[i];
            }

            delete[] m_data;
            m_data = nullptr;
            m_data = new_;
        }

        m_data[m_size] = value;
        m_size += 1;
    }

    int pop_back()
    {
        if (m_data == nullptr)
        {
            throw std::runtime_error("A lista está vazia");
        }
        else
        {
            int hop = m_data[m_size - 1];
            m_size--;
            if (m_size < m_capacity / 2)
            {
                m_capacity /= 2;
                int *v = new int[m_capacity];
                for (int i = 0; i < m_size; i++)
                    v[i] = m_data[i];
                delete[] m_data;
                m_data = nullptr;
                m_data = v;
            }
            return hop;
        }
    }

    std::string toString()
    {
        string aux = "[ ";

        // cout << m_size << endl;

        for (int i = 0; i < m_size; i++)
        {
            aux += to_string(m_data[i]) + " ";
        }
        aux += "]";

        return aux;
    }
};

/* NAO MEXA DAQUI PRA BAIXO */
//
int main()
{
    string line, cmd;
    int value;
    Vector v(0);
    while (true)
    {
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if (cmd == "end")
        {
            break;
        }
        else if (cmd == "init")
        {
            ss >> value;
            v = Vector(value);
        }
        else if (cmd == "status")
        {
            cout << "size:" << v.size() << " capacity:" << v.capacity() << "\n";
        }
        else if (cmd == "push_back")
        {
            while (ss >> value)
                v.push_back(value);
        }
        else if (cmd == "pop_back")
        {
            ss >> value;
            cout << "popped: ";
            for (int i = 0; i < value; ++i)
                cout << v.pop_back() << " ";
            cout << endl;
        }
        else if (cmd == "show")
        {
            cout << v.toString() << endl;
        }
        else
        {
            cout << "fail: comando invalido\n";
        }
    }
}