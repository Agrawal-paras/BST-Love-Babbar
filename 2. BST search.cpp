#include<iostream>
bool searchIntoBST(Node *root,int element)
{
    if(root==NULL)
    return false;

    if(root->data==element)
    return true;

    if(root->data > element)
    return searchIntoBST(root->left, element);

    else
    return searchIntoBST(root->right, element);

}