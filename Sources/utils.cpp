#include "utils.h"

TreeNode::TreeNode(vector<int> &nums){
    TreeNode *root = NULL;
    BuildTree(&root, nums);
    Copy(root);
}

void TreeNode::PreOderTravserHelper(TreeNode *node, void(*Visit)(TreeNode *node)){
    if (node == NULL) return;
    Visit(node);
    PreOderTravserHelper(node->left, Visit);
    PreOderTravserHelper(node->right, Visit);
}

void TreeNode::PreOderTraverseNonRecursive(void(*Visit)(TreeNode *node)){
    stack<TreeNode*> s;
    TreeNode *p = this;
    while (p != NULL || !s.empty()){
        if (p != NULL) {
            Visit(p);
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void TreeNode::InOrderTraverseHelper(TreeNode *node, void(*Visit)(TreeNode *node)){
    if (node == NULL) return;
    InOrderTraverseHelper(node->left, Visit);
    Visit(node);
    InOrderTraverseHelper(node->right, Visit);
}

void TreeNode::InOderTraverseNonRecursive(void (*Visit)(TreeNode *node)){
    stack<TreeNode *> s;
    TreeNode *p = this;
    while (p != NULL || !s.empty()) {
        if (p != NULL) {
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top();
            s.pop();
            Visit(p);
            p = p->right;
        }
    }
}

void TreeNode::PostOderTraverseHelper(TreeNode *node, void(*Visit)(TreeNode *node)){
    if (node == NULL) return;
    PostOderTraverseHelper(node->left, Visit);
    PostOderTraverseHelper(node->right, Visit);
    Visit(node);
}

void TreeNode::PostOderTraverseNonRecursive(void (*Visit)(TreeNode *node)){
//    TreeNode *p = this;
//    stack<TreeNode *> s;
}

void TreeNode::Mirror() {
    MirrorHelper(this);
}

void TreeNode::MirrorHelper(TreeNode *node) {
    if (node == NULL) return;
    TreeNode *temp = node->left;
    node->left = node->right;
    node->right = temp;
    MirrorHelper(node->left);
    MirrorHelper(node->right);
}
