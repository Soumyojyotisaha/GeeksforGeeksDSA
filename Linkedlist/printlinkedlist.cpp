#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Solution
{
public:
    void display(Node* head)
    {
        // your code goes here
        while (head)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
};
