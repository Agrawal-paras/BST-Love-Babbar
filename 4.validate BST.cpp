//approach 1-inorder traversal should be sorted



//Approach-2-

#include<iostream>
int main()
{
  bool check= validateBST(root,INT_MAX,INT_MIN);
  return check;
}
bool validateBST(Node *root,int max,int min)
{ 
    if(root==NULL)
    return true;
    if(root->data < max && root->data > min)
    {
        bool left=validateBST(root->left, root->data, min);
        bool right=validateBST(root->right, max, root->data);
        return left && right;
    }
    else
    return false;
}