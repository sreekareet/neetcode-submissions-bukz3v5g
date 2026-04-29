class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        for(int right = 0; right < s.size(); right++){
            count[s[right] - 'A']++; //find freq of char
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            //if windowsize - maxfreq <= k then string is valid, otherwise invalid
            //invalid.. shrink the window
            while ( (right - left + 1) - maxFreq > k){
                count[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
