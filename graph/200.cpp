#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char> >& grid){
        int m=grid.size(),n=grid[0].size();
        bool b[m][n];
        for (int i = 0; i <m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[i][j]=false;
            }   
        }
        int res=0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j]=='1' && b[i][j]==false)
                {
                    res++;
                    queue<pair<int,int> >q;
                    pair<int,int>p;
                    p.first=i,p.second=j;
                    q.push(p);
                    while (q.empty()!=true)
                    {
                        int x=q.front().first,y=q.front().second;
                        b[x][y]=true;
                        q.pop();
                        bool dir1=(x-1>=0);
                        bool dir2=(y-1>=0);
                        bool dir3=(x+1<=m-1);
                        bool dir4=(y+1<=n-1);
                        if (dir1)
                        {
                            if (grid[x-1][y]=='1' && b[x-1][y]==false)
                            {
                                b[x-1][y]=true;
                                pair<int,int>p;
                                p.first=x-1;
                                p.second=y;
                                q.push(p);
                            }
                        }
                        if (dir3)
                        {
                            if (grid[x+1][y]=='1' && b[x+1][y]==false)
                            {
                                b[x+1][y]=true;
                                pair<int,int>p;
                                p.first=x+1;
                                p.second=y;
                                q.push(p);
                            }
                        }
                        if (dir2)
                        {
                            if (grid[x][y-1]=='1' && b[x][y-1]==false)
                            {
                                b[x][y-1]=true;
                                pair<int,int>p;
                                p.first=x;
                                p.second=y-1;
                                q.push(p);
                            }
                        }
                        if (dir4)
                        {
                            if (grid[x][y+1]=='1' && b[x][y+1]==false)
                            {
                                b[x][y+1]=true;
                                pair<int,int>p;
                                p.first=x;
                                p.second=y+1;
                                q.push(p);
                            }
                        }
                    }
                    
                }
                
            }
            
        }
        return res;
    }
};
int main(){
    freopen("200.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    vector<vector<char> >v;
    for (int i = 0; i < m; i++)
    {
        vector<char>c;
        for (int  j= 0; j< n; j++)
        {
            char cc;
            cin>>cc;
            c.push_back(cc);
        }
        v.push_back(c);
    }
    Solution s;
    cout<<s.numIslands(v)<<endl;
    return 0;
}