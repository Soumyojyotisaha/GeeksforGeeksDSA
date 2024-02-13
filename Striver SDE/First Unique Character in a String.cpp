class Solution {
public:
    int firstUniqChar(string s) {
        // Use an unordered_map to store the frequency of each character
        std::unordered_map<char, int> charFrequency;

        // Count the frequency of each character in the string
        for (char c : s) {
            charFrequency[c]++;
        }

        // Iterate through the string to find the first character with a frequency of 1
        for (int i = 0; i < s.size(); ++i) {
            if (charFrequency[s[i]] == 1) {
                return i; // Found the first non-repeating character
            }
        }

        return -1; // No non-repeating character found
    }
};
