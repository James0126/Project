#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    int cnt = 0;
    vector<int> answer;
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i]%divisor == 0)
        {
            answer.push_back(arr[i]);
            cnt++;
        }
    }
    if(cnt == 0)
    {
        answer.push_back(-1);
    }
    
    for(int i = 0; i < answer.size(); i++)
    {
        for(int j = i+1; j < answer.size(); j++)
        {
            if(answer[i]>answer[j])
            {
                int dest = answer[i];
                answer[i] = answer[j];
                answer[j] = dest;
            }
        }
    }
    return answer;
}