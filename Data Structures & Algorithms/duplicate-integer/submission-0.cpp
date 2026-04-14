class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> freq;
        for(auto num: nums){
            if(freq.find(num) != freq.end()){
                return true;
            }
            freq.insert(num);
        }
        return false;
    }
};