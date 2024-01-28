#include <iostream>

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int x) : data(x), next(nullptr), bottom(nullptr) {}
};

Node* mergeTwoLists(Node* a, Node* b) {
    Node* temp = new Node(0);
    Node* res = temp;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        } else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a) temp->bottom = a;
    else temp->bottom = b;

    return res->bottom;
}

Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL)
        return root;

    // recur for list on right
    root->next = flatten(root->next);

    // now merge
    root = mergeTwoLists(root, root->next);

    // return the root
    // it will be in turn merged with its left
    return root;
}

// Utility function to print the flattened linked list
void printFlattenedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->bottom;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* root = new Node(5);
    root->next = new Node(10);
    root->next->next = new Node(19);
    root->next->next->next = new Node(28);

    root->next->bottom = new Node(7);
    root->next->bottom->bottom = new Node(8);
    root->next->bottom->bottom->bottom = new Node(30);

    root->next->next->bottom = new Node(20);

    root->next->next->next->bottom = new Node(22);
    root->next->next->next->bottom->bottom = new Node(50);

    // Flatten the matrix into a sorted linked list
    Node* flattenedList = flatten(root);

    // Print the flattened linked list
    std::cout << "Flattened Linked List: ";
    printFlattenedList(flattenedList);

    // Clean up: Delete the linked list
    while (root != nullptr) {
        Node* temp = root;
        root = root->next;
        delete temp;
    }

    return 0;
}
