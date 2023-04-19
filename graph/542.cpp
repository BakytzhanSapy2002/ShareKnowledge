#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct square
{
    vector<bool>used_row;
    vector<bool>used_column;
    int x;
    int y;
    int distance;
};

class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int> >res;
        vector<bool>used_row;   
        vector<bool>used_column;
        for (int i = 0; i < m; i++)
        {
            used_row.push_back(false);
        }  
        for (int i = 0; i < n; i++)
        {
            used_column.push_back(false);
        }
        bool found=false;
        for (int i = 0; i <m; i++)
        {
            vector<int>v;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j]==0)
                {
                    found=true;
                    v.push_back(0);
                }
                else
                {
                    square ss;
                    ss.x=i;
                    ss.y=j;
                    // cout<<ss.x<<" "<<ss.y<<endl;
                    ss.distance=0;
                    ss.used_row=used_row;
                    ss.used_column=used_column;
                    queue<square>q;
                    q.push(ss);
                    while (q.empty()!=true)
                    {
                        ss=q.front();
                        q.pop();
                        ss.used_row[ss.x]=true;
                        ss.used_column[ss.y]=true;
                        ss.distance++;
                        bool dir1=(ss.x-1>=0);
                        bool dir2=(ss.x+1<=m-1);
                        bool dir3=(ss.y-1>=0);
                        bool dir4=(ss.y+1<=n-1);
                        if (dir1)
                        {
                            if (ss.used_row[ss.x-1]==false || ss.used_column[ss.y]==false)
                            {
                               if (mat[ss.x-1][ss.y]==0)
                               {
                                    v.push_back(ss.distance);
                                    break;
                               }
                               else{
                                square s=ss;
                                s.x--;
                                q.push(s);
                               }
                            } 
                        }
                        if (dir2)
                        {
                            if (ss.used_row[ss.x+1]==false || ss.used_column[ss.y]==false)
                            {
                               if (mat[ss.x+1][ss.y]==0)
                               {
                                    v.push_back(ss.distance);
                                    break;
                               }
                               else
                               {
                                    square s=ss;
                                    s.x++;
                                    q.push(s);
                               } 
                            }
                        }
                        if (dir3)
                        {
                            if (ss.used_row[ss.x]==false || ss.used_column[ss.y-1]==false)
                            {
                                if (mat[ss.x][ss.y-1]==0)
                               {
                                    v.push_back(ss.distance);
                                    break;
                               }
                               else
                               {
                                    square s=ss;
                                    s.y--;
                                    q.push(s);
                               } 
                            }
                        }
                        if (dir4)
                        {
                            if (ss.used_row[ss.x]==false || ss.used_column[ss.y+1]==false)
                            {
                                if (mat[ss.x][ss.y+1]==0)
                               {
                                    v.push_back(ss.distance);
                                    break;
                               }
                               else
                               {
                                    square s=ss;
                                    s.y++;
                                    q.push(s);
                               } 
                            }
                        }
                    } 
                }
            }
            res.push_back(v);
        }
        for (int i = 0; i <m; i++)
        {
            for (int j = 0; j <n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        return res;
    }
};
int main(){
    freopen("542.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    vector<vector<int> >b;
    for (int i = 0; i < m; i++)
    {
        vector<int>s;
        for (int j = 0; j <n; j++)
        {
            int x;
            cin>>x;
            s.push_back(x);
        }
        b.push_back(s);
    }
    Solution ss;
    ss.updateMatrix(b);
    return 0;
}
