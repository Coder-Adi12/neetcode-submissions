class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        // Map closing brackets to their corresponding opening brackets
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (closeToOpen.count(c)) {
                // Check if stack is not empty and the top matches the opening bracket
                if (!st.empty() && st.top() == closeToOpen[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                // If it's an opening bracket, push it onto the stack
                st.push(c);
            }
        }

        // If the stack is empty, all brackets were matched correctly
        return st.empty();
    }
};