#include <bits/stdc++.h> 
using namespace std; 

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

bool isCircular(Node* head) {
    Node* temp;
    temp = head;
    do {
        if (temp == nullptr) {
            return false;
        }
        temp = temp->next; /* corrected the arrow operator */
    } while (temp != head);
    if (temp == head)
        return true;
    else
        return false;
}
