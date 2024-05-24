#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Function to construct the tree
void newTree(int a[], int ind, int n) {
    if (ind >= n) return;
    a[ind] = -1;
    newTree(a, 2 * ind + 1, n);
    newTree(a, 2 * ind + 2, n);
}

// Function to find the height of the tree
int findHeight(int a[], int ind, int n) {
    if (ind >= n || a[ind] == -1) // Base case: leaf node or NULL node
        return 0;
    int leftHeight = findHeight(a, 2 * ind + 1, n);
    int rightHeight = findHeight(a, 2 * ind + 2, n);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight); // Return the maximum height of left and right subtrees
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ind = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            ind = i;
            break;
        }
    }
    newTree(a, ind, n);
    int height = findHeight(a, 0, n);
    printf("%d\n", height);
    
    return 0;
}

