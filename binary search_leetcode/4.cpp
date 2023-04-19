#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int start1=0,start2=0,total_size=nums1.size()+nums2.size();
        if (nums1.size()==0){
            if (total_size%2==0){
            double f=nums2[total_size/2]+nums2[total_size/2-1];
            return f/2;
            }
            else{
                return nums2[total_size/2];
            }
        }
        if (nums2.size()==0){
            if (total_size%2==0){
            double f=nums1[total_size/2]+nums1[total_size/2-1];
            return f/2;
            }
            else{
                return nums1[total_size/2];
            }
        }
        while(true){
            if (nums1[start1]==nums2[start2]){
                int t=nums1[start1];
                v.push_back(t);
                v.push_back(t);
                start1++;
                start2++;
                if (start1==nums1.size()){
                    for(int i=start2; i<nums2.size();i++){
                        v.push_back(nums2[i]);
                    }
                    break;
                }
                if (start2==nums2.size()){
                    for(int i=start1; i<nums1.size();i++){
                        v.push_back(nums1[i]);
                    }
                    break;
                }
            }
            else{
                if (nums1[start1]<nums2[start2]){
                    int t1=nums1[start1];
                    v.push_back(t1);
                    start1++;
                    if (start1==nums1.size()){
                    for(int i=start2; i<nums2.size();i++){
                        v.push_back(nums2[i]);
                    }
                    break;
                }
                }
                else{
                    int t2=nums2[start2];
                    v.push_back(t2);
                    start2++;
                    if (start2==nums2.size()){
                    for(int i=start1; i<nums1.size();i++){
                        v.push_back(nums1[i]);
                    }
                    break;
                }
                }  
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        if (total_size%2==0){
            double f=v[total_size/2]+v[total_size/2-1];
            return f/2;
    }
        else{
            return v[total_size/2];
        }
    }
};
int main(){
    int m,n;
    cin>>m>>n;
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin>>a;
        v1.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int b;
        cin>>b;
        v2.push_back(b);
    }
    Solution s1;
    cout<<s1.findMedianSortedArrays(v1,v2)<<endl;
    
}