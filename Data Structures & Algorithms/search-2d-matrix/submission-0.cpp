class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //as 2d matrix is sorted use binary search
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows*cols - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            int row  = mid / cols;
            int col = mid % cols;
            int value = matrix[row][col];

            if(value == target)
                return true;
            else if(value < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
    //Time complexity is O(n*m) where n is rows and m is columns and space is O(1)
};
