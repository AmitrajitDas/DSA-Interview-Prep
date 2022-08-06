class Solution {
public:
    
    int memoize(vector<int>& nums, int target, vector<int>& dp){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(auto& num : nums) 
            if(num <= target) dp[target] += memoize(nums, target - num, dp);
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        return memoize(nums, target, dp);
    }
};