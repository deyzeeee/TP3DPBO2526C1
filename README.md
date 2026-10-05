# JANJI
Saya Muhammad Fadey Rafif dengan NIM 2504792 mengerjakan Tugas Praktikum 3 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

# STRUKTUR FILE

```
├── cpp/
│   ├── Program/
│   │   ├── JadwalTayang.cpp
│   │   ├── Film.cpp
│   │   ├── FilmAnimasi.cpp
│   │   ├── FilmAksi.cpp
│   │   ├── FilmDokumenter.cpp
│   │   ├── Main.cpp
│   │   └── testcase.txt
│   └── Dokumentasi/
│       └── screenshot
│
├── python/
│   ├── Program/
│   │   ├── JadwalTayang.py
│   │   ├── Film.py
│   │   ├── FilmAnimasi.py
│   │   ├── FilmAksi.py
│   │   ├── FilmDokumenter.py
│   │   ├── Main.py
│   │   └── testcase.txt
│   └── Dokumentasi/
│       └── screenshot
│
├── java/
│   ├── Program/
│   │   ├── JadwalTayang.java
│   │   ├── Film.java
│   │   ├── FilmAnimasi.java
│   │   ├── FilmAksi.java
│   │   ├── FilmDokumenter.java
│   │   ├── Main.java
│   │   └── testcase.txt
│   └── Dokumentasi/
│       └── screenshot
│
└── README.md
```

# 🎬 TEMA PROGRAM
Melanjutkan tema bioskop "Holo Cinema" dari tugas-tugas sebelumnya, sekarang  saya mendemonstrasikan dua konsep OOP baru: **Composition** dan **Hierarchical Inheritance**.

Terdapat 5 class:
1. **JadwalTayang** : class mandiri, dipakai lewat **composition** oleh `Film`.
2. **Film** : kelas dasar (parent dari hierarchical inheritance).
3. **FilmAnimasi** : turunan `Film`.
4. **FilmAksi** : turunan `Film`.
5. **FilmDokumenter** : turunan `Film`.

`FilmAnimasi`, `FilmAksi`, dan `FilmDokumenter` sama-sama mewarisi langsung dari `Film` (sejajar satu sama lain, bukan berantai), inilah **Hierarchical Inheritance**, berbeda dengan tugas sebelumnya yang multilevel (`Film -> FilmAnimasi -> Film2D`).

# Diagram Konsep

<img src="dokumentasi/diagram TP3.png" alt="diagram TP3">
<br>

1. `JadwalTayang`
   - atribut (private, `-`): `tanggal_tayang : string`, `jam_tayang : string`, `studio_bioskop : string`
   - method (public, `+`): getter & setter tiap atribut, `tampilkanjadwal()`

2. `Film`
   - atribut (private, `-`): `id_film : int`, `judul : string`, `genre : string`, `durasi : int`, `harga : int`, `jadwalTayang : JadwalTayang`
   - method (public, `+`): getter & setter tiap atribut, `tampilkandata()`

3. `FilmAnimasi`
   - atribut tambahan (private, `-`): `studio_animasi : string`, `rating_usia : string`, `frame_rate : int`
   - method tambahan (public, `+`): getter & setter atribut tambahan, `tampilkandataanimasi()`

4. `FilmAksi`
   - atribut tambahan (private, `-`): `koreografer_laga : string`, `tingkat_bahaya : string`, `jumlah_pemeran_pengganti : int`
   - method tambahan (public, `+`): getter & setter atribut tambahan, `tampilkandataaksi()`

5. `FilmDokumenter`
   - atribut tambahan (private, `-`): `sutradara_riset : string`, `subjek_dokumenter : string`, `jumlah_narasumber : int`
   - method tambahan (public, `+`): getter & setter atribut tambahan, `tampilkandatadokumenter()`

### Alasan pemilihan class & relasi

**Composition `Film` punya `JadwalTayang`**
Satu jadwal tayang (tanggal, jam, studio) cuma bermakna kalau melekat pada satu film tertentu, tidak pernah berdiri sendiri, tidak dibagi ke film lain, dan dibuat bersamaan saat objek `Film` dibuat (lihat constructor `Film`, yang langsung membangun `JadwalTayang` di dalamnya). Ini beda dengan *aggregation*, yang membolehkan objek yang "dimiliki" tetap hidup independen atau dipakai bareng beberapa pemilik.

**Hierarchical Inheritance `Film` sebagai parent dari 3 anak sejajar**
`FilmAnimasi`, `FilmAksi`, dan `FilmDokumenter` masing-masing menspesialisasikan `Film` ke arah yang berbeda, tapi semuanya langsung mewarisi dari parent yang sama (sejajar, bukan berantai seperti multilevel inheritance di tugas sebelumnya). Tiap subclass memakai ulang `tampilkandata()` milik `Film` (pemanggilan method biasa, bukan override) lalu menambahkan cetakan atribut miliknya sendiri lewat method dengan nama unik (`tampilkandataanimasi()`, `tampilkandataaksi()`, `tampilkandatadokumenter()`).

**Array of Object**
Data disimpan di **3 array/list terpisah sesuai jenisnya**: `daftarAnimasi` (isi `FilmAnimasi`), `daftarAksi` (isi `FilmAksi`), dan `daftarDokumenter` (isi `FilmDokumenter`) `vector<FilmAnimasi/FilmAksi/FilmDokumenter>` di C++, `List[...]` di Python, `ArrayList<...>` di Java. Pengecekan ID unik dan penampilan semua data dilakukan dengan mengecek/melewati ketiga array tersebut satu per satu.

