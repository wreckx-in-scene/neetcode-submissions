class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26, 0);

        for(char c : tasks) {
            mpp[c - 'A']++;
        }

        priority_queue<int> pq;

        for(int f : mpp) {
            if(f > 0) pq.push(f);
        }

        int time = 0;

        while(!pq.empty()) {
            vector<int> temp;

            for(int i = 1; i <= n + 1 && !pq.empty(); i++) {
                int freq = pq.top();
                pq.pop();

                freq--;
                temp.push_back(freq);
            }

            for(int f : temp) {
                if(f > 0) {
                    pq.push(f);
                }
            }

            if(pq.empty()) {
                time += temp.size();
            } else {
                time += n + 1;
            }
        }

        return time;
    }
};