#include <iostream>
#include <vector>
using namespace std;


void QSort(vector<int>& vec, int left, int right)
{
    int pl = left;
    int pr = right;
    
    int center = vec[(pl + pr) / 2];
    
    while(pl<=pr)
    {
        while(vec[pl] < center)
            pl++;
        
        while(vec[pr] > center)
            pr--;
            
        if(pl<=pr)
        {
            int dest = vec[pl];
            vec[pl] = vec[pr];
            vec[pr] = dest;
            pl++;
            pr--;
        }
        
        if(left < pr) QSort(vec, left, pr);
        if(pl < right) QSort(vec, pl, right);
    }
    
    //cout<<vec.size()<<endl;
        
}

int main()
{
   vector<int> d{5,3,2,6,7,9,1,8,2};
   
   QSort(d, 0, d.size()-1);
   
    for(int i =0; i < d.size(); i++)
    {
        cout<<d[i]<<" ";
    }

   
   return 0;
}