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
    struct TreeNode* parent;
} TreeNode;
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent= NULL;
    return newNode;
}
TreeNode* lca(TreeNode* root,int a,int b){
    if(root==NULL){
        return NULL;
    }
    if(root->value ==a || root->value==b){
        return root;
    }
    TreeNode * left = lca(root->left,a,b);
    TreeNode * right = lca(root->right,a,b);
    if(left!=NULL && right!=NULL) return root;
    return left!=NULL? left : right;

}
int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    TreeNode** nodes = (TreeNode**)malloc(n * sizeof(TreeNode*));
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(arr[i]);
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
        if((i-1)/2>=0){
            nodes[i]->parent = nodes[(i-1)/2];
        }
    }
    TreeNode* ancestor = lca(nodes[0],a,b);
    if(ancestor->value==a || ancestor->value==b){
        ancestor = ancestor->parent;
    }
    printf("%d ",ancestor->value);
    return 0;
}

