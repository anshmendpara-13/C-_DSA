#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
// struct node *inorder(struct node *root)
// {
//     root = root->left;
//     while (root->left != NULL)
//     {
//         root = root->right;
//     }
//     return root;
//     if (root != NULL)
//     {
//         inorder(root->left);
//         printf("%d \n", root->key);
//         inorder(root->right);
//     }
// }

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        // printf("\n");
        inorder(root->right);
    }
}

/* A utility function to insert
   a new node with given key in
 * BST */
struct node *insert(struct node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
    {
        return newNode(key);
    }

    /* Otherwise, recur down the tree */
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    /* return the (unchanged) node pointer */
    return node;
}

struct node *deletenode(struct node *root, int k)
{
    // Base case
    if (root == NULL)
        return root;

    // Recursive calls for ancestors of
    // node to be deleted
    if (root->key > k)
    {
        root->left = deletenode(root->left, k);
        return root;
    }
    else if (root->key < k)
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

        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        // Copy Successor Data to root
        root->key = succ->key;

        // Delete Successor and return root
        free(succ);
        // delete succ;
        return root;
    }
}

int main()
{
    /* Let us create following BST
            5
    //     / \
    //    3   6
    //   / \
    //  1   4
                 */
    struct node *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 1);
    insert(root, 4);
    insert(root, 8);

    printf(" b ");
    inorder(root);

    deletenode(root, 5);

    printf(" a ");
    inorder(root);
    return 0;
}