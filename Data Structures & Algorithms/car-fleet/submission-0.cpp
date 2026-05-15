class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        int n = position.size();
        double time;
        //calculate time to reach target for each
        for(int i = 0; i < n; i++){
            time = (double)(target - position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        //sort by postion
        sort(cars.begin(), cars.end());

        double max_time = 0;
        int fleet = 0;
        // traverse from right (closest to target)
        for(int i = n -1; i >=0 ; i--){
            //if current_time > prev_time then add new fleet
            if(cars[i].second > max_time){
                max_time = cars[i].second;
                fleet++;
            }
        }
        return fleet;
    }
    //Time complexity is O(nlogn) and space is O(n)
};
