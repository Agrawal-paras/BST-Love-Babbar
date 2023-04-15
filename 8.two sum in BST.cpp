//if the target value is 5 then check wheteher 2 and 3 are present in BST
// find inorder of BST 
// use two pointer approach to find the sum


void inorderTraversal(TreeNode* root,vector<int> &inorder)
{
    if(root==NULL)
    return ;
    inorderTraversal(root->left,inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right,inorder);
}

bool twoSumInBST(Node* root,int target)
{
    vector<int> inorder;
    inorderTraversal(root,inorder);
    int i=0,j=inorder.size()-1;
    while(i<j)
    {
        int sum=inorder[i]+inorder[j]
        if(sum==target)
        return true;
        else if(sum>target)
        j--;
        else
        i++;
    }
    return false;
}