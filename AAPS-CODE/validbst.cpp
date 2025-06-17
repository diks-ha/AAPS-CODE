#include <iostream>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a) {
        val = a;
        left = right = NULL;
    }
};
bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;
    if (root->val <= minVal || root->val >= maxVal)
        return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}
bool isValidBST(TreeNode* root) {
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}
TreeNode* binarytree() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(20);
    return root;
}
int main() {
    TreeNode* root = binarytree();
    if (isValidBST(root))
        cout << "Yes, It is a valid BST." << endl;
    else
        cout << "No , It's not a valid BST." << endl;
    return 0;
}
