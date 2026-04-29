class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int sufix = 1;
        int prefix = 1;
        vector<int> prod(n,1);
        for(int i = 0; i < n ; i++){
            prod[i] = prefix;
            prefix *= nums[i];
        }
        for(int i = n-1; i >= 0 ; i--){
            prod[i] *= sufix;
            sufix *= nums[i];
        }
        return prod;
    }
};
