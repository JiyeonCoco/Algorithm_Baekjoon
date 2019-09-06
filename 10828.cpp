#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N = 0;
    string input;
    stack<int> s;

    std::cin >> N;

    for(int i=0; i<N; i++)
    {
        std::cin >> input;

        if(input == "push")
        {
            int inputNum = 0;
            std::cin >> inputNum;
            s.push(inputNum);
        }
        else if(input == "pop")
        {
            if(s.size() == 0)
                std::cout << -1 << endl;
            else
            {
                std::cout << s.top() << endl;
                s.pop();
            }
        }
        else if(input == "size")
        {
            std::cout << s.size() << endl;
        }
        else if(input == "empty")
        {
            if(s.size() == 0)
                std::cout << 1 << endl;
            else
                std::cout << 0 << endl;
        }
        else if(input == "top")
        {
            if(s.size() == 0)
                std::cout << -1 << endl;
            else
                std::cout << s.top() << endl;
        }
    }
}