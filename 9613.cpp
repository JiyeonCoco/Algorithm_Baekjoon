#include <iostream>

using namespace std;

int GCD(int n1, int n2)
{
    if(n2 == 0)
        return n1;
    else
        return GCD(n2, n1%n2);
}

int main()
{
    int t = 0;
    std::cin >> t;

    for(int i=0; i<t; i++)
    {
        int n = 0;
        int num[100] = { 0 };
        std::cin >> n;

        for(int j=0; j<n; j++)
        {
            std::cin >> num[j];
        }
        long gcd = 0;

        for(int x=0; x<n-1; x++)
        {
            for(int y=x+1; y<n; y++)
            {
                gcd += GCD(num[x], num[y]);
            }
        }
        std::cout << gcd << endl;
    }
}