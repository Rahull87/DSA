class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
    
    void preorder(TreeNode* curr, TreeNode* par) {
        if (!curr) return;
        
        parent[curr] = par;
        preorder(curr->left, curr);
        preorder(curr->right, curr);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        preorder(root, nullptr);
        
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        
        while (!q.empty() && k) {
            k--;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                visited.insert(curr);
                
                if (!visited.count(curr->left) && curr->left)   q.push(curr->left);
                if (!visited.count(curr->right) && curr->right)  q.push(curr->right);
                if (!visited.count(parent[curr]) && parent[curr]) q.push(parent[curr]);
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        
        return ans;
    }
};
