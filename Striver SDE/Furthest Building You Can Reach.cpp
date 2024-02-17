class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        return solve(heights, 0, bricks, ladders, n);
    }

    int solve(const vector<int>& heights, int i, int bricks, int ladders, int n) {
        if (i == n - 1) return i;
        int diff = heights[i + 1] - heights[i];
        if (diff > 0) {
            int ans = i;
            if (bricks >= diff) {
                ans = max(ans, solve(heights, i + 1, bricks - diff, ladders, n));
            }
            if (ladders > 0) {
                ans = max(ans, solve(heights, i + 1, bricks, ladders - 1, n));
            }
            return ans;
        } else {
            return solve(heights, i + 1, bricks, ladders, n);
        }
    }
};
