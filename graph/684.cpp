#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct city
{
    int city_number;
    vector<int>visited;
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges){
        vector<bool>used;
        int n=edges.size();
        for (int i = 0; i < n+1; i++)
        {
            used.push_back(false);
        }
        cout<<"n: "<<n<<endl;
        int start=1;
        city c;
        c.city_number=start;
        used[c.city_number]=true;
        queue<city>q;
        q.push(c);
        vector<pair<int,int>redundants;
        while (q.empty()!=true)
        {
            c=q.front();
            q.pop();
            int prev=c.city_number;
            cout<<"current city: "<<prev<<endl;
            c.visited.push_back(c.city_number);
            for (int i = 0; i<n; i++)
            {
                if (edges[i][0]==c.city_number)
                {
                    bool go_on=false;
                    for (int j = 0; j<c.visited.size(); j++)
                    {
                        if (edges[i][1]==c.visited[j])
                        {
                            cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
                            go_on=true;
                            break;
                        }
                    }
                    if (used[edges[i][1]]==true)
                    {
                        pair<int,int>p;
                        p.first=edges[i][0];
                        p.second=edges[i][1];
                        redundants.push_back(p);
                    }
                    c.city_number=edges[i][1];
                    used[c.city_number]=true;
                    q.push(c);
                    c.city_number=prev;
                }
            }
        } 
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
    s.findRedundantConnection(edges);
    return 0;
}