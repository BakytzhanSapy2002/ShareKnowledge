#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int left1=0,right1=n;
        int left2=0,right2=n;
        bool found1=false,found2=false;
        vector<int>range;
        while (left1<=right1 || left2<=right2)
        {
            int middle1=(right1-left1)/2+left1;
            int middle2=(right2-left2)/2+left2;
            // Бірінші басталатын жерін табу керек.
            if (nums[middle1]==target)
            {
                if (middle1==0)
                {
                    found1=true;
                    range.push_back(middle);
                    if (found2==true)
                    {
                        return range;
                    } 
                }
                else
                {
                    if (nums[middle1-1]!=target)
                    {
                        found1=true;
                        range.push_back(middle);
                        if (found2==true)
                        {
                            return range;
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
             if (nums[middle2]==target)
            {
                if (middle2==n)
                {
                    found2=true;
                    range.push_back(middle);
                    if (found1==true)
                    {
                        return range;
                    } 
                }
                else
                {
                    if (nums[middle2+1]!=target)
                    {
                        found1=true;
                        range.push_back(middle);
                        if (found2==true)
                        {
                            return range;
                        } 
                    }
                    else
                    {
                        if (nums[middle1+1]==target)
                        {
                            right1=middle1-1;
                        }
                        else
                        {
                            if (middle1-1>=0)
                            {
                                if (nums[middle1-1]==target)
                                {
                                    left1=middle1+1;
                                }
                            }
                        }
                        
                    }
                    
                }
            }
            } 
        }
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
cout<<s.search(v,t)<<endl;
return 0;
}