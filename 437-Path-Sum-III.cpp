class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, long long currSum) {
        if (!root) return;

        currSum -= root->val;
        if (currSum == 0) {
            ans++;
        }

        dfs(root->left, currSum);
        dfs(root->right, currSum);
    }

    void pathSumFromNode(TreeNode* node, int targetSum) {
        if (!node) return;

        dfs(node, static_cast<long long>(targetSum)); 
        pathSumFromNode(node->left, targetSum); 
        pathSumFromNode(node->right, targetSum); 
    }

    int pathSum(TreeNode* root, int targetSum) {
        pathSumFromNode(root, targetSum);
        return ans;
    }
};
