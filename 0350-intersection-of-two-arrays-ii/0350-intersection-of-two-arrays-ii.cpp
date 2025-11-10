class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> v;
        unordered_map<int,int> mp1;
        for(int num:nums1){
            mp1[num]++;
        }
        for(int f:nums2){
            if(mp1[f]>0){
                v.push_back(f);
                mp1[f]--;
            }
        }
        return v;
    }
};