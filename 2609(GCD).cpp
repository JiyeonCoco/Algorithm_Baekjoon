#include <iostream>

using namespace std;
int t, n, gcd = 0;
int num[100] = { 0 };

int GCD(int n1, int n2)
{
    if(n2 == 0)
        return n1;
    else
        return GCD(n2, n1%n2);
}

int main()
{
    int num1, num2 = 0;

    std::cin >> num1 >> num2;

    int gcd = GCD(num1, num2);
    std::cout << gcd << endl;
    std::cout << (num1 / gcd) * (num2 / gcd) * gcd << endl;
}