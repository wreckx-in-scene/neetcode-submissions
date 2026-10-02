class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wordList) {
        int n = b.length();

        unordered_set<string> List(wordList.begin(), wordList.end());
        unordered_set<string> used;

        queue<pair<string,int>> q;
        q.push({b,1});
        used.insert(b);

        while(!q.empty()){
            auto [word,dist] = q.front();
            q.pop();

            if(word == e)
                return dist;

            for(int i = 0; i < n; i++){
                string original = word;

                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;

                    if(List.count(word) && !used.count(word)){
                        used.insert(word);
                        q.push({word,dist + 1});
                    }
                }

                word = original;
            }
        }

        return 0;
    }
};