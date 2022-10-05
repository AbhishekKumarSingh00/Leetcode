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
    
private:
    
    void insert(TreeNode* root, int &val, int d, int &depth) {
     
        if(root == NULL)
            return;
        
        if(d == depth - 1) {
            TreeNode* t1 = new TreeNode(val);
            t1->left = root->left;
            root->left = t1;
            
            TreeNode* t2 = new TreeNode(val);
            t2->right = root->right;
            root->right = t2;
        }
        insert(root->left, val, d + 1, depth);
        insert(root->right, val, d + 1, depth);
        
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1) {
            TreeNode* n = new TreeNode(val);
            n -> left = root;
            return n;
        }
        
        insert(root, val, 1, depth);
        return root;
    }
};