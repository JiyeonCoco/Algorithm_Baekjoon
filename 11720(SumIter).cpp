#include <iostream>
#include <string>

using namespace std;

int num[100] = { 0 };
int N = 0, sum = 0;

// num 배열 내의 모든 수의 합
void sumAll(int *num, int cnt)
{
    // num 배열 내의 모든 수의 합을 구했다면 함수 종료
    if(cnt == N)
    {
        return;
    }

    sum += num[cnt];
    sumAll(num, cnt+1);
}

int main()
{
    string input;

    std::cin >> N;
    std::cin >> input;

    // 문자열로 받은 input을 한 글자씩 쪼개서 int형으로 변환 후 num 배열에 저장
    for(int i=0; i<N; i++)
    {
        num[i] = input[i] - '0';
    }

    sumAll(num, 0);
    std::cout << sum << endl;
}