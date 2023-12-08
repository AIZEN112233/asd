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
TreeNode *creer_arbre(int x, TreeNode *g, TreeNode *d) {}
TreeNode *inserer(TreeNode **racine, int x) {}
int rechercher(TreeNode *racine, int x) {}
int rechercher_min(TreeNode *racine) {}
void supprimer(TreeNode **racine, int x) {}
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