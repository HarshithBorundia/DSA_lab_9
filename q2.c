/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
bool isSubtree(TreeNode * root1,TreeNode * root2){
    if ((root1==NULL || root1->value==-1) && (root2==NULL || root2->value==-1))
        return true;
    if (root1 == NULL || root2 == NULL || root1->value==-1 || root2->value==-1)
        return false;
    return (root1->value == root2->value) &&
           isSubtree(root1->left, root2->left) &&
           isSubtree(root1->right, root2->right);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n];
    int b[m];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(int i=0;i<m;i++){
        scanf("%d",b+i);
    }
    TreeNode * root[n];
    int j  = 0;
    TreeNode** nodes1 = (TreeNode**)malloc(n * sizeof(TreeNode*));
    for (int i = 0; i < n; i++) {
        nodes1[i] = createNode(a[i]);
        if(a[i]==b[0]){
            root[j++] = nodes1[i];
        }
    }
    for (int i = 0; i < n; i++) {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;
        if (leftChildIndex < n) {
            nodes1[i]->left = nodes1[leftChildIndex];
        }
        if (rightChildIndex < n) {
            nodes1[i]->right = nodes1[rightChildIndex];
        }
    }
    TreeNode** nodes2 = (TreeNode**)malloc(m * sizeof(TreeNode*));
    for (int i = 0; i < m; i++) {
        nodes2[i] = createNode(b[i]);
    }
    for (int i = 0; i < m; i++) {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;
        if (leftChildIndex < m) {
            nodes2[i]->left = nodes2[leftChildIndex];
        }
        if (rightChildIndex < m) {
            nodes2[i]->right = nodes2[rightChildIndex];
        }
    }
    bool val = false;
    for(int i=0;i<j;i++){
        if(isSubtree(root[i],nodes2[0])){
            printf("WIN");
            val = true;
            break;
        }
    }
    if(!val){
         printf("LOSS");
    }
    return 0;
}

