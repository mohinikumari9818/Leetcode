class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int>mp;
        vector<int>answer;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                count++;
                mp[count]=i;
            }
        }
        for(auto i:queries){
            if(mp.find(i)==mp.end()){
                answer.push_back(-1);
            }
            else{
                answer.push_back(mp[i]);
            }
        }
        return answer;
    }
};