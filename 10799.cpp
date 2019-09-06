#include <iostream>
#include <stack>

using namespace std;
int numStick = 0;

void cutStick(string input)
{
    stack<char> stick;
    char open = '(';
    char close = ')';

    for(int i=0; i<input.size(); i++)
    {
        if(input[i] == open)
        {
            stick.push(input[i]);
        }
        else if(input[i] == close)
        {
            stick.pop();
            if(input[i-1] == open)
                numStick += stick.size();
            else
                numStick ++;
        }
    }
}

int main()
{
    string input;

    std::cin >> input;
    cutStick(input);

    std::cout << numStick << endl;
}