#include <iostream>
#include <vector>
using namespace std;


void QuickSort(vector<auto>& vec, int left, int right)
{
    int pl = left;
    int pr = right;
    
    auto center = vec[(pl+pr)/2];
    
    while(pl<=pr)
    {
        while(vec[pl]<center)
            pl++;
        while(vec[pr]>center)
            pr--;
            
        if(pl<=pr)
        {
            auto dest = vec[pl];
            vec[pl] = vec[pr];
            vec[pr] = dest;
            
            pl++;
            pr--;
        }
    }
    
    if(left<pr)QuickSort(vec, left, pr);
    if(right>pl)QuickSort(vec, pl, right);
}

int main()
{
    vector<char> d{'a','c','w','y','q'};

    QuickSort(d, 0, d.size()-1);
    
    for(int i =0; i < d.size(); i++)
    {
        cout<<d[i]<<" ";
    }

    return 0;
}