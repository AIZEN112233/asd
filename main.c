#include <stdio.h>

char messages[1000][1000] = {
    "create new empty tree",
    "see if the tree is empty (1 for not empty and 0 for empty)",
    "get the height of tree",
    "get the left side of tree",
    "get the right side of tree",
    "create tree user 2 difrent nodes",
    "insert new value",
    "search for a value",
    "get the min value in the tree",
    "delete node from the tree",
    "get the addition of all values in the tree",
    "print the tree in the terminal",
    "exit the code",
};

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *create_empty_node()
{
    TreeNode *node = NULL;
    node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node != NULL)
    {
        node->data = 0;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}
int has_value(TreeNode *node)
{
    if (node == NULL)
    {
        return 0; // Empty tree has no value
    }
    return 1; // Non-empty tree has a value
}
int get_tree_height(TreeNode *node)
{
    if (node == NULL)
    {
        return 0; // Empty tree has height 0
    }

    // Recursively find the height of left and right subtrees
    int left_height = get_tree_height(node->left);
    int right_height = get_tree_height(node->right);

    // Take the maximum of left and right heights and add 1 for the current node
    return 1 + (left_height > right_height ? left_height : right_height);
}
TreeNode *gauche(TreeNode *racine) {}
TreeNode *droit(TreeNode *racine) {}
TreeNode *create_tree(int value, TreeNode *left, TreeNode *right)
{
    // Allocate memory for the new node
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL)
    {
        return NULL; // Memory allocation failed
    }

    // Initialize node data and children
    node->data = value;
    node->left = left;
    node->right = right;

    return node;
}
TreeNode *insert(TreeNode **root, int value)
{
    // Create a new node with the given value
    TreeNode *new_node = create_tree(value, NULL, NULL);
    if (*root == NULL)
    {
        // Empty tree, set the new node as the root
        *root = new_node;
        return new_node;
    }

    // Find the appropriate place to insert the new node
    TreeNode *current = *root;
    while (1)
    {
        if (value < current->data)
        {
            if (current->left == NULL)
            {
                // Insert the new node as the left child
                current->left = new_node;
                return new_node;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                // Insert the new node as the right child
                current->right = new_node;
                return new_node;
            }
            current = current->right;
        }
    }
}
int search(TreeNode *root, int value)
{
    if (root == NULL)
    {
        return 0; // Value not found in an empty tree
    }

    while (root != NULL)
    {
        if (value == root->data)
        {
            return 1; // Found the value
        }
        else if (value < root->data)
        {
            root = root->left; // Search in the left subtree
        }
        else
        {
            root = root->right; // Search in the right subtree
        }
    }

    return 0; // Value not found
}
int search_min(TreeNode *root)
{
    if (root == NULL)
    {
        return 0; // Empty tree has no minimum value
    }

    // Traverse to the leftmost node
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data; // Minimum value is found
}
void delete_node(TreeNode **root, int value)
{
    if (*root == NULL)
    {
        return; // Value not found in an empty tree
    }

    TreeNode *current = *root;
    TreeNode *parent = NULL;

    // Find the node to delete
    while (current != NULL && current->data != value)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    // If the node is not found, return
    if (current == NULL)
    {
        return;
    }

    // Case 1: Node has no children
    if (current->left == NULL && current->right == NULL)
    {
        if (parent == NULL)
        {
            // Deleting root node
            *root = NULL;
        }
        else if (parent->left == current)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        free(current);
        return;
    }

    // Case 2: Node has one child
    if (current->left != NULL && current->right == NULL)
    {
        if (parent == NULL)
        {
            *root = current->left;
        }
        else if (parent->left == current)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
        free(current);
        return;
    }

    if (current->left == NULL && current->right != NULL)
    {
        if (parent == NULL)
        {
            *root = current->right;
        }
        else if (parent->left == current)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
        free(current);
        return;
    }

    // Case 3: Node has two children
    TreeNode *successor = current->right;
    TreeNode *successor_parent = current;

    while (successor->left != NULL)
    {
        successor_parent = successor;
        successor = successor->left;
    }

    // Copy successor's data to the node to be deleted
    current->data = successor->data;

    // Delete the successor node
    if (successor_parent == current)
    {
        current->right = successor->right;
    }
    else
    {
        successor_parent->left = successor->right;
    }
    free(successor);
}
int somme(TreeNode *racine) {}
void afficher(TreeNode *racine) {}

int main()
{
    printf("if you need function for \n");
    for (int i = 0; i < 13; i++)
    {
        printf("%d - %s \n", i + 1, messages[i]);
    }

    return 0;
}