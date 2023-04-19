#include <iostream>
#include <vector>
#include <set>
#include <queue>
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
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target){
        vector<vector<int> >total_result;
        int n=candidates.size();
        vector<bool>used;
        for (int i = 0; i <n; i++)
        {
            used.push_back(false);
        }
        queue<element>q;
        element e;
        e.used=used;
        set<vector<bool> >unique_combinations;
        e.sum_of=0;
        for (int i = 0; i < n; i++)
        {
            e.position=i;
           // cout<<e.position<<endl;
            q.push(e);
        }
        while (q.empty()!=true)
        {
            e=q.front();
            int current=e.position;
           // cout<<current<<endl;
            q.pop();
            e.used[e.position]=true;
            e.sum_of=e.sum_of+candidates[current];
            if (e.sum_of>target)
            {
                continue;
            }
            unique_combinations.insert(e.used);
            for (int i = 0; i < n; i++)
            {
                if (e.used[i]==false)
                {
                    e.position=i;
                    q.push(e);
                    e.position=current;
                }
            }
        }
        set<vector<bool> >::iterator it;
        vector<vector<int> >combinations;
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
        for (int i = 0; i < combinations.size(); i++)
        {
            for (int j = 0; j < combinations[i].size(); j++)
            {
                cout<<combinations[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"..."<<endl;
        for (int w = 0; w< combinations.size(); w++)
        {
            difficult_point dfp;
            queue<difficult_point>q;
            dfp.sum_up=0;
           // cout<<"/////////////////"<<endl;
            for (int j = 0; j<combinations[w].size(); j++)
            {
                //cout<<combinations[w][j]<<" ";
                dfp.sum_up+=combinations[w][j];
                dfp.amount.push_back(0);
            }
            //cout<<endl;
            
            if (dfp.sum_up==target)
            {
               // cout<<"*****************************"<<endl;
                // for (int i = 0; i < combinations[w].size(); i++)
                // {
                //     cout<<combinations[w][i]<<" ";
                // }
                //cout<<endl;
                total_result.push_back(combinations[w]);
                continue;
            }
            if (dfp.sum_up>target)
            {
                continue;
            }
            //cout<<dfp.sum_up<<endl;
            int size_of=combinations[w].size();
            dfp.position=-1;
            q.push(dfp);
            while (q.empty()!=true)
            {
                dfp=q.front();
                dfp.position++;
              //  cout<<"dfp pos: "<<dfp.position<<endl;
              //  cout<<"dfp sum: "<<dfp.sum_up<<endl;
                q.pop();
                int current=dfp.position;
                vector<int>changeable=combinations[w];
                if (dfp.sum_up==target)
                {
                    for (int i = 0; i <dfp.amount.size(); i++)
                    {
                        for (int j = 0; j<dfp.amount[i]; j++)
                        {
                            changeable.push_back(combinations[w][i]);
                        }
                    }
                 //   cout<<"*****************************"<<endl;
                    // for (int i = 0; i < changeable.size(); i++)
                    // {
                    //    cout<<changeable[i]<<" ";
                    // }
                 //   cout<<endl;
                    total_result.push_back(changeable);
                    continue;
                }
                int k=(target-dfp.sum_up)/combinations[w][current]; // Күрделірек k= типа бөлінсе
                int mod=(target-dfp.sum_up)%combinations[w][current]; // қалдық нөлге тең.
              //  cout<<"k: "<<k<<" mod: "<<mod<<endl;
              //  cout<<current<<" "<<"size of: "<<size_of<<endl;
                if (current==size_of-1)
                {
                    if (mod==0)
                    {
                      //  cout<<"current: "<<current<<endl;
                        dfp.amount[current]=dfp.amount[current]+k;
                      //  cout<<"its amount would be changed: "<<dfp.amount[current]<<endl;
                      //  cout<<"new_res: "<<combinations[w].size()<<endl;
                        vector<int>changeable2=combinations[w];
                        for (int r=0; r<combinations[w].size(); r++)
                        {
                            //cout<<"***"<<dfp.amount[r]<<endl;
                            for (int y = 0; y<dfp.amount[r]; y++)
                            {
                                changeable2.push_back(combinations[w][r]);
                            }
                        }
                     //   cout<<"*****************************"<<endl;
                        // for (int i = 0; i < changeable2.size(); i++)
                        // {
                        // cout<<changeable2[i]<<" ";
                        // }
                        // cout<<endl;
                        total_result.push_back(changeable2);
                    }
                    continue;
                }
                        for (int t=0; t<=k; t++)
                        { 
                            dfp.amount[current]=dfp.amount[current]+t;
                            dfp.sum_up=dfp.sum_up+t*combinations[w][current];
                           // cout<<"sum: "<<dfp.sum_up<<" when t: "<<t<<endl;
                            if (dfp.sum_up<=target)
                            {
                                q.push(dfp);
                            }
                            if (dfp.sum_up>target)
                            {
                                break;
                            }
                            dfp.amount[current]=dfp.amount[current]-t;
                            dfp.sum_up=dfp.sum_up-t*combinations[w][current];
                        }
                }
            } 
           // cout<<"finished"<<endl;
           return total_result;
        }
};
int main(){
    freopen("39.txt","r",stdin);
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
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}