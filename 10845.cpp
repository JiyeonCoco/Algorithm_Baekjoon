#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N = 0, inputNum = 0;
    string input;
    queue<int> q;

    std::cin >> N;

    for(int i=0; i<N; i++)
    {
        std::cin >> input;

        if(input == "push")
        {
            std::cin >> inputNum;
            q.push(inputNum);
        }
        else if(input == "pop")
        {
            if(q.size() == 0)
                std::cout << -1 << endl;
            else
            {
                std::cout << q.front() << endl;
                q.pop();
            }
        }
        else if(input == "size")
        {
            std::cout << q.size() << endl;
        }
        else if(input == "empty")
        {
            if(q.size() == 0)
                std::cout << 1 << endl;
            else
                std::cout << 0 << endl;
        }
        else if(input == "front")
        {
            if(q.size() == 0)
                std::cout << -1 << endl;
            else
                std::cout << q.front() << endl;
        }
        else if(input == "back")
        {
            if(q.size() == 0)
                std::cout << -1 << endl;
            else
                std::cout << q.back() << endl;
        }
    }
}