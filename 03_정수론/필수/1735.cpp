#include <iostream>
#include<vector>

using namespace std;

// 분수의 합
vector<int> addFraction(int a, int b, int c, int d){
    
    int numerator = a*d+b*c;    // 연산 후 분자
    int denominator = b*d;      // 연산 후 분모
    
    vector<int> result;      // 분자, 분모 반환
    result.push_back(numerator); // 분자
    result.push_back(denominator); // 분모
    
    return result;
}

// 기약분수
vector<int> earlierFrac(int a, int b) {
    
    // 분자a와 분모b의 최대공약수 구하기
    int gcd;
    for(int i=min(a, b); i>0; i--){
        if(a%i == 0 && b%i==0){
            gcd = i;
            break;
        }
    }
    
    // 분자와 분모를 최대공약수로 나누기
    vector<int> result;
    result.push_back(a/gcd);
    result.push_back(b/gcd);
    return result;
}

int main(){
    
    int A, B;
    cin >> A >> B; // (앞)피연산자 => 분자, 분모
    
    int C, D;
    cin >> C >> D; // (뒤)피연산자 => 분자, 분모
    
    vector<int> sum = addFraction(A, B, C, D);          // 분수의 합
    vector<int> noDiv = earlierFrac(sum[0], sum[1]);    // 기약분수
    
    cout << noDiv[0] << " " << noDiv[1]; // 기약분수의 분자, 분모 출력
    
    return 0;
}