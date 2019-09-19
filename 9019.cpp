#include <iostream>
#include <queue>
#include <string>

using namespace std;
int T, A, B = 0;


string BFS()
{
    int num = 0;
    int seen[10001] = { 0 };
    queue<pair<int, string>> q;

    q.push(make_pair(A, ""));
    seen[A] = 1;

    while(!q.empty())
    {
        int curNum = q.front().first;
        string curRes = q.front().second;
        q.pop();

        if(curNum == B)
            return curRes;

        // D
        {
            num = 2 * curNum;
            if(num > 9999)
                num %= 10000;

            if(seen[num] == 0)
            {
                seen[num] = 1;
                q.push(make_pair(num, curRes + 'D'));
            }
        }

        // S
        {
            num = curNum - 1;
            if(num < 0)
                num = 9999;

            if(seen[num] == 0)
            {
                seen[num] = 1;
                q.push(make_pair(num, curRes + 'S'));
            }
        }

        // L
        {
            num = (10 * (curNum % 1000)) + (curNum / 1000);

            if(seen[num] == 0)
            {
                seen[num] = 1;
                q.push(make_pair(num, curRes + 'L'));
            }
        }

        // R
        {
            num = (curNum / 10) + (1000 * (curNum % 10));

            if(seen[num] == 0)
            {
                seen[num] = 1;
                q.push(make_pair(num, curRes + 'R'));
            }
        }
    }
    return "";
}

int main()
{
    std::cin >> T;

    for(int i=0; i<T; i++)
    {
        std::cin >> A >> B;
        std::cout << BFS() << endl;
    }
}