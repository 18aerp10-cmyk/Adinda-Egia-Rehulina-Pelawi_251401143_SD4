#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node* head = NULL;

void insertUrut(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL || n < head->value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->value < n) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void hapusDibawah(int batas) {
    while (head != NULL && head->value < batas) {
        Node *hapus = head;
        head = head->next;
        delete hapus;
    }

}

bool cari(int n) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->value == n) return true;
        temp = temp->next;
    }
    return false;
}

