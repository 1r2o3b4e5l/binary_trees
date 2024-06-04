#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

void binary_tree_print(const binary_tree_t *);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

    if (new_node == NULL)
        return NULL;

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

binary_tree_t *create_binary_tree()
{
    binary_tree_t *root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    return root;
}

int main(void)
{
    binary_tree_t *root = create_binary_tree();

    if (root == NULL)
    {
        fprintf(stderr, "Failed to create binary tree\n");
        return EXIT_FAILURE;
    }

    binary_tree_print(root);

    return EXIT_SUCCESS;
}

void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    printf("%d\n", tree->n);
    binary_tree_print(tree->left);
    binary_tree_print(tree->right);
}

