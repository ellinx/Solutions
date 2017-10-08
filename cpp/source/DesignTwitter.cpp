#include "../Solutions.hpp"

/***************** Design Twitter *****************/
/*
 Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
 
 postTweet(userId, tweetId): Compose a new tweet.
 getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
 follow(followerId, followeeId): Follower follows a followee.
 unfollow(followerId, followeeId): Follower unfollows a followee.
 
 
 Example:
 
 Twitter twitter = new Twitter();
 
 // User 1 posts a new tweet (id = 5).
 twitter.postTweet(1, 5);
 
 // User 1's news feed should return a list with 1 tweet id -> [5].
 twitter.getNewsFeed(1);
 
 // User 1 follows user 2.
 twitter.follow(1, 2);
 
 // User 2 posts a new tweet (id = 6).
 twitter.postTweet(2, 6);
 
 // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
 twitter.getNewsFeed(1);
 
 // User 1 unfollows user 2.
 twitter.unfollow(1, 2);
 
 // User 1's news feed should return a list with 1 tweet id -> [5],
 // since user 1 is no longer following user 2.
 twitter.getNewsFeed(1);
 */


class Twitter {
private:
    vector<pair<int,int>> tweetList;
    unordered_map<int, unordered_set<int>> users;
public:
    /** Initialize your data structure here. */
    Twitter() {
        tweetList = vector<pair<int,int>>();
        users = unordered_map<int,unordered_set<int>>();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetList.push_back(pair<int,int>(userId,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for (int i=tweetList.size()-1;i>=0;i--) {
            if (userId==tweetList[i].first || users[userId].find(tweetList[i].first)!=users[userId].end()) {
                res.push_back(tweetList[i].second);
            }
            if (res.size()==10) break;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (users[followerId].find(followeeId)!=users[followerId].end()) {
            users[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
