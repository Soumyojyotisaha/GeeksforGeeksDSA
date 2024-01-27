#include <iostream>
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;

        while (t1 != nullptr || t2 != nullptr) {
            int sum = carry;
            if (t1) {
                sum += t1->val;
                t1 = t1->next;
            }
            if (t2) {
                sum += t2->val;
                t2 = t2->next;
            }

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newNode;
            curr = curr->next;
        }

        if (carry) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        return dummyHead->next;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create two example linked lists
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // Create an instance of the Solution class
    Solution solution;

    // Add the two numbers represented by the linked lists
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the input linked lists and the result
    std::cout << "Input List 1: ";
    printList(l1);

    std::cout << "Input List 2: ";
    printList(l2);

    std::cout << "Result: ";
    printList(result);

    return 0;
}