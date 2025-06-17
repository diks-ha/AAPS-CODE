#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
class Solution {
public:
    void mirror(Node* node) {
        if (node == NULL) return;
        mirror(node->left);
        mirror(node->right);
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    cout << "tree before mirroring:- ";
    inorder(root);
    cout << endl;
    Solution sol;
    sol.mirror(root);
    cout << "tree before mirroring:- ";
    inorder(root);
    cout << endl;
    cout << endl;
    return 0;
}
