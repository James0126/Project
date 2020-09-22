#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int index = 0;
    for(int j = 0; j < arr.size(); j++){
        if(j == 0){
            answer.push_back(arr[j]);
            continue;
        };
        
        if(answer[index]==arr[j]){
            continue;
        }
        else{
            answer.push_back(arr[j]);
            index++;
        };
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i];
    }
    

    return answer;
}