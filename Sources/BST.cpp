#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

using namespace std;

class BST : TreeNode{
public:
    BST() {}
    ~BST() {}

    void Run() {
        int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
        vector<int> values(nums, nums + 8);
    }

    void Insert(int value) {
        TreeNode *node = this;
        TreeNode *target = SearchInsertNode(node, value);
        if (target == NULL) return;

        TreeNode t(value);
        if (value > node->value) {
            node->right = &t;
        }
        else {
            node->left = &t;
        }
    }

private:
    TreeNode *SearchInsertNode(TreeNode *node, int value) {
        if (node == NULL) return NULL;

        TreeNode *s = NULL;
        while (node) {
            s = node;

            if (s->value == value) return NULL;

            s = (node->value > value) ? node->right : node->left;
        }
        
        return s;
    }

};