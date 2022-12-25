#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *insert(struct node *node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return createnode(data);

    /* Otherwise, recur down the tree */
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    /* return the (unchanged) node pointer */
    return node;
}

struct node *postorderpredecessor(struct node *root)
{
    root = root->right;
    while (root->right != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *deletenode(struct node *root, int k)
{
    // Base case
    if (root == NULL)
        return root;

    // Recursive calls for ancestors of
    // node to be deleted
    if (root->data > k)
    {
        root->left = deletenode(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = deletenode(root->right, k);
        return root;
    }

    // We reach here when root is the node
    // to be deleted.

    // If one of the children is empty
    if (root->left == NULL)
    {
        struct node *temp = root->right;
        free(root);
        // delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        struct node *temp = root->left;
        free(root);
        // delete root;
        return temp;
    }

    // If both children exist
    else
    {

        struct node *succParent = root;

        // Find successor
        struct node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        // Copy Successor Data to root
        root->data = succ->data;

        // Delete Successor and return root
        free(succ);
        // delete succ;
        return root;
    }
}
int main()
{
    struct node *root = NULL;

    int n;
    printf("Enter size : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int c;

        printf("Enter element : ");
        scanf("%d", &c);
        root = insert(root, c);
    }

    printf("postorder before delation : ");
    postorder(root);
    printf("\n");
    int z;
    printf("Enter element you want to delete : ");
    scanf("%d", &z);
    printf("postorder after delation : ");
    deletenode(root, z);
    postorder(root);

    return 0;
}

// created by Ansh
// 21BIT123

// example :-
/* Let us create following BST
             50
           /    \
          30     70
         /  \   /  \
       20   40 60   80 */

//    you can check for delete 50 as a root node this program give you correct post order