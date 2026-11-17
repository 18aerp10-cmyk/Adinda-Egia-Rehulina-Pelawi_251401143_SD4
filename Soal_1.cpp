#include <iostream>
using namespace std;

#define produk 4
#define hari 5

int main() {
    int jual[produk][hari];
    int totalProduk[produk] = {0};
    int totalHari[hari] = {0};

    for (int i = 0; i < produk; i++) {
        for (int j = 0; j < hari; j++) {
            cout << "Produk " << i + 1 << " hari ke-" << j + 1 << " : ";
            cin >> jual[i][j];

            totalProduk[i] += jual[i][j]; 
            totalHari[j] += jual[i][j];   
        }
    }

    cout << "\nTotal Penjualan per Produk" << endl;
    for (int i = 0; i < produk; i++) {
        cout << "Produk " << i + 1 << " : " << totalProduk[i] << endl;
    }

    cout << "\nTotal Penjualan per Hari" << endl;
    for (int j = 0; j < hari; j++) {
        cout << "Hari ke-" << j + 1 << " : " << totalHari[j] << endl;
    }

    int maxProduk = 0;
    for (int i = 1; i < produk; i++) {
        if (totalProduk[i] > totalProduk[maxProduk]) {
            maxProduk = i;
        }
    }

    int minHari = 0;
    for (int j = 1; j < hari; j++) {
        if (totalHari[j] < totalHari[minHari]) {
            minHari = j;
        }
    }

    cout << "\nProduk dengan penjualan tertinggi : Produk " << maxProduk + 1
         << " (" << totalProduk[maxProduk] << ")" << endl;
    cout << "Hari dengan penjualan terendah    : Hari ke-" << minHari + 1
         << " (" << totalHari[minHari] << ")" << endl;

    return 0;
}