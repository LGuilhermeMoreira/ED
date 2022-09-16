// função
/*
o algoritomo desenvolvido determina quantos primos existe entre dois primos
*/
#include <iostream>
using namespace std;

bool primo(int i) // determina se o numero é primo
{
    if (i == 2)
        return true;
    else
    {
        int n = 2;
        while (n < i)
        {
            if (i % n == 0)
            {
                return false;
            }
            n++;
        }
        return true;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) // checa numero por numero incluindo o a e b
    {
        if (primo(i) == 1)
        {
            cout << i << endl;
        }
    }
}