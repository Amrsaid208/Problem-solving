class TrieNode {
public:
    TrieNode* children[26];
    std::string word;
    TrieNode() : word(\\) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(std::string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = word;
    }
};

class Solution {
public:
    std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    std::unordered_set<std::string> foundWords;

    void backtrack(std::vector<std::vector<char>>& board, TrieNode* node, int row, int col) {
        char c = board[row][col];
        if (c == '#' || node->children[c - 'a'] == nullptr) return;

        node = node->children[c - 'a'];
        if (node->word != \\) {
            foundWords.insert(node->word);
        }

        board[row][col] = '#';  // mark the cell as visited
        for (auto dir : dirs) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size()) {
                backtrack(board, node, newRow, newCol);
            }
        }
        board[row][col] = c;  // unmark the cell
    }

    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        Trie trie;
        for (std::string word : words) {
            trie.insert(word);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                backtrack(board, trie.root, i, j);
            }
        }

        return std::vector<std::string>(foundWords.begin(), foundWords.end());
    }
};