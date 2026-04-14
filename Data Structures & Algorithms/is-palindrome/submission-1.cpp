class Solution {
public:
    bool isPalindrome(string s) {
       int left = 0;
        int right = s.size() - 1;
        while(left < right){
            //if its not alphabets or num then ignore
            while(left < right && !isalnum(s[left])) left++; 
            while(left < right && !isalnum(s[right])) right--;
            if(tolower(s[left]) != tolower(s[right])){ //compare by converting it into lower case
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
