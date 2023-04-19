#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct inorder
{
    int current_equation;
    vector<bool>used;
    string s;
    double d;
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
        vector<double>res;
        for (int t = 0; t < queries.size(); t++)
        {
            vector<bool>used;
            string parameter1=queries[t][0];
            string parameter2=queries[t][1];
            //cout<<parameter1<<" "<<parameter2<<endl;
            double d=1;
            stack<inorder>q;
            inorder in;
            bool found=false;
            bool exist=false;
            for (int j = 0; j<equations.size(); j++)
            {
                used.push_back(false);
            }
            bool exist2=false;
            for (int j = 0; j <equations.size(); j++)
            {
                if (equations[j][0]==parameter1)
                {
                    if (equations[j][1]==parameter2)
                    {
                        found=true;
                        d=d*values[j];
                        res.push_back(d);
                        cout<<"Add: "<<d<<endl;
                        break;
                    }
                    else
                    {
                        if (parameter1==parameter2)
                        {
                            cout<<"Add: "<<1<<endl;
                            res.push_back(1);
                            found=true;
                            break;
                        }
                        exist=true;
                        in.used=used;
                        in.current_equation=j;
                        in.s=equations[j][1];
                        cout<<"Next added: "<<in.s<<endl; 
                        in.d=d*values[j];
                        q.push(in);
                    }
                }
                if (equations[j][1]==parameter1)
                {
                    if (equations[j][0]==parameter2)
                    {
                        found=true;
                        d=d/values[j];
                        cout<<"Add: "<<d<<endl;
                        res.push_back(d);
                        break;
                    }
                    else
                    {
                        if (parameter1==parameter2)
                        {
                            res.push_back(1);
                            cout<<"Add: "<<1<<endl;
                            found=true;
                            break;
                        }
                        exist=true;
                        in.used=used;
                        in.current_equation=j;
                        in.s=equations[j][0];
                        cout<<"Next added: "<<in.s<<endl; 
                        in.d=d/values[j];
                        q.push(in);
                    }
                }
                if (equations[j][1]==parameter2 || equations[j][0]==parameter2)
                {
                    exist2=true;
                }
            }
            if (found==true)
            {
                continue;
            }
            if (exist==false || exist2==false)
            {
                res.push_back(-1);
                cout<<"Add: "<<-1<<endl;
                continue;
            }
            found=false;
            cout<<"Start of will: ***********"<<endl;
            while (q.empty()!=true)
            {
                in=q.top();
                in.used[in.current_equation]=true;
                cout<<in.current_equation<<endl;
                cout<<in.s<<endl;
                exist=false;
                for (int i = 0; i<equations.size(); i++)
                {
                    cout<<"*"<<endl;
                    if(in.used[i]==false){
                        cout<<"***"<<endl;
                    if (equations[i][0]==in.s)
                    {
                        if (equations[i][1]==parameter2)
                        {
                            found=true;
                            in.d=in.d*values[i];
                            res.push_back(in.d);
                            cout<<"Add: "<<in.d<<endl;
                            break;
                        }
                        else
                        {
                            exist=true;
                            in.current_equation=i;
                            in.s=equations[i][1];
                            cout<<"Next variable: "<<in.s<<endl;
                            in.d=in.d*values[i];
                            q.push(in);
                        }
                    }
                    if (equations[i][1]==in.s)
                    {
                        if (equations[i][0]==parameter2)
                        {
                        
                            found=true;
                            in.d=in.d/values[i];
                            res.push_back(in.d);
                            cout<<"Add: "<<in.d<<endl;
                            break;
                        }
                        else
                        {
                            exist=true;
                            in.current_equation=i;
                            in.s=equations[i][0];
                            in.d=in.d/values[i];
                            q.push(in);
                        }
                    }
                    }
                    if (found==true)
                    {
                        break;
                    }
                }
                if (found==true)
                {
                    break;
                }
                    if (exist==false)
                    {
                        q.pop();
                        if (q.empty()!=true)
                        {
                           q.top().used[in.current_equation]=true;
                        }
                    }
                cout<<"**"<<endl;
            }
            if (found==false)
            {
                cout<<"Add: "<<-1<<endl;
                res.push_back(-1);
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
    freopen("399.txt","r",stdin);
    int n;//Number of equations
    cin>>n;
    vector<vector<string> >equations;
    for (int i = 0; i < n; i++)
    {
        vector<string>v;
        string s1,s2;
        cin>>s1>>s2;
        v.push_back(s1);
        v.push_back(s2);
        equations.push_back(v);
    }
    vector<double>values;
    for (int i = 0; i < n; i++)
    {
        double d;
        cin>>d;
        values.push_back(d);
    }
    int k;
    cin>>k;
    vector<vector<string> >queries;
    for (int i = 0; i < k; i++)
    {
        vector<string>v;
        string s1,s2;
        cin>>s1>>s2;
        v.push_back(s1);
        v.push_back(s2);
        queries.push_back(v);
    }
    Solution s;
    s.calcEquation(equations,values,queries);
    return 0;
}