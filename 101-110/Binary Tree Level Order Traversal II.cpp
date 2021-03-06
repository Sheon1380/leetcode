/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//DFS
class Solution {
public:
    vector< vector<int> > ans;
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        levelorder(root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void levelorder(TreeNode* node, int level){
        if(node == NULL)
            return;
        if(level == ans.size())
            ans.push_back({});
        ans[level].push_back(node -> val);
        levelorder(node -> left, level + 1);
        levelorder(node -> right, level + 1);
    }
};

//BFS
class Solution {
public:
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > ans;
        vector<int> temp;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                auto p = q.front();
                temp.push_back(p -> val);
                q.pop();
                if(p -> left != NULL)
                    q.push(p -> left);
                if(p -> right != NULL)
                    q.push(p -> right);
            }
            ans.push_back(temp);
            temp.clear();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
