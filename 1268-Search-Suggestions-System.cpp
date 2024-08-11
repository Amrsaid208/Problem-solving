class Solution {
public:
    unordered_map<string, vector<string>> mp;

    class TrieNode {
    public:
        TrieNode* ch[26];
        bool isWord;
        TrieNode() {
            for (auto& x : ch) x = nullptr;
            isWord = false;
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void insert(string word, unordered_map<string, vector<string>>& mp) {
            TrieNode* p = root;
            string currWord = "";
            for (auto x : word) {
                currWord += x;
                if (mp[currWord].size() < 3) {  // Store only top 3 suggestions
                    mp[currWord].push_back(word);
                }
                int idx = x - 'a';
                if (!p->ch[idx]) p->ch[idx] = new TrieNode();
                p = p->ch[idx];
            }
            p->isWord = true;
        }

        vector<string> search(string prefix, unordered_map<string, vector<string>>& mp) {
            return mp[prefix]; // Directly return the precomputed top 3 suggestions
        }
    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie dect;

        // Sort products once to maintain lexicographical order in the Trie
        sort(products.begin(), products.end());

        for (auto s : products) {
            dect.insert(s, mp);
        }

        vector<vector<string>> result;
        string prefix = "";
        for (auto c : searchWord) {
            prefix += c;
            result.push_back(dect.search(prefix, mp)); // Collect suggestions for each prefix
        }
        return result;
    }
};
