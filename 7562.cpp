#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int I, curX, curY, dstX, dstY = 0;
int seen[300][300] = { 0 };
int coordinates[8][2] = { {-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
                          { 1, -2}, { 2, -1}, { 1, 2}, { 2, 1} };

void BFS()
{
    queue<pair<int, int>> q;
    seen[curY][curX] = 1;
    q.push(make_pair(curY, curX));

    while(!q.empty())
    {
        int hereX = q.front().second;
        int hereY = q.front().first;
        q.pop();

        if(hereX == dstX && hereY == dstY)
            break;

        for(int i=0; i<8; i++)
        {
            int nextX = hereX + coordinates[i][1];
            int nextY = hereY + coordinates[i][0];

            if(nextX >= 0 && nextX < I && nextY >= 0 && nextY < I)
            {
                if(seen[nextY][nextX] == 0)
                {
                    q.push(make_pair(nextY, nextX));
                    seen[nextY][nextX] = seen[hereY][hereX] + 1;
                }
            }
        }
    }
}

int main()
{
    int T = 0;
    std::cin >> T;

    while(T--)
    {
        std::cin >> I;
        std::cin >> curX >> curY >> dstX >> dstY;
        BFS();
        std::cout << seen[dstY][dstX]-1 << endl;

        for(int i=0; i<I; i++)
        {
            for(int j=0; j<I; j++)
            {
                seen[i][j] = 0;
            }
        }
    }
}