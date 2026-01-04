class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int l=0;
        int r=n-1;
        bool ans =true;
        while(l<r){
            if(!isalnum(s[l])){
                l++;
                continue;
            }
            if(!isalnum(s[r])){
                r--;
                continue;
            }
            int leftlower=s[l];
            if(leftlower>='A' && leftlower<='Z'){
                leftlower=leftlower+'a'-'A';
            }
            

            int rightlower=s[r];
            if(rightlower>='A' && rightlower<='Z'){
                rightlower=rightlower+'a'-'A';
            }
            

            if(rightlower!=leftlower){
                ans=false;
                break;
            }
            l++;
            r--;
        }
        return ans;
    }
};