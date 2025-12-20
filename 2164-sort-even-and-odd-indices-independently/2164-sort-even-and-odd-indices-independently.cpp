class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int> v,v1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                v.push_back(nums[i]);
            }
            else{
                v1.push_back(nums[i]);
            }
        }
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end(),greater<int>());
        int even=0;
        int odd=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=v[even++];
            }
            else{
                nums[i]=v1[odd++];
            }
        }
        return nums;

    }
};