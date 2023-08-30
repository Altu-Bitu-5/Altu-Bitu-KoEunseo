#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string add(string a, string b) {
    
    int lenA = a.length();
    int lenB = b.length();
    // 각 자리의 수를 더해야 함 => A, B 중 더 큰 자릿수를 가진 놈을 실행횟수로 설정
    int execution_num = max(lenA, lenB);
    
    // 각 자릿수의 합
    int each_sum;
    // A+B의 값
    string total_sum;
    
    // 일의 자리부터 구하기 위해 설정한 수 => lenA-x
    int x = 1;
    // 자리 올림 (each_sum이 10이상인 경우를 위해 설정)
    int up = 0;
    
    // 각 자리를 더하는 과정
    while(execution_num--){

        int each_A = (lenA-x)<0 ? 0 : stod(a.substr(lenA-x, 1));
        int each_B = (lenB-x)<0 ? 0 : stod(b.substr(lenB-x, 1));
        
        each_sum = each_A + each_B + up;
        
        if(each_sum >= 10){
            up = 1;
            each_sum -= 10;
        }
        else{
            up = 0;
        }
        
        total_sum += to_string(each_sum);
        
        if(execution_num==0 && up ==1){
            total_sum += '1';
        }
        
        x++;
        
    }
    reverse(total_sum.begin(), total_sum.end());
    return total_sum;
}
    


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 숫자 A, B 받기
    string A, B;
    cin >> A >> B;
    
    // add 함수 실행
    string sum = add(A, B);
    
    cout << sum;
    
    return 0;
}


