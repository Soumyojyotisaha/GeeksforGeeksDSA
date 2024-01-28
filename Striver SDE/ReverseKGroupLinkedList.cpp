#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* nextcurr = nullptr;
        ListNode* prev = nullptr;
        int count = 0;

        // Count the remaining nodes
        ListNode* temp = head;
        int remainingNodes = 0;
        while (temp != nullptr) {
            temp = temp->next;
            remainingNodes++;
        }

        if (remainingNodes < k) {
            // If remaining nodes are less than k, no need to reverse
            return head;
        }

        // Reverse the first k nodes
        while (curr != nullptr && count < k) {
            nextcurr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextcurr;
            count++;
        }

        if (nextcurr != nullptr) {
            // Recursively reverse the remaining nodes
            head->next = reverseKGroup(nextcurr, k);
        }

        return prev;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Solution solution;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    // Print the original linked list
    std::cout << "Original Linked List: ";
    printList(head);

    // Reverse in groups of size k (let's say k = 3)
    int k = 3;
    head = solution.reverseKGroup(head, k);

    // Print the reversed linked list
    std::cout << "Reversed Linked List in groups of " << k << ": ";
    printList(head);

    // Clean up: Delete the linked list
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
