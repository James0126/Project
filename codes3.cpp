#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;
    for(int i=0; i < numbers.size(); i++)
    {
        for(int j = i+1; j<numbers.size(); j++)
        {
            if(i == 0 && j == 1)
            {
                answer.push_back(numbers[i]+numbers[j]);
            }
            for(int k = 0; k < answer.size(); k++)
            {
                if(numbers[i]+numbers[j] == answer[k])
                    break;
                
                if(k == answer.size()-1)
                   answer.push_back(numbers[i]+numbers[j]); 
            }
            
        }
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