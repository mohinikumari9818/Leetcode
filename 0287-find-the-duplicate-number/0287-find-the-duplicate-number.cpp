class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int s:nums){
            mp[s]++;
        }
        for(auto pair:mp){
            if(pair.second>1){
                return pair.first;
            }
        }
        return 0;
    }
};