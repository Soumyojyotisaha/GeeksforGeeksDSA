#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
        // Initialize count to 0.
        int count = 0;

        // Traverse the linked list and increment count for each node.
        while (head != NULL) {
            count++;
            head = head->next;
        }

        // Return the count, which is the length of the linked list.
        return count;
    }
};
