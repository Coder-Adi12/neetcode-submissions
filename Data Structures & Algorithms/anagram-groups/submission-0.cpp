class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;
        
        for (const string& s : strs) {
            // Create a key of length 26 initialized with null characters
            string key(26, 0); 
            
            // Increment the count for each character
            for (char c : s) {
                key[c - 'a']++;
            }
            
            // Group the original string under this frequency key
            anagram_map[key].push_back(s);
        }
        
        vector<vector<string>> result;
        // Iterate through the map to gather all grouped anagrams
        for (auto& pair : anagram_map) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
