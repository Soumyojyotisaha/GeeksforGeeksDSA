#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {
            t1 = (t1 == nullptr) ? headB : t1->next;
            t2 = (t2 == nullptr) ? headA : t2->next;
        }

        return t1;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Create linked list 1: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // Create linked list 2: 6 -> 7 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(6);
    headB->next = new ListNode(7);
    headB->next->next = new ListNode(8);
    headB->next->next->next = headA->next->next->next; // Set intersection point

    // Call the function to find the intersection point
    ListNode* intersectionNode = solution.getIntersectionNode(headA, headB);

    // Display the intersection point value
    if (intersectionNode != nullptr) {
        std::cout << "Intersection point value: " << intersectionNode->val << std::endl;
    } else {
        std::cout << "No intersection point found." << std::endl;
    }

    // Clean up: Delete the linked lists
    delete headA;
    delete headB;

    return 0;
}
