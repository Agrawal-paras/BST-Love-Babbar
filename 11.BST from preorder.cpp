// Approach 1-As like we insert the BT we did time-O(N^2)



//Approach 2
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int maxi=INT_MAX;
        int mini=INT_MIN;
        TreeNode* root= solve(preorder,i,maxi,mini);
        return root;
    }
    TreeNode* solve(vector<int> preorder,int &i,int maxi,int mini)
    {
        if(i >= preorder.size())
        return NULL;

        if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;

        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=solve(preorder,i,root->val,mini);
        root->right=solve(preorder,i,maxi,root->val);
        return root;
     
    }
};