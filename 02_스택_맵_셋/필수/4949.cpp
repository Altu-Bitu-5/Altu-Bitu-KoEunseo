#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 이전 괄호를 반환해주는 함수
char prevBracket(stack<char> bracket) {

    char previous_value;

    if (bracket.size() < 2) {
        previous_value = 'e';
    }
    else {
        bracket.pop();
        previous_value = bracket.top();
    }

    return previous_value;
}

int main() {

    while (true) {

        // 괄호의 종류를 저장하는 스택
        stack<char> bracket;

        // 입력값
        string exm;

        getline(cin, exm);
        if (exm == ".") {
            break;
        }

        for (char c : exm) {

            // 입력받은 값을 한 자씩 가져오기
            if (c == '(' || c == ')' || c == '[' || c == ']') {
                bracket.push(c);
            }

            char previous_bracket = prevBracket(bracket);

            // 이전 괄호와 짝이 맞는 경우 괄호 한쌍을 pop
            if ((c == ']' && previous_bracket == '[') || (c == ')' && previous_bracket == '(')) {
                bracket.pop();
                bracket.pop();
            }
        }

        if (bracket.empty()) {
            cout << "yes \n";
        }
        else {
            cout << "no \n";
        }
    }

    return 0;
}
