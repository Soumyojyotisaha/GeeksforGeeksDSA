import java.util.*;

class sortbitonic {
    static class Node {
        int data;
        Node next;
        Node prev;
    }

    static Node sort(Node head) {
        if (head == null || head.next == null)
            return head;
        Node front = head;
        Node last = head;
        Node res = new Node();
        Node resEnd = res;
        Node next;
        while (last.next != null)
            last = last.next;
        while (front != last) {
            if (last.data <= front.data) {
                resEnd.next = last;
                next = last.prev;
                last.prev.next = null;
                last.prev = resEnd;
                last = next;
                resEnd = resEnd.next;
            } else {
                resEnd.next = front;
                next = front.next;
                front.next = null;
                front.prev = resEnd;
                front = next;
                resEnd = resEnd.next;
            }
        }
        resEnd.next = front;
        front.prev = resEnd;
        return res.next;
    }

    static Node push(Node head_ref, int new_data) {
        Node new_node = new Node();
        new_node.data = new_data;
        new_node.prev = null;
        new_node.next = head_ref;
        if (head_ref != null)
            head_ref.prev = new_node;
        head_ref = new_node;
        return head_ref;
    }

    static void printList(Node head) {
        if (head == null)
            System.out.print("Doubly Linked list is empty");
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node head = null;
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            head = push(head, m);
        }
        head = sort(head);
        System.out.println("After sorting:");
        printList(head);
    }
}
