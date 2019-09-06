#include <iostream>

using namespace std;

// 한 줄 그대로 입력받기
// fgets(s, 100, stdin);
// scanf("%[^\n]\n", s);
// getline(cin, s);

int main()
{
    string s;

    while(getline(cin, s))
    {
        std::cout << s << endl;
    }
}