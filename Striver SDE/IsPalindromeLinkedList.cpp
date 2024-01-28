#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* rev = reverseList(slow->next);
        ListNode* curr = head;

        // Compare the first half with the reversed second half
        while (rev != nullptr) {
            if (rev->val != curr->val)
                return false;
            rev = rev->next;
            curr = curr->next;
        }

        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
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

    // Create a palindrome linked list: 1 -> 2 -> 3 -> 3 -> 2 -> 1
    ListNode* headPalindrome = new ListNode(1);
    headPalindrome->next = new ListNode(2);
    headPalindrome->next->next = new ListNode(3);
    headPalindrome->next->next->next = new ListNode(3);
    headPalindrome->next->next->next->next = new ListNode(2);
    headPalindrome->next->next->next->next->next = new ListNode(1);

    // Create a non-palindrome linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* headNonPalindrome = new ListNode(1);
    headNonPalindrome->next = new ListNode(2);
    headNonPalindrome->next->next = new ListNode(3);
    headNonPalindrome->next->next->next = new ListNode(4);
    headNonPalindrome->next->next->next->next = new ListNode(5);

    // Test isPalindrome function
    std::cout << "Is the first linked list a palindrome? " << (solution.isPalindrome(headPalindrome) ? "Yes" : "No") << std::endl;
    std::cout << "Is the second linked list a palindrome? " << (solution.isPalindrome(headNonPalindrome) ? "Yes" : "No") << std::endl;

    // Clean up: Delete the linked lists
    while (headPalindrome != nullptr) {
        ListNode* temp = headPalindrome;
        headPalindrome = headPalindrome->next;
        delete temp;
    }

    while (headNonPalindrome != nullptr) {
        ListNode* temp = headNonPalindrome;
        headNonPalindrome = headNonPalindrome->next;
        delete temp;
    }

    return 0;
}
