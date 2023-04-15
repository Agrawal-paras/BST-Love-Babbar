#include<iostream>
Node* lca(Node* root,Node* p,Node* q)
{
    if(root==NULL)
    return NULL;
    if(root->data > p->data && root->data > q->data)
    return lca(root->left,p,q);
    if(root->data < p && root->data < q)
    return lca(root->right,p,q);
    return root;

}

//iterative solution for space complexity- O(1)

#include<iostream>
Node* lca(Node* root,Node* p,Node* q)
{
    while(root!=NULL)
    {

     if(root->data > p->data && root->data > q->data)
     root=root->left;
     
     else if(root->data < p && root->data < q)
     root=root->right;

     else
     return root;
    }
}