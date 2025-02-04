class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count=0;
        int sum1=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            sum1+=nums[i];
            int sum=0;
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                
            }
            if((sum-sum1)%2==0){
                count++;
            }
            
        }
        return count;
    }
};