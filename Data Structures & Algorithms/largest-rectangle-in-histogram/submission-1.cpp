class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0; i <=n ; i++){
            int currHeight = (i == n)? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int right = i; //current index
                int left = st.empty()? -1 : st.top(); //stack index
                int width = right - left - 1;
                maxArea = max(maxArea, height*width);
            }
            st.push(i); //push indices to calculate width
        }
        return maxArea;
    }
    //Time and space complexity is O(n)
};
