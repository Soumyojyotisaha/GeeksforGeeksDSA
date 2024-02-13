class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        queue<int> q;

        // Enqueue numbers from 1 to 9
        for (int i = 1; i <= 9; ++i) {
            q.push(i);
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current >= low && current <= high) {
                result.push_back(current);
            }

            // Generate the next sequential number
            int lastDigit = current % 10;
            if (lastDigit < 9) {
                int nextNum = current * 10 + (lastDigit + 1);
                q.push(nextNum);
            }
        }

        return result;
    }
};
