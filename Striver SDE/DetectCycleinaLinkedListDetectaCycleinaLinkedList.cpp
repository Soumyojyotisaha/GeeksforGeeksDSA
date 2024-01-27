#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow_p = head, *fast_p = head;
        while (fast_p != nullptr && fast_p->next != nullptr) {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
            if (slow_p == fast_p)
                return true; 
        } 
        return false;
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
    // Example usage with a cycle
    ListNode* headWithCycle = new ListNode(1);
    headWithCycle->next = new ListNode(2);
    headWithCycle->next->next = new ListNode(3);
    headWithCycle->next->next->next = new ListNode(4);
    headWithCycle->next->next->next->next = headWithCycle->next; // Creating a cycle

    Solution solution;

    std::cout << "Linked List with Cycle: ";
    // To print a linked list with a cycle, we can't use the printList function directly
    // as it will go into an infinite loop. We can print a few elements instead.
    ListNode* current = headWithCycle;
    for (int i = 0; i < 5; ++i) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "... (cycle)" << std::endl;

    // Checking if the linked list has a cycle
    bool hasCycle = solution.hasCycle(headWithCycle);
    std::cout << "Has Cycle: " << (hasCycle ? "true" : "false") << std::endl;

    // Cleaning up the memory
    delete headWithCycle;

    return 0;
}
