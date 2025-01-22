class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        unordered_set<int>st;
        for(int i:arr){
            m[i]++;
        }
        int count=0;
        for(auto i:m){
            st.insert(i.second);
            count++;
        }
        return count==st.size();
    
    }
};