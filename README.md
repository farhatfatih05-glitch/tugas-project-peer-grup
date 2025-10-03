<!doctype html>
<html lang="id">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width,initial-scale=1">
  <title>Dokumentasi Project: Aplikasi Kasir Mini (C++)</title>
  <style>
    body{font-family:system-ui,-apple-system,Segoe UI,Roboto,Ubuntu,"Helvetica Neue",Arial;line-height:1.6;margin:24px;color:#111}
    header{border-bottom:2px solid #e5e7eb;padding-bottom:12px;margin-bottom:18px}
    h1{font-size:24px;margin:0}
    h2{color:#0b5ed7;margin-top:18px}
    pre{background:#f8fafc;padding:12px;border-radius:6px;overflow:auto}
    code{font-family:SFMono-Regular,Menlo,Monaco,Consolas,"Liberation Mono","Courier New",monospace}
    section{margin-bottom:12px}
    .example {background:#fff7ed;padding:12px;border-left:4px solid #f59e0b}
    footer{font-size:13px;color:#555;margin-top:20px;border-top:1px solid #eee;padding-top:8px}
  </style>
</head>
<body>
  <header>
    <h1>Aplikasi Kasir Mini (C++) — Dokumentasi</h1>
    <p>Dokumen ini berisi latar belakang, fungsi program, langkah pembuatan, algoritma, contoh input/output, dan proyeksi pengembangan.</p>
  </header>

  <section>
    <h2>Latar Belakang</h2>
    <p>Di materi pemrograman dasar, konsep <strong>looping</strong> dan <strong>fungsi</strong> sangat penting. Project ini adalah aplikasi kasir sederhana yang dibuat untuk melatih penerapan kedua konsep tersebut. Aplikasi dapat digunakan untuk menghitung subtotal, diskon, pajak, total, dan kembalian pada transaksi sederhana.</p>
  </section>

  <section>
    <h2>Fungsi Program</h2>
    <ul>
      <li>Menerima input beberapa item (nama, harga, jumlah).</li>
      <li>Menampilkan daftar belanja beserta subtotal tiap item.</li>
      <li>Menghitung subtotal keseluruhan, menerapkan diskon berdasarkan aturan, menghitung pajak, dan menentukan total bayar.</li>
      <li>Menerima pembayaran dan menghitung kembalian.</li>
    </ul>
  </section>

  <section>
    <h2>Program (Kode Singkat)</h2>
    <p>Berikut versi C++ singkat yang digunakan dalam project:</p>
    <pre><code>#include &lt;iostream&gt;
#include &lt;string&gt;
using namespace std;

const float PAJAK = 0.1; // 10%

// Fungsi hitung total belanja
float hitungTotal(float harga[], int qty[], int n) {
    float subtotal = 0;
    for (int i = 0; i &lt; n; i++) {
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

    for (int i = 0; i &lt; n; i++) {
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
    for (int i = 0; i &lt; n; i++) {
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
</code></pre>
  </section>

  <section>
    <h2>Langkah-langkah Membuat Program</h2>
    <ol>
      <li>Rancang input yang diperlukan: nama, harga, qty, jumlah item.</li>
      <li>Buat array untuk menyimpan data (nama[], harga[], qty[]).</li>
      <li>Buat fungsi <code>hitungTotal</code> yang menerima array dan mengembalikan total setelah diskon & pajak.</li>
      <li>Implementasikan looping untuk membaca input dan menampilkan daftar belanja.</li>
      <li>Tambahkan mekanisme pembayaran (input uang bayar & hitung kembalian).</li>
      <li>Uji program dengan beberapa skenario (tanpa diskon, diskon 5%, diskon 10%).</li>
    </ol>
  </section>

  <section>
    <h2>Penjelasan Algoritma</h2>
    <p>Algoritma utama singkatnya:</p>
    <ol>
      <li>Baca n (jumlah item).</li>
      <li>Untuk setiap i dari 0 sampai n-1: baca nama[i], harga[i], qty[i] (looping input).</li>
      <li>Hitung subtotal: jumlahkan harga[i] * qty[i] untuk semua i (looping penjumlahan).</li>
      <li>Tentukan diskon: jika subtotal &gt;= 500000 → 10%, else if &gt;= 200000 → 5%, else 0%.</li>
      <li>Kurangi subtotal dengan diskon, lalu hitung pajak 10% dari nilai setelah diskon.</li>
      <li>Total bayar = setelahDiskon + pajak. Terima input bayar, kembalian = bayar - total.</li>
    </ol>
    <p>Kompleksitas: operasi utama (input, penjumlahan) berjalan linear O(n) terhadap jumlah item.</p>
  </section>

  <section>
    <h2>Contoh Input &amp; Output</h2>
    <div class="example">
      <strong>Input:</strong>
      <pre>n = 2
Nama: Pulsa, Harga: 50000, Qty: 2
Nama: Headset, Harga: 150000, Qty: 1
Bayar: 300000</pre>
      <strong>Perhitungan &amp; Output:</strong>
      <pre>Subtotal = 250000
Diskon = 5% -> 12500
Setelah diskon = 237500
Pajak 10% = 23750
Total bayar = 261250
Kembalian = 38750</pre>
    </div>
  </section>

  <section>
    <h2>Proyeksi Ke Depan (Pengembangan)</h2>
    <ul>
      <li>Mengganti array statis dengan <code>vector</code> atau <code>struct Item</code> untuk kode yang lebih terstruktur.</li>
      <li>Menambahkan validasi input (tidak menerima negatif, menangani nama dengan spasi).</li>
      <li>Fitur edit/hapus item, menyimpan struk ke file (receipt.txt atau CSV).</li>
      <li>Migrasi ke GUI sederhana (mis. Qt) atau versi web dengan backend untuk persistence dan multi-user.</li>
      <li>Integrasi sistem barcode atau database SQLite untuk skala lebih besar.</li>
    </ul>
  </section>

  <section>
    <h2>Cara Menjalankan Program</h2>
    <ol>
      <li>Simpan kode sebagai <code>kasir.cpp</code>.</li>
      <li>Kompilasi: <code>g++ -std=c++17 kasir.cpp -o kasir</code>.</li>
      <li>Jalankan: <code>./kasir</code> (Linux/Mac) atau <code>kasir.exe</code> (Windows).</li>
    </ol>
  </section>

  <footer>
    <p>Dibuat untuk keperluan tugas kuliah — Aplikasi kasir mini ini bertujuan memperlihatkan penerapan dasar looping dan fungsi di C++. Anda bisa menyalin seluruh isi HTML ini ke file <code>index.html</code> untuk dokumentasi tugas.</p>
  </footer>
</body>
</html>

# tugas-project-peer-grup
Project kasir mini menggunakan C++ dengan looping dan function.
