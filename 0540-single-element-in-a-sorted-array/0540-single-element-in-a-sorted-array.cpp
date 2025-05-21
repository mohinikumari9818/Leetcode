class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        // int n=mp.size();
        for(auto it:mp){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};