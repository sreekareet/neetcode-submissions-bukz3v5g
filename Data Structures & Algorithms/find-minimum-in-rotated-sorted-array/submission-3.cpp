class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right]){
                //means min number is in right side and left array is sorted
                left = mid + 1; //move and search in right
            }
            else{
                //min is in left side
                //min can be in mid position also(min == mid) so right = mid -1 is not done
                right = mid; 
            }
        }
        return nums[left];
    }
    //Time complexity is O(logn) and space complexity is O(1)
};
