#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> network;
vector<int> seen;
int virusNum = 0;

void DFS(int num, int here)
{
    seen[here] = 1;

    for(int there=0; there<num; there++)
    {
        if(network[here][there] == 1 && seen[there] == 0)
        {
            virusNum++;
            DFS(num, there);
        }
    }
}

int main()
{
    int num, pair = 0;
    int input[2] = { 0 };

    std::cin >> num;
    std::cin >> pair;

    network = vector<vector<int>>(num, vector<int>(num, 0));
    for(int i=0; i<pair; i++)
    {
        for(int j=0; j<2; j++)
        {
            std::cin >> input[j];
        }
        network[input[0]-1][input[1]-1] = 1;
        network[input[1]-1][input[0]-1] = 1;
    }

    seen = vector<int>(num, 0);
    DFS(num, 0);

    std::cout << virusNum << endl;
}