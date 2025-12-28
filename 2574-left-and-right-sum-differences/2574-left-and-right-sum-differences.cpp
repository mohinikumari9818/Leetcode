class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n);
        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);
        // int lefttotal=0;
        // int righttotal=0;
        for(int i=1;i<n;i++){
            if(i==0){
                leftsum.push_back(0);
            }
            leftsum[i]=(nums[i-1]+leftsum[i-1]);
            // leftsum.push_back(lefttotal);
        }
        for(int i=n-2;i>=0;i--){
            if(i==0){
                rightsum.push_back(0);
            }
            rightsum[i]=(nums[i+1]+rightsum[i+1]);
            // rightsum.push_back(righttotal);
        }
        for(int i=0;i<n;i++){
            answer[i]=abs(leftsum[i]-rightsum[i]);
            // answer.push_back(diff);
        }
        return answer;

    }
};