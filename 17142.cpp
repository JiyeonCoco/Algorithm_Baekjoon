#include <iostream>
#include <vector>

using namespace std;
int lab[50][50] = { 0 };
int N, M, minTime = 0;

void checkBoundary(int i, int j)
{
    if(lab[i-1][j])
        lab[i-1][j] = 1;
    if(lab[i+1][j])
        lab[i+1][j] = 1;
    if(lab[i][j-1])
        lab[i][j-1] = 1;
    if(lab[i][j+1])
        lab[i][j+1] = 1;
}

void infection()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(lab[i][j] == 2 && lab[i-1][j] != -1)
            {



            }
        }
    }
}

int main()
{
    int status;

    std::cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cin >> status;

            if(status == 0)
                lab[i][j] = 0;
            else if(status == 1)
                lab[i][j] = -1;
            else if(status == 2)
                lab[i][j] = 1;
        }
    }

    lab[4][3] = 2;
    lab[6][0] = 2;
    lab[1][5] = 2;

    infection();

}