class Solution {
public:

    bool canFinish(vector<int> &piles, int h, int speed){
        long long hours = 0;
        for(auto pile: piles){
            hours += (pile + speed - 1)/speed; //ceil(piles/speed) -- to avoid overflow
        }
        return h >= hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canFinish(piles, h, mid)){
                ans = mid;
                right = mid - 1; //try with less speed as we need to find mimimum k
            }
            else{
                left = mid + 1; //go for higher speed
            }
        }
        return ans;
    }
};
