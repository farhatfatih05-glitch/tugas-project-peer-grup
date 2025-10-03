#include <iostream>
#include <string>
using namespace std;

const float PAJAK = 0.1; // 10%


float hitungTotal(float harga[], int qty[], int n) {
    float subtotal = 0;
    for (int i = 0; i < n; i++) {
        subtotal += harga[i] * qty[i];
    }
    float diskon = 0;
    if (subtotal >= 500000) diskon = 0.1 * subtotal;
    else if (subtotal >= 200000) diskon = 0.05 * subtotal;

    float setelahDiskon = subtotal - diskon;
    float total = setelahDiskon + (setelahDiskon * PAJAK);
    return total;
}

int main() {
    string nama[50];
    float harga[50];
    int qty[50];
    int n;

    cout << "===== PROGRAM KASIR MINI =====\n";
    cout << "Masukkan jumlah item: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nItem ke-" << i+1 << endl;
        cout << "Nama barang  : ";
        cin >> nama[i];
        cout << "Harga barang : ";
        cin >> harga[i];
        cout << "Jumlah       : ";
        cin >> qty[i];
    }

    cout << "\n===== DAFTAR BELANJA =====\n";
    float subtotal = 0;
    for (int i = 0; i < n; i++) {
        float totalItem = harga[i] * qty[i];
        subtotal += totalItem;
        cout << nama[i] << " x" << qty[i] << " = Rp" << totalItem << endl;
    }

    float totalBayar = hitungTotal(harga, qty, n);
    cout << "\nSubtotal : Rp" << subtotal << endl;
    cout << "Total Bayar (setelah diskon & pajak): Rp" << totalBayar << endl;

    float bayar;
    cout << "Uang dibayarkan: Rp";
    cin >> bayar;
    cout << "Kembalian      : Rp" << bayar - totalBayar << endl;

    cout << "\nTerima kasih telah berbelanja!\n";
    return 0;
}
