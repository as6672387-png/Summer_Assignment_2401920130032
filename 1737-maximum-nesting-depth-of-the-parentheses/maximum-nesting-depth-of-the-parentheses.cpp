class Solution {
public:
    int maxDepth(string s) {
        int i=0;
        int count=0;int maxi=0;
        for(i=0;i<s.length();i++) {
            if(s[i] == '(') count++;
            if(s[i] == ')') count--;

            maxi = max(maxi,count);
        }
        return maxi;
        
    }
};