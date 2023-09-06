#include <iostream>
#include <vector>

using namespace std;

// 소수판별기=> 소수일 경우, 0을 반환
int checkSosu(int a) {
    
    int detection;

    for(int i=2; i<a; i++){
        if(a%i==0){
            // 소수가 아닌 자연수
            detection = -1;
            break;
        } else{
            // 소수
            detection = 0;
        }
    }
    
    return detection;
}

vector<int> FindTwoSosu(int n){
    
    vector<int> result;
    
    for(int b=(n-1); b>1; b -= 2){
        
        int a = n-b;

        if(checkSosu(a) == 0 && checkSosu(b) == 0){
            // a, b가 소수일 때
            result.push_back(a);
            result.push_back(b);
            break;
        }
    }
    return result;
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // n: 4이상의 짝수
    int n;
    
    // 0이 들어와야 멈출 수 있음
    while(true) {
        cin >> n;
        if(n==0){
            break;
        }
        
        // 더해서 n을 만들 수 있는 두 소수
        vector<int> getTwoSosu = FindTwoSosu(n);
        
        if(getTwoSosu.empty()) {
            cout << "Goldbach's conjection is wrong" <<"\n";
        } else {
            cout << n << " = " << getTwoSosu[0] << " + " << getTwoSosu[1] << "\n";
        }
    }
    
    return 0;
}

