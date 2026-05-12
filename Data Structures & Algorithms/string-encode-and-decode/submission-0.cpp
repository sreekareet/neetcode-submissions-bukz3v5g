class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (auto &s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {

            // read length
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            // extract string
            string str = s.substr(j + 1, len);

            result.push_back(str);

            // move pointer
            i = j + 1 + len;
        }

        return result;
    }
};
