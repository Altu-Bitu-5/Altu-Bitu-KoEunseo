#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct serialCode
{
    string code;
};

// 자리수의 합 구하기
int addNum(serialCode a)
{
    int sum = 0;
    for (char c : a.code)
    {
        if (isdigit(c))
        {
            sum += c - '0';
        }
    }

    return sum;
}

// 비교
bool compareSort(const serialCode &a, const serialCode &b)
{
    // 길이순 정렬
    if (a.code.length() != b.code.length())
    {
        return a.code.length() < b.code.length();
    }

    // 자리수의 합 구하기
    int sumA = 0, sumB = 0;
    sumA = addNum(a);
    sumB = addNum(b);

    // 자리수의 합을 통해 정렬
    if (sumA != sumB)
    {
        return sumA < sumB;
    }

    // 사전순으로 정렬
    return a.code < b.code;
}

int main()
{

    // 기타의 수 ( = 시리얼 넘버의 수)
    int n;
    cin >> n;

    // 시리얼 넘버를 저장할 배열
    vector<serialCode> codeArr;

    // 크기 설정
    codeArr.assign(n, {});

    // 각 시리얼 넘버  입력
    for (int i = 0; i < n; i++)
    {
        cin >> codeArr[i].code;
    }

    // 길이&자리수의 합으로 정렬
    sort(codeArr.begin(), codeArr.end(), compareSort);

    // 정렬된 시리얼 번호 출력
    for (const serialCode &code : codeArr)
    {
        cout << code.code << "\n";
    }

    return 0;
}
