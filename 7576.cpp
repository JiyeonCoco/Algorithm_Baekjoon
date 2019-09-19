#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int farm[1000][1000] = { 0 };
int seen[1000][1000] = { 0 };
queue<pair<int, int>> q;
int M, N = 0;
int minTime = 0;
int coordinates[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool checkTomato(int time)
{
    bool check = true;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(time == 0)
            {
                if(farm[i][j] == 0)
                {
                    check = false;
                    return check;
                }
            }
            else if(time == 1)
            {
                if(farm[i][j] == 0 && seen[i][j] == 0)
                {
                    check = false;
                    return check;
                }
            }
        }
    }
    return check;
}

void BFS()
{
    while(!q.empty())
    {
        int hereX = q.front().second;
        int hereY = q.front().first;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nextX = hereX + coordinates[i][1];
            int nextY = hereY + coordinates[i][0];

            if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N)
            {
                if(farm[nextY][nextX] == 0 && seen[nextY][nextX] == 0)
                {
                    q.push(make_pair(nextY, nextX));
                    seen[nextY][nextX] = seen[hereY][hereX] + 1;
                    minTime = max(minTime, seen[nextY][nextX]);
                }
            }
        }
    }
}

int main()
{
    int input = 0;
    std::cin >> M >> N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            std::cin >> input;
            farm[i][j] = input;

            if(input == 1)
            {
                q.push(make_pair(i, j));
                seen[i][j] = 1;
            }
        }
    }

    if(checkTomato(0))
    {
        std::cout << 0 << endl;
        return 0;
    }

    BFS();

    if(checkTomato(1))
        std::cout << minTime-1 << endl;
    else
        std::cout << -1 << endl;
}