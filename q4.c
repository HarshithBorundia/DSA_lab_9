#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
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

// Function to search for a value in the inorder array within a given range
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; ++i) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to construct the tree from inorder and preorder traversals
TreeNode* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;
    
    // Pick current node from preorder traversal using preIndex and increment preIndex
    TreeNode* node = createNode(preorder[*preIndex]);
    (*preIndex)++;
    
    // If this node has no children then return
    if (inStart == inEnd)
        return node;
    
    // Else find the index of this node in inorder traversal
    int inIndex = search(inorder, inStart, inEnd, node->value);
    
    // Using index in inorder traversal, construct left and right subtrees
    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);
    
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

int main() {
    int n;
    scanf("%d", &n);
    int inorder[n], preorder[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }
    int preIndex = 0;
    TreeNode* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);
    levelOrderTraversal(root,n);
    return 0;
}


