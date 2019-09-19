#include <iostream>
#include <queue>

using namespace std;
int matrix[100][100] = { 0 };
int seen[100] = { 0 };
queue<int> q;

void BFS(int n, int person1)
{
    seen[person1] = 1;
    q.push(person1);

    while(!q.empty())
    {
        int here = q.front();
        q.pop();

        for(int there=1; there<=n; there++)
        {
            if(matrix[here][there] == 1 && seen[there] == 0)
            {
                q.push(there);
                seen[there] = seen[here] + 1;
            }
        }
    }
}

int main()
{
    int n, n1, n2, m = 0;
    std::cin >> n >> n1 >> n2 >> m;

    while(m--)
    {
        int x, y = 0;
        std::cin >> x >> y;
        matrix[x][y] = 1;
        matrix[x][y] = 1;
    }

    BFS(n, n1);
    std::cout << seen[n2]-1 << endl;
}