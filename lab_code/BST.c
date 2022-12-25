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
    int option, val;
    printf("Enter your choice");
    while (1)
    {
        printf("\n 1. Insert Element");
        printf("\n 2. Delete an element");
        printf("\n 3. Display the tree");
        printf("\n 4. Exit");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the value of the new node : ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            printf("\n Enter the element to be deleted : ");
            scanf("%d", &val);
            root = deletenode(root, val);
            break;
        case 3:
            printf("\n The elements of the tree are : \n");
            postorder(root);
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}
