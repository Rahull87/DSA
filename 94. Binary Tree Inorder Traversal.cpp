#include <stack>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> path;
        TreeNode* current = root;

        while (!stk.empty() || current != NULL) {
            while (current != NULL) {
                stk.push(current);
                current = current->left;
            }
            TreeNode* node = stk.top();
            path.push_back(node->val);
            stk.pop();
            current = node->right;
        }
        return path;
    }
};
