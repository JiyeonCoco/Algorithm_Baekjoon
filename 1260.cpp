#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int matrix[1000][1000] = { 0 };
vector<int> seen;
queue<int> q;

void DFS(int N, int here)
{
    seen[here] = 1;
    std::cout << here+1 << " ";

    for(int there=0; there<N; there++)
    {
        if(matrix[here][there] == 1 && seen[there] == 0)
        {
            DFS(N, there);
        }
    }
}

void BFS(int N, int here)
{
    seen[here] = 1;
    q.push(here);

    while(!q.empty())
    {
        int pos = q.front();
        std::cout << q.front()+1 << " ";
        q.pop();

        for(int there=0; there<N; there++)
        {
            if(matrix[pos][there] == 1 && seen[there] == 0)
            {
                q.push(there);
                seen[there] = 1;
            }
        }
    }
}

int main()
{
    int N, M, V = 0;
    int input[2] = { 0 };
    std::cin >> N >> M >> V;

    for(int i=0; i<M; i++)
    {
        std::cin >> input[0] >> input[1];
        matrix[input[0]-1][input[1]-1] = 1;
        matrix[input[1]-1][input[0]-1] = 1;
    }

    seen = vector<int>(N, 0);
    DFS(N, V-1);
    std::cout << endl;
    seen = vector<int>(N, 0);
    BFS(N, V-1);
}