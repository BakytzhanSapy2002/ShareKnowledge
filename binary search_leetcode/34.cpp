#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int n=nums.size()-1;
        int left1=0,right1=n;
        int left2=0,right2=n;
        vector<int>range;
        bool found1=false,found2=false;
        while (left1<=right1 && left2<=right2)
        {
            int middle1=(right1-left1)/2+left1;
            int middle2=(right2-left2)/2+left2;
            //Бірінші басталатын жерін табу керек.
            cout<<nums[left1]<<" "<<nums[middle1]<<" "<<nums[right1]<<endl;
            cout<<left1<<" "<<middle1<<" "<<right1<<endl;
            cout<<nums[left2]<<" "<<nums[middle2]<<" "<<nums[right2]<<endl;
            cout<<left2<<" "<<middle2<<" "<<right2<<endl;
            cout<<endl;
            if (nums[middle1]==target && found1==false)
            {
                if (middle1==0)
                {
                    found1=true;
                    if (found2==true)
                    {
                        if (range.size()==0)
                            {
                                range.push_back(middle1);
                                range.push_back(middle2);
                                return range;
                            }
                            else
                            {
                                range.push_back(middle2);
                                return range;
                            }
                    }
                    else
                    {
                       if (range.size()==0)
                       {
                        range.push_back(middle1);
                       }
                    }
                }
                else
                {
                    if (nums[middle1-1]!=target)
                    {
                        found1=true;
                        if (found2==true)
                        {
                            if (range.size()==0)
                            {
                                range.push_back(middle1);
                                range.push_back(middle2);
                                return range;
                            }
                            else
                            {
                                range.push_back(middle2);
                                return range;
                            }
                            
                        }
                        else
                        {
                            if (range.size()==0)
                            {
                                range.push_back(middle1);
                            }
                        }
                    }
                    else
                    {
                        if (nums[middle1-1]==target)
                        {
                            right1=middle1-1;
                        }
                        else
                        {
                            if (middle1+1<=n)
                            {
                                if (nums[middle1+1]==target)
                                {
                                    left1=middle1+1;
                                }
                            }
                        }
                        
                    }
                    
                }
            }
            if (nums[middle1]<target)
            {
                left1=middle1+1;
                //cout<<"Changed left1 : "<<left1<<endl;
            }
            if (nums[middle1]>target)
            {
                right1=middle1-1;
                //cout<<"Changed right1 : "<<right1<<endl;
            }
             if (nums[middle2]==target && found2==false)
            {
                if (middle2==n)
                {
                    found2=true;
                    if (found1==true)
                    {
                        if (range.size()==0)
                            {
                                range.push_back(middle1);
                                range.push_back(middle2);
                                return range;
                            }
                            else
                            {
                                range.push_back(middle2);
                                return range;
                            }
                    } 
                }
                else
                {
                    if (nums[middle2+1]!=target && found2==false)
                    {
                        found2=true;
                        if (found1==true)
                        {
                            if (range.size()==0)
                            {
                                range.push_back(middle1);
                                range.push_back(middle2);
                                return range;
                            }
                            else
                            {
                                range.push_back(middle2);
                                return range;
                            }
                        } 
                    }
                    else
                    {
                        if (nums[middle2+1]==target)
                        {
                            left2=middle2+1;
                        }
                        else
                        {
                            if (middle2-1>=0)
                            {
                                if (nums[middle2-1]==target)
                                {
                                    right2=middle2-1;
                                }
                            }
                        }
                        
                    }
                    
                }
            }
            if (nums[middle2]<target)
            {
                left2=middle2+1;
                //cout<<"Changed left2 : "<<left2<<endl;
            }
            if (nums[middle2]>target)
            {
                right2=middle2-1;
                //cout<<"Changed right2 : "<<right2<<endl;
            }
            }
            range.push_back(-1);
            range.push_back(-1);
            return range;
        }
};
int main(){
int n;
cin>>n;
vector<int>v;
for (int i = 0; i < n; i++)
{
    int x;
    cin>>x;
    v.push_back(x);
}
int t;
cin>>t;
Solution s;
vector<int>v2=s.searchRange(v,t);
if (v2.size()==0)
{
    cout<<"["<<-1<<","<<-1<<"]"<<endl;
}
else cout<<"["<<v2[0]<<","<<v2[1]<<"]"<<endl;
return 0;
}