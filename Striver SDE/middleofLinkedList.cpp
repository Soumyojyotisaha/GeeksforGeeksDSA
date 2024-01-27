#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return nullptr; 

        int count = 0;
        ListNode* curr;
        for (curr = head; curr != nullptr; curr = curr->next)
            count++;

        curr = head;
        for (int i = 0; i < count / 2; i++)
            curr = curr->next;

        // Output the value of the middle node (assuming you want to print it)
        std::cout << "Value of the Middle Node: " << curr->val << std::endl;

        return curr;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    std::cout << "Original Linked List: ";
    printList(head);

    // Finding the middle node
    ListNode* middleNode = solution.middleNode(head);

    // Cleaning up the memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
