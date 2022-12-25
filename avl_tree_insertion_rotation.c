#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createnode(int key)
{
    struct node *no = (struct node *)malloc(sizeof(struct node));
    no->key = key;
    no->left = NULL;
    no->right = NULL;
    no->height = 1;
    return no;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getbalancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct node *rightrotation(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    y->height = max(getheight(y->right), getheight(y->left)) + 1;

    return x;
}

struct node *leftrotation(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    y->height = max(getheight(y->right), getheight(y->left)) + 1;

    return y;
}

struct node *insert(struct node *no, int key)
{
    if (no == NULL)
    {
        return createnode(key);
    }
    if (key < no->key)
    {
        no->left = insert(no->left, key);
    }
    else if (key > no->key)
    {
        no->right = insert(no->right, key);
    }

    no->height = 1 + max(getheight(no->left), getheight(no->right));
    int bf = getbalancefactor(no);

    // left left case
    if (bf > 1 && key < no->left->key)
    {
        return rightrotation(no);
    }

    // right right case
    if (bf < -1 && key > no->right->key)
    {
        return leftrotation(no);
    }

    // left right case
    if (bf > 1 && key > no->left->key)
    {
        no->left = leftrotation(no->left);
        return rightrotation(no);
    }

    // right left case
    if (bf < -1 && key < no->right->key)
    {
        no->right = rightrotation(no->right);
        return leftrotation(no);
    }

    return no;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preorder(root);
    return 0;
}