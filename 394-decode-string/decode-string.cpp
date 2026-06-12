class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;

        string currentString;
        int currentNumber = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currentNumber = currentNumber * 10 + (ch - '0');
            }
            else if (ch == '[') {
                st.push({currentString, currentNumber});

                currentString = "";
                currentNumber = 0;
            }
             else if (ch == ']') {
                auto [previousString, repeatCount] = st.top();
                st.pop();

                string expanded = previousString;

                while (repeatCount--) {
                    expanded += currentString;
                }

                currentString = expanded;
            }
            else {
                currentString += ch;
            }
        }
        
        return currentString;
        
    }
};