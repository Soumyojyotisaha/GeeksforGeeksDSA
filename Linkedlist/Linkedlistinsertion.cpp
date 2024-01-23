#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class Solution{
  public:
    Node *insertAtBegining(Node *head, int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        return newNode;
    }
    Node *insertAtEnd(Node *head, int x)  {
        Node* newNode = new Node(x);
        if (!head) {
            return newNode;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
};