#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

void tambah(Node*& root, int data) {
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->kiri = NULL;
        root->kanan = NULL;
        return;
    }

    if (data < root->data) {
        tambah(root->kiri, data);
    }

    if (data > root->data) {
        tambah(root->kanan, data);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

int hitungLeaf(Node* root) {
    if (root == NULL) return 0;
    if (root->kiri == NULL && root->kanan == NULL) return 1;
    return hitungLeaf(root->kiri) + hitungLeaf(root->kanan);
}

int hitungSatuAnak(Node* root) {
    if (root == NULL) return 0;

    int hasil = 0;
    if ((root->kiri == NULL && root->kanan != NULL) ||
        (root->kiri != NULL && root->kanan == NULL)) {
        hasil = 1;
    }
    return hasil + hitungSatuAnak(root->kiri) + hitungSatuAnak(root->kanan);
}

int hitungDuaAnak(Node* root) {
    if (root == NULL) return 0;

    int hasil = 0;
    if (root->kiri != NULL && root->kanan != NULL) {
        hasil = 1;
    }
    return hasil + hitungDuaAnak(root->kiri) + hitungDuaAnak(root->kanan);
}

int main() {
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (0=stop) : ";
    cin >> angka;

    while (angka != 0) {
        tambah(root, angka);
        cin >> angka;
    }

    cout << "In-order      : ";
    inOrder(root);
    cout << endl;

    cout << "Jumlah leaf   : " << hitungLeaf(root) << endl;
    cout << "Jumlah 1 anak : " << hitungSatuAnak(root) << endl;
    cout << "Jumlah 2 anak : " << hitungDuaAnak(root) << endl;

    return 0;
}