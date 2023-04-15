/*
APPROACH 1-

1.DONO BST KO INORDER ME CONVERT 
2.DO SORTED ARRAY(INORDER) KO MERGE
3.INORDER KO BALANCED BST ME CONVERT


    Time Complexity : O(N + M)
    Space Complexity : O(N + M)

    Where,‘N’ and ‘M’ are the number of nodes in the
    first BST and the second BST respectively.

*/

// Function to store the inorder traversal of tree in a list.
void storeInOrder(TreeNode<int> *root, vector<int> &arr) {
    if (root != NULL) {
        storeInOrder(root->left, arr);
        arr.push_back(root->data);
        storeInOrder(root->right, arr);
    }
}

// Function to merge two sorted array/lists.
vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
    int i = 0, j = 0;
    vector<int> arr;
    
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arr.push_back(arr1[i]);
            i++;
        } else {
            arr.push_back(arr2[j]);
            j++;
        }
    }
    
    while (i < arr1.size()) {
        arr.push_back(arr1[i]);
        i++;
    }
    
    while (j < arr2.size()) {
        arr.push_back(arr2[j]);
        j++;
    }
    
    return arr;
}

// Function to convert sorted array-list to balanced BST.
TreeNode<int> *constructBSTFromSortedArray(vector<int> &arr, int start, int end) {
    // Base case.
    if (start > end) {
        return NULL;
    }
    
    int mid = (start + end) / 2;
    
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = constructBSTFromSortedArray(arr, start, mid - 1);
    root->right = constructBSTFromSortedArray(arr, mid + 1, end);
    return root;
}

 TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
    // Store the in-order traversal of tree1 in an array.
    vector<int> temp1;
    storeInOrder(root1, temp1);
    
    // Store the in-order traversal of tree2 in an array.
    vector<int> temp2;
    storeInOrder(root2, temp2);
    
    // Merge the two sorted arrays.
    vector<int> final = mergeSortedArrays(temp1, temp2);
    
    // Construct the balanced BST from this sorted array.
    return constructBSTFromSortedArray(final, 0, final.size() - 1);
}




/* 
APPROACH-2

1.CONVERT A BST INTO DOUBLY LINKED LIST
2.MERGE TWO SORTED LINKED LIST
3.SORTED LINKED LIST TO BST


Time Complexity : O(N + M)
Space Complexity : O(H1+H2)

*/

void convertIntoSortedDLL(TreeNode<int> *root,TreeNode<int>* &head)
{
    if(root==NULL)
    return NULL;

    convertIntoSortedDLL(root->right,head);

    root->right=head;

    if(head!=NULL)
    head->left=root;

    head=root;

    convertIntoSortedDLL(root->left,head);
}

TreeNode<int>* mergeLinkedList(TreeNode<int> *head1,TreeNode<int> *head2)
{
    TreeNode<int> *head=NULL;
    TreeNode<int> *tail=NULL;

    while(head1 != NULL && head2 != NULL)
{
    if(head1->data < head2->data)
    {
        if(head==NULL)
        {
            head=head1;
            tail=head1;
            head1=head1->right;
        }
        else
        {
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
        }
    }
    else
    {
        if(head==NULL)
        {
            head=head2;
            tail=head2;
            head2=head2->right;
        }
        else
        {
           tail->right=head2;
            head2->left=tail;
            tail=head2;
            head2=head2->right; 
        }
    }
}
}

int countNodes(TreeNode<int>* head)
{
    int cnt=0;
    TreeNode<int>* temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->right;
    }
    return cnt;
}


TreeNode<int>* sortedLLToBST(TreeNode<int>* &head ,int n)
{
    if(n<=0 || head==NULL)
    {
        return NULL;
    }

    TreeNode<int>* left=sortedLLToBST(head,n/2);
    TreeNode<int>* root=head;

    root->left=left;

    head=head->next;

    root->right=sortedLLToBST(head,n-n/2-1);
    return root;
}


TreeNode<int> * mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {


TreeNode<int> *head1=NULL;
convertIntoSortedDLL(root1,head1);
head1->left=NULL;

TreeNode<int> *head2=NULL;
convertIntoSortedDLL(root2,head2);
head2->left=NULL;

TreeNode<int> *head=mergeLinkedList(head1,head2);

return sortedLLToBST(head,countNodes(head));

}