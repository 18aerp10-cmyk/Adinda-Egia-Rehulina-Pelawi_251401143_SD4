#include <iostream>
using namespace std;

#define MAX 100

int main() {
    char stack[MAX];
    int top = -1;
    string kata;

    cout << "Masukkan kata : ";
    cin >> kata;

    int panjang = 0;
    while (kata[panjang] != '\0') {
        panjang++;
    }

    for (int i = 0; i < panjang; i++) {
        top++;
        stack[top] = kata[i];
    }

    bool palindrome = true;
    for (int i = 0; i < panjang; i++) {
        char c = stack[top]; 
        top--;

        if (c != kata[i]) {  
            palindrome = false;
            break;
        }
    }

    if (palindrome)
        cout << kata << " adalah PALINDROME" << endl;
    else
        cout << kata << " BUKAN palindrome" << endl;

    return 0;
}