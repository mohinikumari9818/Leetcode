class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n=nums.size();
      
       for(int i=0;i<n;i++){
         int count=1;
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count>(n/2)){
            return nums[i];
        }
        
       }
       return -1;
//         int n=nums.size();
//         int max_count=1;
//         int count=1;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<n-1;i++){
//             if(nums[i]==nums[i+1]){
//                 count++;
//             }
//             else{
//                 count=1;
//             }
//             max_count=max(max_count,count);
//         }
//        for(int i=0;i<n;i++){
//         if(nums[i]==nums[i+1]){
//             count++;
//         }
//         else{
//             count=1;
//         }
//         if(count==max_count){
//             return max_count[i];
//         }
//        }
    }

};