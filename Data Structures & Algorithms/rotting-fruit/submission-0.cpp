class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int freshCount = 0;

        queue<pair<int,int>> q;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1)
                    freshCount++;
            }
        }
        //bfs
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty() && freshCount > 0){
            int level = q.size();
            minutes++;
            for(int i = 0; i < level; i++){
                auto [row,col] = q.front();
                q.pop();
                
                for(auto [dr,dc]: directions){
                    int newRow = dr + row;
                    int newCol = dc + col;
                    
                    if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || grid[newRow][newCol] != 1)
                        continue;
                    
                    grid[newRow][newCol] = 2;  // mark rotten
                    freshCount--;

                    q.push({newRow, newCol});


                }
            }
        }
        if(freshCount > 0) return -1;
        return minutes;
    }
};
