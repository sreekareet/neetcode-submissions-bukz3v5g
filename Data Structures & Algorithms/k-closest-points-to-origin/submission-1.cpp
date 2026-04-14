class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<pair<int,int>> pq;
      vector<vector<int>> result;
      for(int i = 0 ;i < points.size(); i++)  {
        int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
        pq.push({dist,i});
        if(pq.size() > k){
            pq.pop();
        }
      }
      while(!pq.empty()){
        int index = pq.top().second;
        result.push_back(points[index]);
        pq.pop();
      }
      return result;
    }
};
