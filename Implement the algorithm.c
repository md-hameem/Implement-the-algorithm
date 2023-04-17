#include <stdio.h>
#include <stdlib.h>

// Define struct for tree nodes
struct TreeNode {
    char value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node with the given value
struct TreeNode* newNode(char value);

// Function to evaluate an expression tree and return the result
int evalExpr(struct TreeNode* node);

// Main function to construct an expression tree and evaluate it
int main() {
    // Construct an expression tree for the equation (2+3)*4
    struct TreeNode* node1 = newNode('*');
    struct TreeNode* node2 = newNode('+');
    struct TreeNode* node3 = newNode('2');
    struct TreeNode* node4 = newNode('3');
    struct TreeNode* node5 = newNode('4');

    node1->left = node2;
    node1->right = node5;
    node2->left = node3;
    node2->right = node4;

    // Evaluate the expression and print the result
    int result = evalExpr(node1);
    printf("Result for the equation ((2+3)*4): %d\n", result);

    return 0;
}

struct TreeNode* newNode(char value) {
    // Allocate memory for a new tree node and initialize its fields
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int evalExpr(struct TreeNode* node) {
    if (node->left == NULL && node->right == NULL) {
        // If the node is a leaf node, return its integer value
        return node->value - '0';
    }

    // Evaluate the left and right subtrees recursively
    int leftValue = evalExpr(node->left);
    int rightValue = evalExpr(node->right);

    // Apply the operation specified by the node's value to the sub-tree values and return the result
    if (node->value == '+') {
        return leftValue + rightValue;
    } else if (node->value == '-') {
        return leftValue - rightValue;
    } else if (node->value == '*') {
        return leftValue * rightValue;
    } else if (node->value == '/') {
        return leftValue / rightValue;
    } else {
        // If the node's value is not a valid operator, print an error message and exit the program with failure status
        fprintf(stderr, "Error: unknown operator %c\n", node->value);
        exit(1);
    }
}
