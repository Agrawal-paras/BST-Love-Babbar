// approach 1- inorder traversal and find predecessor and successor time-O(N) and space-O(N)



//approach-2:-
// predecessor will be the right most child of left subtree
// successor will be the left most child of the right subtree

void findPreSuc(Node *root,Node* &pre,Node* &suc,int key)
{
    if(root==NULL)
    return;

    if(root->key==key)
    {
        if(root->left!=NULL)
        {
            Node *temp=root->left;
            while(temp->right!=NULL)
            {
                temp=temp->right;
                pre=temp;
            }

        }
        if(root->right!=NULL)
        {
            Node *temp=root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
                suc=temp;
            }
        }
        
        return;
    }
    if(root->key>key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else
    {
    pre=root;
    findPreSuc(root->right,pre,suc,key);
}
}

