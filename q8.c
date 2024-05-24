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
void dfs(struct TreeNode* node, int depth, long long* total_distance) {
    if (node == NULL || node->value==-1)
        return;
    *total_distance += depth;
    dfs(node->left, depth + 1, total_distance);
    dfs(node->right, depth + 1, total_distance);
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
    long long ans = 0;
    dfs(nodes[0],0,&ans);
    printf("%lld",ans);

    return 0;
}



