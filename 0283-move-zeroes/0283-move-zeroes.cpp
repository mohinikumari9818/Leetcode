class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                v.push_back(nums[i]);
            }
        }
        int m=v.size();
        for(int i=0;i<m;i++){
            nums[i]=v[i];
        }
        for(int i=m;i<n;i++){
            nums[i]=0;
        }
        // return nums;
    }
};