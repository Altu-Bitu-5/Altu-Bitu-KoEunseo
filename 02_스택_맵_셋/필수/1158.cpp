#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> Yo(int a, int b){
    
    vector<int> result; // 원에서 사람들이 제거되는 순서
    queue<int> circle;  // 원형 테이블 circle 생성
    
    // 원을 이루고 있는 사람들에게 고유 순번을 부여
    for(int i=0; i<a; i++){
        circle.push(i+1);
    }
    
    // 원형 테이블에 사람이 남아있지 않을 때까지 실행
    while(!circle.empty()){
        
        for(int i=0; i<b; i++){
            
            // b(죽을 순번)의 이전 값은 circle의 뒤로 보내야 함 => 순서대로(front에 있는 값부터) 다시 circle에 push
            // b(죽을 순번)은 result(제거된 순서)에 push하고, circle에는 존재하면 안되기 때문에 pop
            (i != b-1) ? (circle.push(circle.front()), circle.pop()) : (result.push_back(circle.front()), circle.pop());
            
        }
    }
    
    
    return result;
}



int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 총 정원: N명, 제거하고 싶은 순서: K번째
    int N, K;
    cin >> N >> K;
    
    // 요세푸스 순열을 실행시킬 수 있는 함수를 호출하고  vector 자료형의 result에 저장
    vector<int> result = Yo(N, K); 
    
    // result에 있는 모든 값을 출력
    cout << "<" << result[0];
    for(int i=1; i<N; i++){
        cout << ", " << result[i];
    }
    cout << ">";
    
    return 0;
}

