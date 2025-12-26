class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>v;
    //     // set<vector<int>>s;
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++ ){
    //             for(int k=j+1;k<n;k++){
    //                 if(nums[i]+nums[j]+nums[k]==0){
    //                     v.push_back({nums[i],nums[j],nums[k]}) ;
    //                 }
    //             }
    //         }
    //     }
    //     // for(auto triplet:s){
    //     //     v.push_back(triplet);
    //     // }
    //     return v;
    // }
     vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate left & right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return result;
    }
};