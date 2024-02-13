class Solution {
public:
    int numSquares(int n) {
        // Create a vector to store the minimum number of perfect squares required for each number from 0 to n
        std::vector<int> dp(n + 1, INT_MAX);
        
        // Initialize dp[0] as 0 since it doesn't require any perfect squares to sum up to 0
        dp[0] = 0;
        
        // Iterate from 1 to n to fill the dp array
        for (int i = 1; i <= n; ++i) {
            // Iterate over each possible perfect square number less than or equal to i
            for (int j = 1; j * j <= i; ++j) {
                // Update dp[i] by choosing the minimum between its current value and dp[i - j*j] + 1
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        // Return the minimum number of perfect squares required to sum up to n
        return dp[n];
    }
};
