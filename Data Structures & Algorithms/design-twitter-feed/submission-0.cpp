class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> user_db;
    unordered_map<int, unordered_set<int>> follows;
    int time;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        time++;
        user_db[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;

        // own tweets
        for(auto tweet : user_db[userId]) {
            pq.push(tweet);
        }

        // followed users' tweets
        for(auto followee : follows[userId]) {
            for(auto tweet : user_db[followee]) {
                pq.push(tweet);
            }
        }

        while(pq.size() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};