class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        
        // Step 2: Group numbers by frequency (Bucket Sort)
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto const& [num, freq] : countMap) {
            buckets[freq].push_back(num);
        }
        
        // Step 3: Fetch the top k elements
        vector<int> result;
        for (int i = n; i >= 0; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                // Return immediately once we have collected k elements
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};
