// função
#include <iostream>
using namespace std;

bool primo(int i)
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
    for (int i = a; i <= b; i++)
    {
        if (primo(i) == 1)
        {
            cout << i << endl;
        }
    }
}