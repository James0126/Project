#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    
   for(int i = 0; i < commands.size(); i++)
    {
        vector<int> temp;
        for(int j = commands[i][0] - 1; j<commands[i][1];j++ )
        {
            temp.push_back(array[j]);
        }
        
        for(int k = 0; k < temp.size(); k++)
        {
            for(int l = k+1; l < temp.size(); l++)
            {
                if(temp[k] > temp[l])
                {
                    int dest = temp[k];
                    temp[k] = temp[l];
                    temp[l] = dest;
                }
                
            }
        }//end of for(k)
        
        answer.push_back(temp[commands[i][2]-1]);
    }
    

    return answer;
}