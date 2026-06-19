class Solution {
public:
    bool isValid(string s) {
         stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }

                char topBracket = st.top();
                st.pop();

                if ((ch == ')' && topBracket != '(') ||
                    (ch == '}' && topBracket != '{') ||
                    (ch == ']' && topBracket != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
        
    }
};