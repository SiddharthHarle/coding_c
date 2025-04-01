#include <iostream>
using namespace std;

// Node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find LCA in a BST (Recursive)
TreeNode* findLCA(TreeNode* root, int p, int q) {
    if (!root) return nullptr;

    // If both p and q are smaller, move left
    if (p < root->val && q < root->val)
        return findLCA(root->left, p, q);

    // If both p and q are larger, move right
    if (p > root->val && q > root->val)
        return findLCA(root->right, p, q);

    // If one node is on the left and the other on the right, this is LCA
    return root;
}

// Function to insert a node in BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 6);
    insert(root, 2);
    insert(root, 8);
    insert(root, 0);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);
    insert(root, 3);
    insert(root, 5);

    int p = 2, q = 8;
    TreeNode* lca = findLCA(root, p, q);
    cout << "LCA of " << p << " and " << q << " is: " << (lca ? lca->val : -1) << endl;

    return 0;
}
