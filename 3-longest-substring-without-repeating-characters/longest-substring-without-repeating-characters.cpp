class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            char currentChar = s[right];

            if (lastSeen.count(currentChar) &&
                lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }

            lastSeen[currentChar] = right;

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }

};