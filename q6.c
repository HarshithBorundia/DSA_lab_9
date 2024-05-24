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
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorder(int *j,int ans[],TreeNode* root){
    if(root==NULL || root->value==-1){
        return;
    }
    inorder(j,ans,root->left);
    ans[(*j)++] = root->value;
    inorder(j,ans,root->right);
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int cnt = 0;
    TreeNode** nodes = (TreeNode**)malloc(n * sizeof(TreeNode*));
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(a[i]);
        if(a[i]!=-1){
            cnt++;
        }
    }
    k = cnt-k+1;
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
    int ans[cnt];
    int j = 0;
    inorder(&j,ans,nodes[0]);
    printf("%d",ans[k-1]);
    

    return 0;
}

