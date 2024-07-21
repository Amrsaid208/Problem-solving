/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MAX;
    void traverse(TreeNode* root, int curr) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            ans = min(ans, curr);
            return;
        }
        traverse(root->left, curr + 1);
        traverse(root->right, curr + 1);
    }
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        traverse(root, 1);
        return ans;
    }
};