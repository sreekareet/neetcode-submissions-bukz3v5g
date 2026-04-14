class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        int maxLen = 0;
        int left = 0;
        unordered_map<char,int> lastIndex;
        for(int right=0; right<s.size(); right++){
            if (lastIndex.count(s[right])) {
                left = max(left, lastIndex[s[right]]+1);
            }
            lastIndex[s[right]] = right;
            maxLen = max(right-left+1, maxLen);
            
        }
        return maxLen;
    }
};
