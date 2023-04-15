// A Balanced BST is in which the height of two subtrees of every node differs no more than 1;
// we have to create Balanced BST
/*

    Time Complexity : O(N)
    Space Complexity : O(N)

    Where N is the number of nodes in BST.

*/

// Inorder traversal of the tree.
void inorder(TreeNode<int>* root, vector<int>& inorderArray) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, inorderArray);
    inorderArray.push_back(root -> data);
    inorder(root->right, inorderArray);
}

TreeNode<int>* bst(vector<int>& inorderArray, int start, int end) {
    if (start > end) {
        return NULL;
    }

    // Get the middle of the array and make it as the new root.
    int mid = (start + end) / 2;

    TreeNode<int>* root = new TreeNode<int> (inorderArray[mid]);

    // Make the left half of array as the left subtree.
    root -> left = bst(inorderArray, start, mid - 1);

    // Make the right half of array as the right subtree.
    root -> right = bst(inorderArray, mid + 1, end);

    return root;

}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Array to store the nodes in the order of inorder traversal.
    vector<int> inorderArray;

    inorder(root, inorderArray);

    int n = inorderArray.size();

    return bst(inorderArray, 0, n-1);
}