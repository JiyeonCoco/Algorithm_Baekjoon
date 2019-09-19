#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M = 0;
queue<pair<int, int>> q;
int maze[101][101] = { 0 };
int seen[101][101] = { 0 };
int coordinates[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void BFS()
{
    q.push(make_pair(0, 0));
    seen[0][0] = 1;

    while(!q.empty())
    {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nextX = hereX + coordinates[i][1];
            int nextY = hereY + coordinates[i][0];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
            {
                if(maze[nextX][nextY] == 1 && seen[nextX][nextY] == 0)
                {
                    q.push(make_pair(nextX, nextY));
                    seen[nextX][nextY] = seen[hereX][hereY] + 1;
                }
            }
        }
    }
}

int main()
{
    std::cin >> N >> M;
    string input;

    for(int i=0; i<N; i++)
    {
        std::cin >> input;

        for(int j=0; j<M; j++)
        {
            maze[i][j] = input[j] - '0';
        }
    }
    BFS();
    std::cout << seen[N-1][M-1] << endl;
}