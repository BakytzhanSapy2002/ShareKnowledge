#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct path
{
    int current_vertex;
    int previous_vertex;
    vector<bool>used;
    vector<int>used_numbers;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges){
        int n=3;
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i][0]>=edges[i][1] && edges[i][0]>n)
            {
                n=edges[i][0];
                edges[i][0]--;
                edges[i][1]--;
            }
            else
            {
                if (edges[i][1]>edges[i][0] && edges[i][1]>n)
                {
                    n=edges[i][1];
                }
                edges[i][0]--;
                edges[i][1]--;
            }
        }
        vector<vector<int> >edges1=edges;
        // for (int i = 0; i < edges.size(); i++)
        // {
        //     cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
        // }
        vector<bool>used;
        for (int i = 0; i < n; i++)
        {
            used.push_back(false);
        }
        path p;
        vector<bool>res;
        vector<int>res_number;
        p.current_vertex=edges[0][1];
        p.previous_vertex=edges[0][0];
        //edges.erase(edges.begin()+0);
        p.used=used;
        p.used_numbers.push_back(edges[0][0]);
        stack<path>s;
        s.push(p);
        while (s.empty()==false)
        {
            path current_path=s.top();
            cout<<"Current vertex: "<<current_path.current_vertex<<endl;
            s.pop();
            // for (int i = 0; i < edges.size(); i++)
            // {
            //     cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
            // }
            int i=0;
            bool f=false;
            while(i<edges.size()){
                if (current_path.used[edges[i][1]]==true && edges[i][0]==current_path.current_vertex && edges[i][1]!=current_path.previous_vertex)  
                {
                    f=true;
                    cout<<"Found "<<endl;
                    cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
                    current_path.used[edges[i][0]]=true;
                    current_path.used[edges[i][1]]=true;
                    current_path.used_numbers.push_back(edges[i][0]);
                    current_path.used_numbers.push_back(edges[i][1]);
                    current_path.used[current_path.previous_vertex]=true;
                    res=current_path.used;
                    res_number=current_path.used_numbers;
                    break;
                }
                if (current_path.used[edges[i][0]]==true && edges[i][1]==current_path.current_vertex && edges[i][0]!=current_path.previous_vertex)  
                {
                    f=true;
                    cout<<"Found "<<endl;
                    cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
                    current_path.used[edges[i][0]]=true;
                    current_path.used[edges[i][1]]=true;
                    current_path.used_numbers.push_back(edges[i][1]);
                    current_path.used_numbers.push_back(edges[i][0]);
                    current_path.used[current_path.previous_vertex]=true;
                    res=current_path.used;
                    res_number=current_path.used_numbers;
                    break;
                }
                else
                {
                    if (edges[i][0]==current_path.current_vertex && current_path.used[edges[i][1]]==false)
                    {
                        path new_path=current_path;
                        new_path.current_vertex=edges[i][1];
                        new_path.previous_vertex=edges[i][0];
                        cout<<"Next vertex: "<<new_path.current_vertex<<endl;
                        new_path.used[edges[i][0]]=true;
                        new_path.used_numbers.push_back(edges[i][0]);
                        s.push(new_path);
                        i++;
                        //edges.erase(edges.begin()+i);
                    }
                    else
                    { 
                        if (edges[i][1]==current_path.current_vertex && current_path.used[edges[i][0]]==false)
                    {
                        path new_path=current_path;
                        new_path.current_vertex=edges[i][0];
                        new_path.previous_vertex=edges[i][1];
                        cout<<"Next vertex: "<<new_path.current_vertex<<endl;
                        new_path.used[edges[i][1]]=true;
                        new_path.used_numbers.push_back(edges[i][1]);
                        s.push(new_path);
                        //edges.erase(edges.begin()+i);   
                        i++;
                    }
                    else
                    {
                        i++;
                    }
                    
                }
            }
        }
        if (f==true)
        {
            break;
        }
        
    }
    vector<int>pair;
    int index_start;
    for (int j = 0; j<res_number.size(); j++)
    {
        if (res_number[j]==res_number[res_number.size()-1])
        {
            index_start=j;
            break;
        }
    }
    cout<<res_number[index_start]<<endl;
    for (int i = edges1.size()-1; i>=0; i--)
    {
        bool f=false;
        for (int j = index_start; j<res_number.size()-1; j++)
        {
            if ((edges1[i][0]==res_number[j] && edges1[i][1]==res_number[j+1]) || (edges1[i][1]==res_number[j] && edges1[i][0]==res_number[j+1]))
            {
                pair.push_back(edges1[i][0]+1);
                pair.push_back(edges1[i][1]+1);
                f=true;
                break;
            }
        }
        if (f==true)
        {
           break;
        }
    }
    for (int i = 0; i < res_number.size(); i++)
    {
        cout<<res_number[i]<<" ";
    }
    cout<<endl;
    return pair;
    }
};
int main(){
    freopen("684.txt","r",stdin);
    int n;
    cin>>n;
    vector<vector<int> >edges;
    for (int i = 0; i < n; i++)
    {
        vector<int>edge;
        int a,b;
        cin>>a>>b;
        edge.push_back(a);
        edge.push_back(b);
        edges.push_back(edge);
    }
    Solution s;
    vector<int>res=s.findRedundantConnection(edges);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}