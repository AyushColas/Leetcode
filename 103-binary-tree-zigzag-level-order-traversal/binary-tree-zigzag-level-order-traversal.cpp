/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { 
         vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> elements(levelSize);

            for(int i=0; i<levelSize; i++){
                TreeNode* node = q.front();
                q.pop();

                elements[i] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(!leftToRight) reverse(elements.begin(),elements.end());

            result.push_back(elements);
            leftToRight = !leftToRight;
        }

        return result;
    }
};