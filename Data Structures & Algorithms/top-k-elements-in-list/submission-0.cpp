class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto num:nums){
            freq[num]++;
        }
        //bucket
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        
        for(auto num:freq){
            bucket[num.second].push_back(num.first); //each frequency bucket will have corresponding values
        }
        //now push top k into results vector
        vector<int> result;
        for(int i = n; i >=0 && result.size() < k; i--){
          for(auto num:bucket[i]){
            result.push_back(num);
            if(result.size() == k) //got top k elements
                break;
          }  
        }
        return result;
    }
};
