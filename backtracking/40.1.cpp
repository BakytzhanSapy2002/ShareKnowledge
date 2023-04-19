#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
struct element
{
    int position;
    vector<bool>used;
    int sum_of;
};
struct difficult_point
{
   int position;
   int sum_up;
   vector<int>amount;
};
bool order(int a, int b){
    return a<=b;
}
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target){
        vector<vector<int> >res;
        vector<vector<int> >combinations;
        int s=0;
        while (s!=candidates.size())
        {
            if (candidates[s]>=target)
            {
                if (candidates[s]==target)
                {
                    vector<int>newo;
                    newo.push_back(candidates[s]);
                    combinations.push_back(newo);
                }
                candidates.erase(candidates.begin()+s);
            }
            else
            {
                s=s+1;
            }
        } 
        int n=candidates.size();
        int sum=0;
        vector<bool>used;
        for (int i = 0; i <n; i++)
        {
            used.push_back(false);
            sum=sum+candidates[i];
        }
        if (sum<target && combinations.size()==0)
        {
           return res;
        }
        queue<element>q;
        element e;
        e.used=used;
        set<vector<bool> >unique_combinations;
        for (int i = 0; i < n; i++)
        {
            e.position=i;
            e.sum_of=candidates[i];
            e.used[i]=true;
           // cout<<e.position<<endl;
            q.push(e);
            e.used[i]=false;
        }
        while (q.empty()!=true)
        {
            e=q.front();
            cout<<"Sum: "<<endl;
            cout<<e.sum_of<<endl;
            int current=e.position;
            cout<<current<<endl;
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (e.used[i]==false)
                {
                    e.position=i;
                    e.sum_of=e.sum_of+candidates[i];
                    e.used[i]=true;
                    if (e.sum_of>target)
                    {
                        e.used[i]=false;
                        e.sum_of=e.sum_of-candidates[i];
                        continue;
                    }
                    if (e.sum_of==target)
                    {
                        unique_combinations.insert(e.used);
                        cout<<"found"<<endl;
                        for (int j = 0; j < n; j++)
                        {
                            if (e.used[j]==true)
                            {
                                cout<<candidates[j]<<" ";
                            }
                        }
                        cout<<endl;
                        e.used[i]=false;
                        e.sum_of=e.sum_of-candidates[i];                        
                        continue;
                    }
                    q.push(e);
                    e.used[i]=false;
                    e.sum_of=e.sum_of-candidates[i];
                }
            }
        }
        cout<<"*******"<<endl;
        set<vector<bool> >::iterator it;
        if (unique_combinations.size()==0 && combinations.size()==0)
        {
            return res;
        }
        for (it=unique_combinations.begin(); it!=unique_combinations.end(); it++)
        {
            vector<bool>v=*it;
            vector<int>vv;
            for (int i = 0; i < v.size(); i++)
            {
              
                if (v[i])
                {
                   vv.push_back(candidates[i]);
                }
            }
            combinations.push_back(vv);
        }
        unique_combinations.erase(unique_combinations.begin(),unique_combinations.end());
        // for (int i = 0; i < combinations.size(); i++)
        // {
        //     for (int j = 0; j < combinations[i].size(); j++)
        //     {
        //         cout<<combinations[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        set<vector<int> >uniques;
        for (int i = 0; i <combinations.size(); i++)
        {
            sort(combinations[i].begin(),combinations[i].end(),order);
           uniques.insert(combinations[i]);
        }
        set<vector<int> >::iterator it1;
        for (it1 = uniques.begin(); it1!=uniques.end(); it1++)
        {
            res.push_back(*it1);
        }
        return res;
        }
};
int main(){
    freopen("40.txt","r",stdin);
    int n;
    cin>>n;
    vector<int>candidates;
    for (int i = 0; i < n; i++)
    {
       int x;
       cin>>x;
       candidates.push_back(x);
    }
    int target;
    cin>>target;
    Solution s;
    vector<vector<int> >result=s.combinationSum(candidates,target);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" - ";
        }
        cout<<endl;
    }    
    return 0;
}