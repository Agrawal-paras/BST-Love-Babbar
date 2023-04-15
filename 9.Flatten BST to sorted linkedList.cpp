//store inorder
//left pointer to null
//right pointer to next element
//at last point the last elements to null both right and left pointer

#include<iostream>

void inorderTraversal(TreeNode<int> *root,vector<int> &inorder)
{
    if(root==NULL)
    return ;
    inorderTraversal(root->left,inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right,inorder);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> inorder;
    inorderTraversal(root,inorder);
    int size=inorder.size();

    TreeNode<int> *newRoot=new TreeNode<int>(inorder[0]);
    TreeNode<int> *curr=newRoot;

    for(int i=1;i<size;i++)
    {
        TreeNode<int> *temp=new TreeNode<int>(inorder[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    return newRoot;
}