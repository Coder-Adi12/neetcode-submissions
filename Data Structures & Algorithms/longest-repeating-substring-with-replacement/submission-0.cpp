class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> count(26, 0);
        int maxCount = 0;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); ++right) {
            // Add the current character to the frequency tracking
            count[s[right] - 'A']++;
            
            // Track the highest frequency of any single character in the current window
            maxCount = std::max(maxCount, count[s[right] - 'A']);

            // If the number of replacements needed exceeds k, shrink the window from the left
            while ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            // Update the maximum window length found so far
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
    
