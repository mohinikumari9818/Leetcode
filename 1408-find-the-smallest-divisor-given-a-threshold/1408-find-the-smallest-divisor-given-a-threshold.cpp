class Solution {
public:
    int getSum(vector<int>& nums, int divisor) {
            int total = 0;
            for (int num : nums) {
                total += (num + divisor - 1) / divisor; // ceil division
            }
            return total;
        }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = getSum(nums, mid);

            if (sum <= threshold) {
                ans = mid;        // possible answer, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;    // too big, need a bigger divisor
            }
        }

        return ans;
    }
};