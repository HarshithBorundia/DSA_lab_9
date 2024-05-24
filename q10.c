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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(TreeNode* node) {
    if (node == NULL || node->value==-1)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL || root->value==-1)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
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

    int diameter = diameterOfBinaryTree(nodes[0]);
    printf("%d\n", diameter);

    return 0;
}


