#include <iostream>
#include <stack>
#include <string>

using namespace std;

int VPS(string input)
{
    char open = '(';
    char close = ')';
    stack<char> str;

    for(int i=0; i<input.size(); i++)
    {
        if(input[i] == open)
        {
            str.push(input[i]);
        }
        else if(input[i] == close)
        {
            if(str.empty())
                return false;
            if(str.top() != open)
                return false;
            str.pop();
        }
    }
    return str.empty();
}

int main()
{
    int T = 0;
    string input;
    std::cin >> T;

    for(int i=0; i<T; i++)
    {
        std::cin >> input;

        if(VPS(input) == 1)
            std::cout << "YES" << endl;
        else
            std::cout << "NO" << endl;
    }
}