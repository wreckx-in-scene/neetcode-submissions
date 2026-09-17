class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";

        for(char ch : s){
            if(isalnum(ch))
                a += tolower(ch);
        }

        int i = 0, j = a.size() - 1;

        while(i <= j){
            if(a[i++] != a[j--]) return false;
        }

        return true;
    }
};