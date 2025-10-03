<!doctype html>
<html lang="id">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width,initial-scale=1">
  <title>Dokumentasi Project: Aplikasi Kasir Mini (C++)</title>
  <style>
    body {
      font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
      margin: 0;
      padding: 0;
      background: #f9fafb;
      color: #111827;
      line-height: 1.7;
    }
    header {
      background: linear-gradient(135deg, #0ea5e9, #2563eb);
      color: white;
      padding: 30px;
      text-align: center;
    }
    header h1 {
      margin: 0;
      font-size: 28px;
    }
    header p {
      margin: 8px 0 0;
      font-size: 16px;
      opacity: 0.9;
    }
    main {
      max-width: 900px;
      margin: 30px auto;
      padding: 0 20px;
    }
    section {
      background: white;
      padding: 20px;
      border-radius: 10px;
      margin-bottom: 20px;
      box-shadow: 0 2px 6px rgba(0,0,0,0.08);
    }
    h2 {
      color: #1d4ed8;
      margin-top: 0;
    }
    ul, ol {
      margin-left: 20px;
    }
    pre {
      background: #1e293b;
      color: #f8fafc;
      padding: 15px;
      border-radius: 8px;
      overflow-x: auto;
    }
    code {
      font-family: Consolas, monospace;
      font-size: 14px;
    }
    .example {
      background: #fef9c3;
      border-left: 5px solid #f59e0b;
      padding: 15px;
      border-radius: 6px;
    }
    footer {
      text-align: center;
      font-size: 14px;
      color: #6b7280;
      padding: 15px;
      background: #f3f4f6;
    }
  </style>
</head>
<body>
  <header>
    <h1>Aplikasi Kasir Mini (C++)</h1>
    <p>Dokumentasi Project Tugas Pemrograman — Looping & Function</p>
  </header>
  
  <main>
    <section>
      <h2>Latar Belakang</h2>
      <p>Konsep <strong>looping</strong> dan <strong>fungsi</strong> merupakan dasar penting dalam pemrograman. Untuk melatih penerapan konsep tersebut, dibuatlah sebuah aplikasi kasir sederhana yang mampu menghitung subtotal, diskon, pajak, total, dan kembalian dari transaksi pembelian.</p>
    </section>

    <section>
      <h2>Fungsi Program</h2>
      <ul>
        <li>Input data barang: nama, harga, dan jumlah.</li>
        <li>Menampilkan daftar belanja dan subtotal per item.</li>
        <li>Menghitung subtotal keseluruhan, diskon, pajak, dan total bayar.</li>
        <li>Menerima pembayaran serta menampilkan kembalian.</li>
      </ul>
    </section>

    <section>
      <h2>Kode Program (C++)</h2>
      <pre><code>#include &lt;iostream&gt;
#include &lt;string&gt;
using namespace std;

const float PAJAK = 0.1;

float hitungTotal(float harga[], int qty[], int n) {
    float subtotal = 0;
    for (int i = 0; i &lt; n; i++) subtotal += harga[i] * qty[i];
    float diskon = 0;
    if (subtotal &gt;= 500000) diskon = 0.1 * subtotal;
    else if (subtotal &gt;= 200000) diskon = 0.05 * subtotal;
    float setelahDiskon = subtotal - diskon;
    return setelahDiskon + (setelahDiskon * PAJAK);
}

int main() {
    string nama[50]; float harga[50]; int qty[50]; int n;
    cout &lt;&lt; "Masukkan jumlah item: "; cin &gt;&gt; n;
    for (int i=0;i&lt;n;i++){
        cout &lt;&lt; "Item " &lt;&lt; i+1 &lt;&lt; " Nama: "; cin &gt;&gt; nama[i];
        cout &lt;&lt; "Harga: "; cin &gt;&gt; harga[i];
        cout &lt;&lt; "Jumlah: "; cin &gt;&gt; qty[i];
    }
    float subtotal=0;
    for(int i=0;i&lt;n;i++) subtotal+=harga[i]*qty[i];
    float total=hitungTotal(harga,qty,n);
    cout &lt;&lt; "Subtotal: Rp" &lt;&lt; subtotal &lt;&lt; "\nTotal Bayar: Rp" &lt;&lt; total;
}
</code></pre>
    </section>

    <section>
      <h2>Langkah-langkah Pembuatan</h2>
      <ol>
        <li>Rancang input: nama, harga, jumlah barang.</li>
        <li>Buat array untuk menyimpan data.</li>
        <li>Buat fungsi <code>hitungTotal()</code> untuk men
