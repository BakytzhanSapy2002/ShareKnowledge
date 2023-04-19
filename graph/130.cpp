#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char> >& board){
        string s1="\"X\"",s2="\"O\"";
        vector<pair<int,int> >v;
        int m=board.size(),n=board[0].size();
        bool b[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j<n ; j++)
            {
                b[i][j]=false;
                  if (board[i][j]=='O' && (i==0 || i==m-1 || j==0 || j==n-1))
                  {
                        pair<int,int>p;
                        p.first=i;
                        p.second=j;
                        v.push_back(p);
                  }
            }
        }
        for (int i=0; i<v.size(); i++)
        {
            int x=v[i].first,y=v[i].second;
            b[x][y]=true;
            queue<pair<int,int> >q;
            q.push(v[i]);
            while (q.empty()!=true)
            {
                int xx=q.front().first,yy=q.front().second;
                q.pop();
                bool dir1=(yy+1<n),dir2=(xx+1<m),dir3=(yy-1>=0),dir4=(xx-1>=0);
                if (dir1 && board[xx][yy+1]=='O' && b[xx][yy+1]==false)
                {
                    b[xx][yy+1]=true;
                    pair<int,int>p;
                    p.first=xx;
                    p.second=yy+1;
                    q.push(p);
                }
                if (dir2 && board[xx+1][yy]=='O' && b[xx+1][yy]==false)
                {
                    b[xx+1][yy]=true;
                    pair<int,int>p;
                    p.first=xx+1;
                    p.second=yy;
                    q.push(p);
                }
                if (dir3 && board[xx][yy-1]=='O' && b[xx][yy-1]==false)
                {
                    b[xx][yy-1]=true;
                    pair<int,int>p;
                    p.first=xx;
                    p.second=yy-1;
                    q.push(p);
                }
                if (dir4 && board[xx-1][yy]=='O' && b[xx-1][yy]==false)
                {
                    b[xx-1][yy]=true;
                    pair<int,int>p;
                    p.first=xx-1;
                    p.second=yy;
                    q.push(p);
                }
            }  
        } 
        cout<<"[";
         for (int i = 0; i <m; i++)
         {
            cout<<"[";
           for (int j = 0; j<n; j++)
           {
            if (b[i][j])
            {
                board[i][j]='O';
                if (j==n-1)
                {
                   cout<<s2; 
                   continue;
                }
                cout<<s2<<",";
            }
            else
            {
                board[i][j]='X';
                if (j==n-1)
                {
                   cout<<s1; 
                   continue;
                }
                cout<<s1<<",";
            }
           }
           if (i==m-1)
           {
            cout<<"]";
            continue;
           }
           cout<<"],";
         }
         cout<<"]";
    }
};
int main(){
    freopen("130.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    vector<vector<char> >v;
    for (int i = 0; i < m; i++)
    {
        vector<char>c;
        for (int j = 0; j <n; j++)
        {
            char ch;
            cin>>ch;
            c.push_back(ch);
        }
        v.push_back(c);
    }
    Solution s;
    s.solve(v);
    return 0;
}