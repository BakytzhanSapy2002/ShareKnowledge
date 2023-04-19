#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct city
{
    int city_number;
    vector<bool>visited;
};
vector<vector<int> >connected; 
class Solution {
public:
    int findCircleNum(vector<vector<int> >& isConnected) {
        int n=isConnected.size();
        vector<bool>used;
        for (int i = 0; i <n; i++)
        {
           used.push_back(false);
        }
        int number_of_provinces=0;
        for (int i = 0; i <n; i++)
        {
           if (used[i]==true)
           {
            continue;
           }
           number_of_provinces++;
           cout<<"number of provinces: "<<number_of_provinces<<endl;
           city c;
           c.city_number=i;
           cout<<"********: "<<i<<endl;
           c.visited=used;
           queue<city>q;
           q.push(c);
           while (q.empty()!=true)
           {
                c=q.front();
                int prev=c.city_number;
                cout<<"***: "<<prev<<endl;
                q.pop();
                c.visited[c.city_number]=true;
                used[c.city_number]=true;
                for (int j = 0; j < n; j++)
                {
                    if (c.visited[j]==false && used[j]==false && isConnected[c.city_number][j]==1)
                    {
                        c.city_number=j;
                        q.push(c);
                        c.city_number=prev;
                    }
                }
           }
        }
        return number_of_provinces;
    }
};
int main(){
    freopen("547.txt","r",stdin);
    int n;
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        vector<int>v;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        connected.push_back(v);
    }
    Solution s;
    cout<<s.findCircleNum(connected)<<endl;
    return 0;
}