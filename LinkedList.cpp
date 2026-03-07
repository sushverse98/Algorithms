#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

Node* deleteNode(Node* head, int key) {
    if (head == NULL) return head;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data != key)
        curr = curr->next;

    if (curr->next != NULL) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Linked List: ";
    display(head);

    int key = 20;
    cout << "Search " << key << ": ";
    cout << (search(head, key) ? "Found\n" : "Not Found\n");

    head = deleteNode(head, 20);

    cout << "After Deletion: ";
    display(head);

    return 0;
}
