#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};
// insertion in to bst
TreeNode* insertintoBST(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    if (val < root->val)
        root->left = insertintoBST(root->left, val);
    else
        root->right = insertintoBST(root->right, val);

    return root;
}
//bst
TreeNode* createbst(int arr[], int n) {
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertintoBST(root, arr[i]);
    }
    return root;
}
//bfs
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " unsorted elements are :";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    TreeNode* root = createbst(arr, n);
    cout << "Level order traversal of the BST is : ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
