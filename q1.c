/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int maxPathSum(TreeNode* root, int* maxSum) {
    if (root == NULL || root->value==-1) return 0;

    // Recursively calculate the maximum path sum for left and right subtrees
    int leftSum = maxPathSum(root->left, maxSum);
    int rightSum = maxPathSum(root->right, maxSum);

    // Calculate the maximum path sum ending at the current node
    int maxEndingHere = root->value + (leftSum > 0 ? leftSum : 0) + (rightSum > 0 ? rightSum : 0);

    // Update the global maximum path sum if needed
    *maxSum = (*maxSum > maxEndingHere) ? *maxSum : maxEndingHere;

    // Return the maximum path sum ending at the current node
    return root->value + ((leftSum > rightSum) ? leftSum : rightSum);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    TreeNode** nodes = (TreeNode**)malloc(n * sizeof(TreeNode*));
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(a[i]);
    }
    for (int i = 0; i < n; i++) {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;
        if (leftChildIndex < n) {
            nodes[i]->left = nodes[leftChildIndex];
        }
        if (rightChildIndex < n) {
            nodes[i]->right = nodes[rightChildIndex];
        }
    }
    int maxSum = INT_MIN;

    // Calculate the maximum path sum
    maxPathSum(nodes[0], &maxSum);

    // Output the maximum path sum
    printf("%d\n", maxSum);

    return 0;
}

