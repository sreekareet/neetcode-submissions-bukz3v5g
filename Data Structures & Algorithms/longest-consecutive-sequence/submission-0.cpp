class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> lset(nums.begin(), nums.end());
        for(auto &num: nums){
            if(lset.find(num-1) == lset.end()){
                int curr = num;
                int count = 1;
                while(lset.find(curr+1) != lset.end()){
                    curr++;
                    count++;
                }
                maxLen = max(maxLen,count);
            }
        }
        return maxLen;
    }
};
