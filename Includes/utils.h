#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    int value;
    Node * next;
    void Print(void){
        Traverse(PrintHelper);
        cout << endl;
    }

    void Traverse(void (*Visit)(Node *n)){
        Node * p = this;
        while (p != NULL) {
            Visit(p);
            p = p->next;
        }
        cout << endl;
    }
private:
    static void PrintHelper(Node *n){
        cout << n->value << "\t";
    }

};

#define HEAP_LEFT_CHILD(x) (((x) << 1) + 1)
#define HEAP_RIGHT_CHILD(x) (((x) + 1) << 1)

class TreeNode{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        left = NULL;
        right = NULL;
    }
    TreeNode(int num) { value = num; }
    ~TreeNode() {}
    TreeNode(vector<int> &nums);

    void PreOderTraverse(void (*Visit)(TreeNode *node)){ PreOderTraverseRecursive(Visit); }
    void InOrderTraverse(void (*Visit)(TreeNode *node)){ InOderTraverseRecursive(Visit); }
    void PostOrderTraverse(void (*Visit)(TreeNode *node)){ PostOderTraverseRecursive(Visit); }
    int Depth(void) {
        return DepthHelper(this);
    }

    void Copy(TreeNode * target) {
        value = target->value;
        left = target->left;
        right = target->right;
    }

    void RunTraverse(void) {
        int n[] = { 1, 2, 3, 4, 5, 6, 7 };
        vector<int> nums(n, n + 7);
        TreeNode t(nums);
        t.PreOderTraverseNonRecursive(PrintHelper);
        cout << endl;
        t.PreOderTraverseRecursive(PrintHelper);
    }

    void RunMirror(void) {
        int n[] = { 1, 2, 3, 4, 5, 6, 7 };
        vector<int> nums(n, n + 7);
        TreeNode t(nums);
        t.BFS(PrintHelper);
        cout << endl;
        t.Mirror();
        cout << t.Depth() << endl;
        t.BFS(PrintHelper);
    }

    void BFS(void (*Visit)(TreeNode *node)) {
        TreeNode *p = this;
        queue<TreeNode *> q;
        q.push(p);
        while (!q.empty()) {
            p = q.front();
            q.pop();
            Visit(p);
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
    }

    static void PrintHelper(TreeNode *p){
        cout << p->value << " ";
    }

    void Mirror(void);

private:
    void MirrorHelper(TreeNode * node);
    int DepthHelper(TreeNode *node);
    void PreOderTraverseRecursive(void (*Visit)(TreeNode *node)){
        PreOderTravserHelper(this, Visit);
    }
    void PreOderTravserHelper(TreeNode *node, void(*Visit)(TreeNode *node));
    void PreOderTraverseNonRecursive(void(*Visit)(TreeNode *node));
    
    void InOderTraverseRecursive(void(*Visit)(TreeNode *node)){
        InOrderTraverseHelper(this, Visit);
    }
    void InOrderTraverseHelper(TreeNode *node, void(*Visit)(TreeNode *node));
    void InOderTraverseNonRecursive(void (*Visit)(TreeNode *node));

    void PostOderTraverseRecursive(void(*Visit)(TreeNode *node)) {
        PostOderTraverseHelper(this, Visit);
    }
    void PostOderTraverseNonRecursive(void (*Visit)(TreeNode *node));
    void PostOderTraverseHelper(TreeNode *node, void(*Visit)(TreeNode *node));

    void BuildTree(TreeNode **root, vector<int> &nums) {
        if (nums.size() == 0) return;
        BuildTreeHelper(root, nums, 0);
    }
    void BuildTreeHelper(TreeNode **node, vector<int> &nums, unsigned int index) {
        if (index >= nums.size()) return;
        if (*node == NULL) *node = new TreeNode(nums[index]);
        unsigned int left = HEAP_LEFT_CHILD(index);
        if (left < nums.size()) BuildTreeHelper(&((*node)->left), nums, left);
        unsigned int right = HEAP_RIGHT_CHILD(index);
        if (right < nums.size()) BuildTreeHelper(&((*node)->right), nums, right);
    }
};

#endif