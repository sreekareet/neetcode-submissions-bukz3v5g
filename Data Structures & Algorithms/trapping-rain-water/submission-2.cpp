class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        while(left < right ){
            //whichever is less that side should be processed
            //because water can be fiiled between two walls within lesser side height only
            //eg; if left side is 2 and right side is 3 then it can fit in 2 height only
            if(height[left] < height[right]){
                //check for leftMax and calculater water
                leftMax = max(height[left], leftMax);
                water += leftMax - height[left];
                left++;    
            }
            else {
                rightMax = max(height[right], rightMax);
                water += rightMax - height[right];
                right --;
            }
        }
        return water;
    }
};
