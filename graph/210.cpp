#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct node
{
    int position;
    vector<bool>used;
    vector<bool>forward_used;
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        int n=prerequisites.size();
        vector<int>res;
        bool general_used[numCourses];
        vector<bool>used;
        vector<bool>forward_used;
        for (int i = 0; i < numCourses; i++)
        {
            used.push_back(false);
            general_used[i]=false;
        }
        for (int t = 0; t <numCourses; t++)
        {
            node start;
            start.position=t;
            start.used=used;
            start.forward_used=used;
            stack<node>tree;
            tree.push(start);
            while (tree.empty()!=true)
            {
                int ancestor=tree.top().position;
                cout<<"ancestor: "<<ancestor<<endl;
                used=tree.top().used;
                forward_used=tree.top().forward_used;
                used[ancestor]=true;
                bool found=false;
                for (int i = 0; i<n; i++)
                {
                    if (prerequisites[i][0]==ancestor && used[prerequisites[i][1]]==false && general_used[prerequisites[i][1]]==false)
                    {
                        found=true;
                        node next;
                        next.position=prerequisites[i][1];
                        cout<<"next position: "<<next.position<<endl;
                        next.used=used;
                        next.forward_used=forward_used;
                        tree.push(next);
                        for (int j=0; j<n; j++)
                        {
                            if (prerequisites[j][0]==next.position && (used[prerequisites[j][1]]==true && forward_used[prerequisites[j][1]]!=true))
                            {
                                res.clear();
                                return res;
                            }
                        }
                    }
                }
                
                if (found==false)
                {
                    cout<<"Last ancestor: "<<ancestor<<endl;
                    if (general_used[ancestor]==false)
                    {
                        res.push_back(ancestor);
                    }
                    general_used[ancestor]=true;
                    tree.pop();
                    if (tree.empty()!=true)
                    {
                        tree.top().forward_used[ancestor]=true;
                        tree.top().used[ancestor]=true;
                    }
                }
            }
            bool f=true;
            for (int i = 0; i <numCourses; i++)
            {
                if (general_used[i]==false)
                {
                    f=false;
                }
            }
            if (f==true)
            {
                break;
            }
            
        }
        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i]<<" ";
        }
        return res;
    }
};
int main(){
    freopen("210.txt","r",stdin);
    int n,t;
    cin>>n>>t;
    vector<vector<int> >v;
    for (int i = 0; i < t; i++)
    {
        vector<int>c;
        for (int  j= 0; j<2; j++)
        {
            int cc;
            cin>>cc;
            c.push_back(cc);
        }
        v.push_back(c);
    }
    Solution s;
    s.findOrder(n,v);
    return 0;
}