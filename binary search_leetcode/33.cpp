#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int search(vector<int>& nums, int target){
        if (nums.size()==2)
        {
           if (target!=nums[0] && target!=nums[1])
           {
             return -1;
           }
           if (target==nums[0])
           {
            return 0;
           }
           if (target==nums[1])
           {
             return 1;
           }
        }
        if (nums.size()==1)
        {
           if (target==nums[0])
           {
            return 0;
           }
           else
           {
            return -1;
           }
        }
        //return pos;
        int l=0,r=nums.size()-1;
        int pos1;
    while (true)
        {
            int m=(r-l)/2+l;
           // cout<<"left: "<<l<<" right: "<<r<<endl;
           if (l>r)
           {
             pos1=0;
             break;
           }
           
           // cout<<"middle: "<<nums[m]<<endl;
            if (nums[m]<nums[m-1])
            {
                pos1=m;
                //cout<<"pos1: "<<pos1<<endl;
                break;
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
                r=m-1;
            }
        }
        int pos;
        cout<<"pos1: "<<pos1<<endl;
        if (pos1==0)
        {
            if ((target>=nums[0] && target<=nums[nums.size()-1])==false)
            {
               return -1;
            }
            else
            {
                l=0,r=nums.size()-1;
                int pos;
                while (true)
        {
            int m=(r-l)/2+l;
           // cout<<"left: "<<l<<" right: "<<r<<endl;
           // cout<<"middle: "<<nums[m]<<endl;
            if (l>r)
            {
                return -1;
            }
            if (nums[m]==target)
            {
                pos=m;
               // cout<<"pos: "<<pos<<endl;
                break;
            }
            else
            {
                if (nums[m]>target)
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                }
                
            }  
        }
        return pos;
            }
        }
        cout<<"vfv"<<endl;
        if (target>=nums[0])
        {
            l=0;
            r=pos1-1;
            if (target>nums[r])
            {
                return -1;
            }
        }
        if (target<nums[0])
        {
            l=pos1;
            r=nums.size()-1;
            if (target<nums[l] || target>nums[r] )
            {
                return -1;
            }
        }
        cout<<pos1<<endl;
        while (true)
        {
            int m=(r-l)/2+l;
           // cout<<"left: "<<l<<" right: "<<r<<endl;
           // cout<<"middle: "<<nums[m]<<endl;
            if (l>r)
            {
                return -1;
            }
            if (nums[m]==target)
            {
                pos=m;
               // cout<<"pos: "<<pos<<endl;
                break;
            }
            else
            {
                if (nums[m]>target)
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                }
                
            }  
        }
        return pos;
        // cout<<"pos: "<<pos<<" pos1: "<<pos1<<endl;
        // int res_pos;
        // res_pos=(nums.size()-pos1)+1-(pos1-pos);
        // return res_pos;
        // if (pos>=pos1)
        // {
        //     res_pos=pos-pos1;
        //     return res_pos;
        // }
        // else
        // {
        //     res_pos=nums.size()-(pos1-pos);
        //     return res_pos;
        // }
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