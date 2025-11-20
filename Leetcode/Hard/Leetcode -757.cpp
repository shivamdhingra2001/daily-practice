class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end() , [](vector<int>&a , vector<int>&b) {
            if(a[1] == b[1])
               return a[0] > b[0];
            else return a[1] < b[1];
        });

        int count = 2;
        int maxi1 = intervals[0][1];
        int maxi2 = intervals[0][1] - 1;
        for(int i = 1; i<intervals.size(); i++) {
            if(intervals[i][0] > maxi1) {
                count+=2;
               maxi1 = intervals[i][1];
               maxi2 = intervals[i][1] - 1;
            }

            else if(intervals[i][0] > maxi2){
                count++;
                maxi2 = maxi1;
                maxi1 = intervals[i][1];
            }
        }
        return count;
    }
};