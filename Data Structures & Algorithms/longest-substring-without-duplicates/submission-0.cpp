class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int sum = 1;
        for(int i = 0 ; i<s.size() ; i++)
        {
            unordered_set<char> seen;
            seen.insert(s[i]);
            int count = 1;
            for(int j = i+1 ; j <s.size() ; j++)
            {
                if(seen.find(s[j]) == seen.end())
                {
                    seen.insert(s[j]);
                    count++;
                    sum=max(sum,count);
                }
                else
                {
                    break;
                }
            }
        }
        return sum;
    }
};
