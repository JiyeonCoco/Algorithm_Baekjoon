#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int house[25][25] = { 0 };
int seen[25][25] = { 0 };
int cnt, totalCnt = 0;
vector<int> houseCnt;

int coord[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void DFS(int N, int hereX, int hereY)
{
    seen[hereX][hereY] = 1;

    for(int i=0; i<4; i++)
    {
        int nextX = hereX + coord[i][0];
        int nextY = hereY + coord[i][1];

        if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
        {
            if(seen[nextX][nextY] == 0 && house[nextX][nextY] == 1)
            {
                cnt++;
                DFS(N, nextX, nextY);
            }
        }
    }
}

int main()
{
    int N = 0;

    std::cin >> N;

    for(int i=0; i<N; i++)
    {
        string input;
        std::cin >> input;

        for(int j=0; j<N; j++)
        {
            if(input[j] == '0')
                house[i][j] = 0;
            else if(input[j] == '1')
                house[i][j] = 1;
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(seen[i][j] == 0 && house[i][j] == 1)
            {
                cnt = 1;
                DFS(N, i, j);
                totalCnt++;
                houseCnt.push_back(cnt);
            }
        }
    }
    std::cout << totalCnt << endl;

    sort(houseCnt.begin(), houseCnt.end());

    for(int k=0; k<houseCnt.size(); k++)
    {
        std::cout << houseCnt[k] << endl;
    }
}