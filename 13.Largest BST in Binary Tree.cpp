/*
    Time Complexity: O(N^2)
    Space Complexity: O(N)
    
    where 'N' is the total number of nodes in the binary tree.
*/

bool isBST(TreeNode<int>* root, int min, int max)
{
	if (root == NULL)
	{
		return true;
	}

	if (root -> data < min || root -> data > max)
	{
		return false;
	}

	return isBST(root -> left, min, root -> data - 1) && 
		   isBST(root -> right, root -> data + 1, max);
}


int size(TreeNode<int>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	
	return 1 + size(root -> left) + size(root -> right);
}


int largestBST(TreeNode<int>* root)
{
	// Current Subtree is BST.
	if (isBST(root, INT_MIN, INT_MAX) == true)
	{
		return size(root);
	}
	
	// Find largest BST in left and right subtrees.
	return max(largestBST(root -> left), largestBST(root -> right));
}    



/*APPROACH-2


Time Complexity: O(N)
Space Complexity: O(N)
*/

class info{
	public:
        	int maxi;
			int mini;
			bool isBST;
			int size;
};

info solve(TreeNode<int>* root, int &ans)
{
	if(root==NULL)
	{
		return {INT_MIN, INT_MAX, true, 0};
	}

	info left = solve(root->left, ans);
	info right = solve(root->right, ans);

	info currNode;

	currNode.size = left.size + right.size + 1;
	currNode.maxi = max(root->data, right.maxi);
	currNode.mini = min(root->data, left.mini);

	if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
	{
		currNode.isBST = true;
	}
	else
	{
		currNode.isBST = false;
	}

	if(currNode.isBST)
	ans = max(ans, currNode.size);

	return currNode;

}

int largestBST(TreeNode<int>* root)
{
	int maxsize = 0;
    info temp = solve(root, maxsize);
	return maxsize;
}