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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        if(list1->val <= list2->val) {
            head = tail = list1;
            list1 = list1->next;
        } else {
            head = tail = list2;
            list2 = list2->next;
        }

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }

        if(list1 == nullptr) {
            tail->next = list2;
        } else {
            tail->next = list1;
        }

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
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution solution;

    std::cout << "List 1: ";
    printList(list1);

    std::cout << "List 2: ";
    printList(list2);

    // Merging two sorted lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    // Cleaning up the memory
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
