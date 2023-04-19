#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> >total_result;
    vector<vector<bool> >all_cases;
    void recursive_comb(vector<int>comb,vector<bool>bb, int current_sum,int current_position,vector<int>candidates,int target){
        // Stopping criteria: 1) current_sum is more than target or current_position is equal to n
        bool exist=false; // Still current_pos is not changed to the bool vector
        cout<<current_position<<" ";
        if (current_position<candidates.size())
        {
            recursive_comb(comb,bb,current_sum,current_position+1,candidates,target);
        }
        cout<<"ggg0"<<endl;
        while (true)
        {
            if (current_sum+candidates[current_position]>target)
            {
                current_position++;
            }
            else
            {
                exist=true;
                if (current_sum+candidates[current_position]==target)
                {
                    bb[current_position]=true;
                    comb.push_back(candidates[current_position]);
                    vector<vector<bool> >::iterator it=find(all_cases.begin(),all_cases.end(),bb);
                    if (it==all_cases.end())
                    {
                        all_cases.push_back(bb);
                        total_result.push_back(comb);
                    }
                }
                else
                {
                    bb[current_position]=true;
                    comb.push_back(candidates[current_position]);
                    current_position=current_position+1;
                    current_sum=current_sum+candidates[current_position];
                    recursive_comb(comb,bb,current_sum,current_position,candidates,target);
                }
                
            } 
        }
        if (exist==false)
        {
            return;
        }
    }
    vector<vector<int> > combinationSum2(vector<int>candidates, int target){
        // For result         
        // Step-1: Delete elements which are greater than target (easy)
        while (true)
        {
            bool f=false;
            for (int i = 0; i <candidates.size(); i++)
            {
                if (candidates[i]>=target)
                {
                    if (candidates[i]==target)
                    {
                        vector<int>small;
                        small.push_back(candidates[i]);
                        total_result.push_back(small);
                    }
                    f=true;
                    candidates.erase(candidates.begin()+i);
                    break;
                }
            }
            if (f==false)
            {
                break;
            } 
        }
        // Step-2: Create bool function for recursion (easy)
        vector<bool>bb;
        int n=candidates.size();
        for (int i = 0; i <n ; i++)
        {
            bb.push_back(false);
        }
        vector<int>new_comb;
        recursive_comb(new_comb,bb,0,0,candidates,target);
        return total_result;
    }
};
int main(){
    freopen("40.txt","r",stdin);
    vector<int>v;
    int n,t;
    cin>>n>>t;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    Solution s;
    vector<vector<int> >res=s.combinationSum2(v,t);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j <res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

