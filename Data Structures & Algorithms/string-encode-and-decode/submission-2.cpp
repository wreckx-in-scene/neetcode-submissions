class Solution {
public:
    vector<int> arr;

    string encode(vector<string>& strs) {
        arr.clear();

        string encoded = "";

        for(auto x : strs) {
            encoded += x;
            arr.push_back(x.size());
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int pos = 0;

        for(int i = 0; i < arr.size(); i++) {
            int len = arr[i];
            string add = "";

            for(int j = 0; j < len; j++) {
                add += s[pos];
                pos++;
            }

            res.push_back(add);
        }

        return res;
    }
};