#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
struct intersection
{
    int x;
    int y;
    vector<bool>b1;
    vector<bool>b2;
    vector<bool>b3;
};
struct unnormal_operation
{
    int position;
    vector<intersection>vv;
    vector<bool>used;
    vector<int>important;
    vector<bool>forward_used;
};
bool order(intersection inter1,intersection inter2){
    int cnt1=0,cnt2=0;
    for (int i = 0; i <9; i++)
    {
        if (inter1.b1[i] || inter1.b2[i] || inter1.b3[i])
        {
            cnt1++;
        }
        if (inter2.b1[i] || inter2.b2[i] || inter2.b3[i])
        {
            cnt2++;
        }
    }
    return cnt1>=cnt2;    
}
class Solution {
public:
    void solveSudoku(vector<vector<char> >& board){
        vector<bool>b1;
        for (int i = 0; i < 9; i++)
        {
           b1.push_back(false);
        }
        vector<intersection>total;
        for (int i = 0; i <9; i++)
        {
            for (int j = 0; j<9; j++)
            {
                if (board[i][j]=='.')
                {
                    //cout<<i<<" "<<j<<endl;
                    vector<bool>bb1=b1;
                    vector<bool>bb2=b1;
                    vector<bool>bb3=b1;
                    for (int k=0; k<9; k++)
                    {
                        if (board[i][k]!='.')
                        {
                            bb1[int(board[i][k])-int('0')-1]=true;
                            //cout<<int(board[i][k])-int('0')<<endl;
                        }
                        if (board[k][j]!='.')
                        {
                            //cout<<int(board[k][j])-int('0')<<endl;
                            bb2[int(board[k][j])-int('0')-1]=true;
                        }
                    }
                    int iii=i/3,jjj=j/3;
                    for (int k = iii*3; k<=iii*3+2; k++)
                    {
                        for (int l = jjj*3; l<=jjj*3+2; l++)
                        {
                            if (board[k][l]!='.')
                            {
                                //cout<<int(board[k][j])-int('0')<<endl;
                                bb3[int(board[k][l])-int('0')-1]=true;
                            }
                        }
                    }
                    intersection inter;
                    inter.x=i;
                    inter.y=j;
                    inter.b1=bb1;
                    inter.b2=bb2;
                    inter.b3=bb3;
                    total.push_back(inter);
                    // for (int  k= 0; k< 9; k++)
                    // {
                    //    cout<<bb1[k]<<" ";
                    // }
                    // cout<<endl;
                }
            }
        } 
        sort(total.begin(),total.end(),order); // 1-step is finished it was sorted.
        // 2-nd step is start from that position and 
        // for (int i = 0; i < total.size(); i++)
        // {
        //     cout<<total[i].x<<" "<<total[i].y<<endl;
        //     // Next step  is to determine candidates.
        cout<<"It is not problem "<<endl;
            stack<unnormal_operation>q;
            vector<bool>used;
            for (int j = 0; j<total.size(); j++)
            {
                used.push_back(false);
            }
            for (int j = 0; j <9; j++)
            {
                if (total[0].b1[j]==false && total[0].b2[j]==false)
                {
                    vector<int>important;
                    unnormal_operation unnormal;
                    unnormal.position=0;
                    unnormal.used=used;
                    unnormal.forward_used=b1;
                    important.push_back(total[0].x);
                    important.push_back(total[0].y);
                    important.push_back(j);
                    vector<intersection>totall=total;
                   // cout<<j<<endl;
                   for (int yy=1; yy <totall.size(); yy++)
                   {
                        //cout<<totall[yy].x<<" "<<totall[yy].y<<endl;
                        if(totall[yy].x==totall[0].x){
                            totall[yy].b1[j]=true;
                        }
                        if(totall[yy].y==totall[0].y){
                            totall[yy].b2[j]=true;
                        }
                        if ((totall[0].x/3)*3<=totall[yy].x && (totall[0].x/3)*3+2>=totall[yy].x)
                        {
                            if ((totall[0].y/3)*3<=totall[yy].y && (totall[0].y/3)*3+2>=totall[yy].y)
                            {
                                totall[yy].b3[j]=true;
                            }
                        } 
                   }
                   unnormal.vv=totall;
                   unnormal.important=important;
                //    for (int yy=1; yy <totall.size(); yy++)
                //    {
                //         cout<<totall[yy].x<<" "<<totall[yy].y<<endl;
                //         for (int ii = 0; ii <9; ii++)
                //         {
                //             cout<<totall[yy].b1[ii]<<" ";
                //         }
                //         cout<<endl;
                //         for (int ii = 0; ii <9; ii++)
                //         {
                //             cout<<totall[yy].b2[ii]<<" ";
                //         }
                //         cout<<endl;
                //         for (int ii = 0; ii <9; ii++)
                //         {
                //             cout<<totall[yy].b3[ii]<<" ";
                //         }
                //         cout<<endl;
                //         cout<<endl;
                //    }
                   q.push(unnormal);
                }
            }
            while (true)
            {
                // if (cnt==10)
                // {
                //     break;
                // }
                unnormal_operation unnorm=q.top();
                unnorm.position++;
                unnormal_operation unnorm1=unnorm;
                vector<bool>prevff=unnorm.forward_used;
               // cout<<"Uniform position: "<<unnorm.position<<endl;
                // for (int i = 0; i <unnorm.important.size()/3; i++)
                // {
                //     cout<<unnorm.important[i*3]<<" "<<unnorm.important[i*3+1]<<" "<<unnorm.important[i*3+2]<<endl;
                // }
                //cout<<"that is all"<<endl;
                // cout<<unnorm.vv[unnorm.position].x<<"  "<<unnorm.vv[unnorm.position].y<<endl;
                // cout<<endl;
                if (unnorm.position==unnorm.vv.size())
                {
                   // cout<<"*****"<<endl;
                    break;
                }
                // for (int  t= 0; t < unnorm.used.size(); t++)
                // {
                //     cout<<unnorm.used[t]<<" ";
                // }
                // cout<<endl;
                bool exist=false;
                vector<unnormal_operation>willadded;
                for (int j = 0; j<9; j++)
                {
                    if (unnorm.forward_used[j]==true)
                    {
                       continue;
                    }
                    if (unnorm.vv[unnorm.position].b1[j]==false)
                    {
                    if (unnorm.vv[unnorm.position].b2[j]==false)
                    {
                    if (unnorm.vv[unnorm.position].b3[j]==false)
                    {
                       // cout<<"j: "<<j<<endl;
                        exist=true;
                        vector<intersection>totall=unnorm.vv;
                        for (int yy=unnorm.position+1; yy <totall.size(); yy++){
                            //cout<<totall[yy].x<<" "<<totall[yy].y<<endl;
                            if(totall[yy].x==totall[unnorm.position].x){
                                totall[yy].b1[j]=true;
                            }
                            if(totall[yy].y==totall[unnorm.position].y){
                                totall[yy].b2[j]=true;
                            }
                            if ((totall[unnorm.position].x/3)*3<=totall[yy].x && (totall[unnorm.position].x/3)*3+2>=totall[yy].x)
                            {
                                if ((totall[unnorm.position].y/3)*3<=totall[yy].y && (totall[unnorm.position].y/3)*3+2>=totall[yy].y)
                                {
                                    totall[yy].b3[j]=true;
                                }
                            }
                        }
                        unnorm.vv=totall;
                        unnorm.important.push_back(unnorm.vv[unnorm.position].x);
                        unnorm.important.push_back(unnorm.vv[unnorm.position].y);
                        unnorm.important.push_back(j);
                        //    for (int yy=1; yy <totall.size(); yy++)
                        //    {
                        //         cout<<totall[yy].x<<" "<<totall[yy].y<<endl;
                        //         for (int ii = 0; ii <9; ii++)
                        //         {
                        //             cout<<totall[yy].b1[ii]<<" ";
                        //         }
                        //         cout<<endl;
                        //         for (int ii = 0; ii <9; ii++)
                        //         {
                        //             cout<<totall[yy].b2[ii]<<" ";
                        //         }
                        //         cout<<endl;
                        //         for (int ii = 0; ii <9; ii++)
                        //         {
                        //             cout<<totall[yy].b3[ii]<<" ";
                        //         }
                        //         cout<<endl;
                        //         cout<<endl;
                        //    }
                        unnorm.forward_used=b1;          
                        willadded.push_back(unnorm);
                        q.top().forward_used[j]=true;
                        unnorm.important=unnorm1.important;
                        unnorm.vv=unnorm1.vv;
                        unnorm.forward_used=prevff;
                    }
                    }
                    }
                }
                for (int i = 0; i <willadded.size(); i++)
                {
                    q.push(willadded[i]);
                }
                if (exist==false)
                {
                    q.pop();  
                } 
            }
            unnormal_operation unnorm_res=q.top();
            for (int i = 0; i < unnorm_res.important.size()/3; i++)
            {
                char c=char(unnorm_res.important[i*3+2]+int('1'));
                board[unnorm_res.important[i*3]][unnorm_res.important[i*3+1]]=c;
              //  cout<<unnorm_res.important[i*3]<<" "<<unnorm_res.important[i*3+1]<<" "<<unnorm_res.important[i*3+2]<<endl;
            }
            cout<<"[";
            for (int i = 0; i<8; i++)
            {
                cout<<"[";
                for (int j = 0; j <8; j++)
                {
                    cout<<"\""<<board[i][j]<<"\",";
                }
                cout<<"\""<<board[i][8]<<"\"";
                cout<<"],"<<endl;
            }
                cout<<"[";
                for (int j = 0; j <8; j++)
                {
                    cout<<"\""<<board[8][j]<<"\",";
                }
                cout<<"\""<<board[8][8]<<"\"";
                cout<<"]]"<<endl;
    }
};
int main(){
    freopen("37.txt","r",stdin);
    vector<vector<char> >board;
    for (int i = 0; i < 9; i++)
    {
        vector<char>v;
        for (int j = 0; j < 9; j++)
        {
            char c;
            cin>>c;
            v.push_back(c);
        }
        board.push_back(v);
    }
    Solution s;
    s.solveSudoku(board);
    return 0;
}