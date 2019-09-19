#include <iostream>
#include <queue>

using namespace std;
int N, K = 0;
int curTime[100001] = { 0 };

int BFS()
{
    queue<int> q;
    q.push(N);

    while(!q.empty())
    {
        int pos = 0;
        int curPos = q.front();
        q.pop();

        if(curPos == K)
            return curTime[curPos];

        // front
        pos = curPos + 1;

        if(pos <= 100000)
        {
            if(curTime[pos] == 0)
            {
                q.push(pos);
                curTime[pos] = curTime[curPos] + 1;
            }
        }

        // back
        pos = curPos - 1;

        if(pos >= 0)
        {
            if(curTime[pos] == 0)
            {
                q.push(pos);
                curTime[pos] = curTime[curPos] + 1;
            }
        }

        // magic
        pos = curPos * 2;

        if(pos <= 100000)
        {
            if(curTime[pos] == 0)
            {
                q.push(pos);
                curTime[pos] = curTime[curPos] + 1;
            }
        }
    }
    return 0;
}

int main()
{
    std::cin >> N >> K;

    std::cout << BFS() << endl;
}