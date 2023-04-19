#include <bits/stdc++.h>
using namespace std;
class Solution {
// 5 1 2 3 4
public:
    int findMin(vector<int>& nums) {
        if (nums.size()==1)
        {
            return nums[0];
        }
        int pos1;
        int l=0,r=nums.size()-1;
       while (true)
        {
            int m=(r-l)/2+l; // nums[m]=2; 
           // cout<<"left: "<<l<<" right: "<<r<<endl;
           if (l>r)
           {
             pos1=0;
             break;
           }
           //cout<<"middle: "<<nums[m]<<endl;
           if (m>0)
           {
            if (nums[m]<nums[m-1])
            {
                pos1=m;
                //cout<<"pos1: "<<pos1<<endl;
                break;
            }
           }
           if (m<nums.size()-1)
           {
                if (nums[m]>nums[m+1])
            {
                pos1=m+1;
                //cout<<"pos1: "<<pos1<<endl;
                break;
            }
           }
            bool b1=(nums[m]>=nums[l]),b2=(nums[m]<=nums[r]);
            if (b1)
            {
                if (b2)
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                } 
            }
            else
            {
               if (b2)
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                } 
            }
        }
        return nums[pos1];
        }
};
int main(){
    int n;
    vector<int>v;
    freopen("153.txt","r",stdin);
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    Solution s;
    cout<<s.findMin(v);
    return 0;
}