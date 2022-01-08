#include <bits/stdc++.h>
#include<string>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node (int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *head) {
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
}

Node *insertAtBegin(Node *head, int x) {
    Node *temp = new Node(x);
    temp-> next = head;
    return temp;
}

Node *insertAtEnd(Node *head, int x) {
    Node *temp = new Node(x);
    if (head == NULL) {
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

Node *deleteHead(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *curr = head->next;
    delete(head);
    return curr;
}

Node *deleteLastNode(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        delete(head);
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next != NULL) {
        curr = curr->next;
    }
    delete(curr->next);
    curr->next = NULL;
    return head;
}

int searchNode(Node *head, int x) {
    if (head == NULL) return -1;
    Node *curr = head;
    int pos = 1;
    while (curr->next != NULL) {
        if (curr->data == x) {
            return pos;
        }
        pos++;
        curr = curr->next;
    }
    return -1;
}

Node *InsertAtPosition(Node *head, int data, int pos) {
    Node *temp = new Node(data);
    if (pos == 1) {
        temp->next = head;
        return temp;
    }

    Node *curr = head;
    for (int i = 1; i <= pos-2 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int main() 
{ 
    Node *head = NULL;

    // for (int i = 0; i < 10; i++) {
    //     head = insertAtEnd(head, i);
    // }
    // head = insertAtBegin(head,30);
    // head = insertAtBegin(head, 20);
    // head = insertAtBegin(head, 10);

    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    head = insertAtEnd(head, 60);
    head = insertAtEnd(head, 70);
    head = insertAtEnd(head, 80);

    head = InsertAtPosition(head, 45, 6);
    cout << searchNode(head, 40) << endl;
    // head = deleteHead(head);
    // head = deleteLastNode(head);
    printList(head);
}
