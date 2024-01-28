#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;

        // Detect the cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // If there's no cycle, return nullptr
        if (!hasCycle) {
            return nullptr;
        }

        // Find the starting point of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

// Utility function to create a linked list with a cycle for testing
ListNode* createLinkedListWithCycle() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    return head;
}

int main() {
    // Example usage
    Solution solution;

    // Create a linked list with a cycle
    ListNode* headWithCycle = createLinkedListWithCycle();

    // Call the function to detect the cycle and find the starting point
    ListNode* startingPoint = solution.detectCycle(headWithCycle);

    // Display the starting point value
    if (startingPoint != nullptr) {
        std::cout << "Starting point of the cycle: " << startingPoint->val << std::endl;
    } else {
        std::cout << "No cycle found." << std::endl;
    }

    // Clean up: Delete the linked list
    while (headWithCycle != nullptr) {
        ListNode* temp = headWithCycle;
        headWithCycle = headWithCycle->next;
        delete temp;
    }

    return 0;
}
