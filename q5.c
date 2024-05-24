/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void sort(int inorder[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(inorder[i]>inorder[j]){
                int temp = inorder[i];
                inorder[i] = inorder[j];
                inorder[j] = temp;
            }
        }
    }
}
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; ++i) {
        if (arr[i] == value)
            return i;
    }
    return -1; // If not found
}
TreeNode* buildBST(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) // Base case: no elements in inorder traversal
        return NULL;

    // Create a new node with the current postorder element
    TreeNode* node = createNode(postorder[(*postIndex)--]);

    // If the current subtree has only one element
    if (inStart == inEnd)
        return node;

    // Find the index of the current node in inorder traversal
    int inIndex = findIndex(inorder, inStart, inEnd, node->value);

    // Construct right subtree first, because postorder traversal's last element is root
    node->right = buildBST(inorder, postorder, inIndex + 1, inEnd, postIndex);
    // Then construct left subtree
    node->left = buildBST(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}
void levelOrderTraversal(TreeNode * root,int n){
    TreeNode* q[3000];
    int j  = 0;
    int cnt = n;
    q[j] = root;
    cnt--;
    int ind = -1;
    printf("%d ",root->value);
    while(cnt){  
        ind++;
        TreeNode * node = q[ind];
        if(node->left){
            j++;
            q[j] = node->left;
            printf("%d ",q[j]->value);
            cnt--;
        }
        else{
            printf("-1 ");
        }
        if(cnt==0)break;
        if(node->right){
            j++;
            q[j] = node->right;
            printf("%d ",q[j]->value);
            cnt--;
        }
        else{
            printf("-1 ");
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int postorder[n];
    for(int i=0;i<n;i++){
        scanf("%d",&postorder[i]);
    }
    int inorder[n];
    for(int i=0;i<n;i++){
        inorder[i] = postorder[i];
    }
    sort(inorder,n);
    int postIndex = n - 1; // Start from the last element of postorder traversal
    TreeNode* root = buildBST(inorder, postorder, 0, n - 1, &postIndex);
    levelOrderTraversal(root,n);
    return 0;
}

