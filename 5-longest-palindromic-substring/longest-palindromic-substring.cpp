class Solution {
public:
    bool isPalindrome(string &s){
        int j =s.size()-1;
        int i=0;

        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        int n = s.size();

        for(int i=0;i<n;i++) {
            string temp = "";
            for(int j=i;j<n;j++) {
                temp += s[j];
                if(isPalindrome(temp) && temp.size() > ans.size()){
                    ans = temp;
                }
            }

        }
        return ans;
    }
};