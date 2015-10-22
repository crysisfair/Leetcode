#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

using namespace std;

class ReverseLinklist {
public:
    ReverseLinklist() {}
    ~ReverseLinklist() {}

    void Run(void) {
        int test1[] = { 1, 2, 3, 4, 5};
        Node *p_test1 = generateLinklist(test1, 5);
        p_test1->Print();
        p_test1 = ReverseII(p_test1);
        p_test1->Print();
        freeList(p_test1);
    }

    Node *ReverseI(Node *head) {
        if (head == 0) return NULL;
        Node * p = head, *prev = NULL, *t = NULL;
        while (p->next != NULL){
            t = p->next;
            p->next = prev;
            prev = p;
            p = t;
        }
        p->next = prev;
        return p;
    }

    Node *ReverseII(Node *head) {
        if (head == NULL) return NULL;
        Node * p = (Node *)malloc(sizeof(Node));;
        memset(p, 0, sizeof(Node));
        p->next = head;
        Node * current = p->next->next;
        p->next->next = NULL;
        Node * t = NULL;

        while (current != NULL) {
            t = current->next;
            current->next = p->next;
            p->next = current;
            current = t;
        }
        return p->next;
    }

private:
    Node *generateLinklist(int nums[], int length) {
        Node *head = 0, *p = 0, *last = 0;
        for (int i = 0; i < length; i++){
            p = (Node *)malloc(sizeof(Node));
            memset(p, 0, sizeof(Node));
            if (i == 0) head = p;
            else last->next = p;
            p->value = nums[i];
            last = p;
        }
        return head;
    }

    void freeList(Node *head) {
        Node * p = 0;
        while (head != 0) {
            p = head->next;
            free(head);
            head = p;
        }
        head = NULL;
    }
};