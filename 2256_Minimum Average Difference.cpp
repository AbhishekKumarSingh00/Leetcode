class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        //Solution 1 --------------> O(n) space and time
        /*
        int n = nums.size();
        vector<long long> preSum(n);
        preSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            preSum[i] = preSum[i-1] + nums[i];
        }
        
        long long avgDiff = INT_MAX, temp = INT_MAX, ans = 0;
        for(int i = 0; i < n; i++) {
            
            int first = preSum[i] / (i + 1);
            int second = 0;
            if(i != n-1)
                second = (preSum[n-1] - preSum[i]) / (n - i - 1);
            temp = (int) abs(first - second);
            // cout<<first<<"  "<<second<<"  "<<temp<<endl;
            if(temp < avgDiff) {
                avgDiff = temp;
                ans = i;
            }
        }
        return ans;
        */
        
        //Solution 2 -------> O(n) time O(1) ----> space
        int n = nums.size();
        long long totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        // cout<<totalSum<<endl;
        
        long long avgDiff = INT_MAX, ans = 0, currSum = 0;
        int temp = INT_MAX;
        for(int i = 0; i < n; i++) {
            
            currSum += nums[i];
            long long first = currSum / (i + 1);
            long long second = 0;
            if(i != n-1)
                second = (totalSum - currSum) / (n - i - 1);
            temp = (int) abs(first - second);
            // cout<<first<<"  "<<second<<"  "<<temp<<endl;
            if(temp < avgDiff) {
                avgDiff = temp;
                ans = i;
            }
        }
        return ans;
    }
};