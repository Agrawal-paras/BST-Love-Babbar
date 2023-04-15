//it takes space of O(N) in the form of vector

class Solution {
public:
void inorderTraversal(TreeNode* root,vector<int> &inorder)
{
    if(root==NULL)
    return ;
    inorderTraversal(root->left,inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right,inorder);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
        return inorder[k-1];

    }
};


// it did not take space

int kthSmallest(TreeNode* root, int k) 
{
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

int solve(treeNode* root,int &i,int k)
{
    if(root==NULL)
    return -1;

    int left=solve(root->left,i,k);

    if(left!=-1)
    return left;

    i++;
    if(i==k)
    {
        return root->data;

    }
    return solve(root->right,i,k);    
}