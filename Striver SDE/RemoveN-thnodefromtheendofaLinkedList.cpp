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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0)
            return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            if (first == nullptr)
                return nullptr;
            first = first->next;
        }

        // Move both pointers until the first pointer reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        ListNode* toRemove = second->next;
        second->next = toRemove->next;
        delete toRemove;

        // Update the head if necessary
        head = dummy->next;
        delete dummy;

        return head;
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

    // Removing the 2nd node from the end
    int n = 2;
    ListNode* modifiedList = solution.removeNthFromEnd(head, n);

    std::cout << "Linked List after removing " << n << " node(s) from the end: ";
    printList(modifiedList);

    // Cleaning up the memory
    while (modifiedList) {
        ListNode* temp = modifiedList;
        modifiedList = modifiedList->next;
        delete temp;
    }

    return 0;
}
