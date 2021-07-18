#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
}TreeNode;

TreeNode* treeInsert(TreeNode* t, int data)
{
    TreeNode* newNode;
    newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode* current = t;
    TreeNode* parent = t;
    if (t == NULL) {
        t = newNode;
    }
    else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            }
            else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode* root)
{
    if (root)
    {
        printf("%d", root->key);
        if (root->left || root->right)
        {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(", ");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

int sum = 0;
int calcElemTree(TreeNode* tree)
{
    if (tree == NULL)
        return sum;
    else
    {
        sum++;
        calcElemTree(tree->left);
        calcElemTree(tree->right);
    }
}

void resetSum()
{
    sum = 0;
}

////////////////////////==TASK 4==/////////////////////////////////////////////////////////////////

boolean searchData(TreeNode* root, int data)
{
    if (root)
    {
        if (root->key == data)
        {
            printf("Data found: %d", data);
            return true;
        }
        else
        {
            searchData(root->left, data);
            searchData(root->right, data);
        }

    }
    else return -1;
}

////////////////////////==TASK 1==/////////////////////////////////////////////////////////////////

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(TreeNode* tree)
{
    if (tree == NULL)
        return 0;
    return 1 + max(height(tree->left), height(tree->right));
}

boolean isBalanced(TreeNode* root)

{
    int lh;
    int rh;

    if (root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;

}

////////////////////////==TASK 2==/////////////////////////////////////////////////////////////////

float r = 0;
int createRoot()
{
    TreeNode* tr = treeInsert(NULL, rand() % 10000 + 1);
    for (int j = 0; j < 10000; j++)
        treeInsert(tr, rand() % 50000 + 1);
    //printTree(tr); // Чтоб не печатать все деревья в консоль
    printf("\n");
    calcElemTree(tr);
    printf("Elements: %d \n", sum);
    resetSum();
    if (isBalanced(tr))
    {
        printf("Tree is balanced");
        r++;
    }
    else
        printf("Tree is not balanced");
    printf("\n");

    return 0;
}

int main()
{
    TreeNode* tree = treeInsert(NULL, 5);
    for (int i = 0; i < 10; i++)
        treeInsert(tree, rand() % 100 + 1);
    printTree(tree);
    printf("\n");
    calcElemTree(tree);
    printf("Elements: %d \n", sum);
    resetSum();
    printf("\n");

    ////////////////////////==TASK 4==/////////////////////////////////////////////////////////////////
    printf("           TASK 4:\n");
    int h = 70;
    searchData(tree, h);
    printf("\n");
    printf("\n");

    ////////////////////////==TASK 1==/////////////////////////////////////////////////////////////////

    printf("           TASK 1:\n");
    if (isBalanced(tree))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
    printf("\n");

    ////////////////////////==TASK 2==/////////////////////////////////////////////////////////////////

    printf("           TASK 2:\n");
    unsigned int arrayTree[50];
    for (size_t i = 0; i < 50; i++)
    {
        arrayTree[i] = (unsigned int)malloc(50 * sizeof(unsigned int));
    }

    for (size_t i = 0; i < 50; i++)
    {
        arrayTree[i] = createRoot();
    }
    printf("\n");
    ////////////////////////==TASK 3==/////////////////////////////////////////////////////////////////

    printf("           TASK 3:\n");
    float ye;
    if (r != 0)
        ye = r / 0, 5;
    else ye = 0;

    printf("Persent:  %f", ye);

    printf("\n");



    return 0;
}