# ☕️ Class & Atribut

1. **JadwalTayang** (dipakai lewat composition oleh Film)
    - tanggal_tayang : string
    - jam_tayang : string
    - studio_bioskop : string

2. **Film** (parent, kelas biasa/concrete)
    - id_film : int identifier unik, dicek agar tidak duplikat
    - judul : string
    - genre : string
    - durasi : int (menit) divalidasi tidak boleh negatif
    - harga : int (rupiah) divalidasi harus lebih dari 0
    - jadwalTayang : JadwalTayang composition, dibangun di constructor Film

3. **FilmAnimasi** (extends Film)
    - studio_animasi : string
    - rating_usia : string (SU/13+/17+)
    - frame_rate : int (fps) divalidasi harus lebih dari 0

4. **FilmAksi** (extends Film)
    - koreografer_laga : string
    - tingkat_bahaya : string (Ringan/Sedang/Berat)
    - jumlah_pemeran_pengganti : int divalidasi tidak boleh negatif

5. **FilmDokumenter** (extends Film)
    - sutradara_riset : string
    - subjek_dokumenter : string
    - jumlah_narasumber : int divalidasi tidak boleh negatif

# 🔁 Alur Program (berlaku untuk semua bahasa)

```
MULAI
  │
  ├─ 1) Isi data awal ke 3 array (daftarAnimasi, daftarAksi, daftarDokumenter)
  ├─ 2) Tampilkan "DATA AWAL (SEBELUM PENAMBAHAN)"
  │
  ├─ 3) Loop menu, sampai user pilih "Keluar":
  │      ├─ pilih 1 → tampilkan semua data (loop ketiga array satu-satu)
  │      ├─ pilih 2 → tambah data:
  │      │      a. pilih jenis film (Animasi/Aksi/Dokumenter)
  │      │      b. isi atribut Film + JadwalTayang (dengan validasi input)
  │      │      c. isi atribut tambahan sesuai jenis
  │      │      d. simpan ke array yang sesuai jenisnya
  │      └─ pilih 3 → keluar dari loop
  │
  ├─ 4) Tampilkan "DATA AKHIR (SESUDAH PENAMBAHAN)"
SELESAI
```

Penjelasan tiap langkah:
1. Program memuat **data awal** ke masing-masing array sesuai jenisnya, lalu langsung menampilkannya secara lengkap sebagai **"DATA AWAL (SEBELUM PENAMBAHAN)"**.
2. User masuk ke menu: **(1) Tampilkan Semua Data Film**, **(2) Tambah Film Baru**, **(3) Keluar**.
3. Saat menambah data, user memilih dulu jenis film, lalu mengisi atribut dasar `Film` + `JadwalTayang`, kemudian atribut tambahan sesuai jenis yang dipilih (ID dicek harus unik ke ketiga array; durasi, harga, dan atribut numerik lain divalidasi tidak boleh negatif/harus positif). Data baru disimpan ke array yang sesuai jenisnya.
4. Tiap kali memilih "Tampilkan Semua Data Film", program menampilkan isi ketiga array secara berurutan (Animasi → Aksi → Dokumenter), memanggil method tampil milik tiap jenis (`tampilkandataanimasi()`/`tampilkandataaksi()`/`tampilkandatadokumenter()`), yang masing-masing memanggil dulu `tampilkandata()` dari `Film` untuk atribut dasar + jadwal tayang, baru mencetak atribut spesifiknya sendiri.
5. Saat user memilih Keluar, program menampilkan seluruh data sekali lagi sebagai **"DATA AKHIR (SESUDAH PENAMBAHAN)"** sebelum program berhenti.

# ❌ Error Handling
Semua program memvalidasi input non-numeric pada field angka (ID, durasi, harga, frame rate, jumlah pemeran pengganti, jumlah narasumber) dan angka negatif/nol pada field yang mensyaratkan nilai positif, serta ID yang sudah dipakai film lain. Program akan terus meminta input sampai valid.

# DOKUMENTASI OUTPUT

## Output program C++
### Data awal (sebelum penambahan)
<img src="cpp/Dokumentasi/data awal cpp.png" alt="data awal cpp">
<br>

### Tambah data beserta error handling input
<img src="cpp/Dokumentasi/tambah data dan error handling cpp.png" alt="tambah data dan error handling cpp">
<br>

### Data akhir (sesudah penambahan)
<img src="cpp/Dokumentasi/data akhir cpp.png" alt="data akhir cpp">
<br>

## Output program Python
### Data awal (sebelum penambahan)
<img src="python/Dokumentasi/data awal py.png" alt="data awal py">
<br>

### Tambah data beserta error handling input
<img src="python/Dokumentasi/tambah data dan error handling py.png" alt="tambah data dan error handling py">
<br>

### Data akhir (sesudah penambahan)
<img src="python/Dokumentasi/data akhir py.png" alt="data akhir py">
<br>

## Output program Java (bonus)
### Data awal (sebelum penambahan)
<img src="java/Dokumentasi/data awal java.png" alt="data awal java">
<br>

### Tambah data beserta error handling input
<img src="java/Dokumentasi/tambah data dan error handling java.png" alt="tambah data dan error handling java">
<br>

### Data akhir (sesudah penambahan)
<img src="java/Dokumentasi/data akhir java.png" alt="data akhir java">
<br>
