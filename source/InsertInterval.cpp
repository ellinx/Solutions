#include "../Solutions.hpp"

using namespace std;

/***************** Insert Interval *****************/
/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

vector<Interval> Solutions::insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    if (intervals.empty()) {
        res.push_back(newInterval);
        return res;
    }
    for (int i=0;i<intervals.size();i++) {
        if (newInterval.start>intervals[i].end) {
            res.push_back(intervals[i]);
        } else {
            if (newInterval.start>=intervals[i].start) {
                newInterval.start = intervals[i].start;
            }
            while (newInterval.end>intervals[i].end) {
                i++;
                if (i==intervals.size()) {
                    res.push_back(newInterval);
                    return res;
                }
            }
            if (newInterval.end<intervals[i].start) {
                res.push_back(newInterval);
                while (i<intervals.size()) {
                    res.push_back(intervals[i++]);
                }
                return res;
            } else {
                newInterval.end = intervals[i].end;
                res.push_back(newInterval);
                i++;
                while (i<intervals.size()) {
                    res.push_back(intervals[i++]);
                }
                return res;
            }
        }
    }
    res.push_back(newInterval);
    return res;
}
