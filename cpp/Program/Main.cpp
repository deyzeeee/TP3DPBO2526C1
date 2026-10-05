#include "Film.cpp"
#include "FilmAnimasi.cpp"
#include "FilmAksi.cpp"
#include "FilmDokumenter.cpp"
#include <iostream>
#include <vector>

using namespace std;

// Array of Object: 3 vector terpisah (satu per jenis film)
vector<FilmAnimasi> daftarAnimasi;
vector<FilmAksi> daftarAksi;
vector<FilmDokumenter> daftarDokumenter;

// cek ID sudah dipakai atau belum, dicek ke ketiga vector
bool isIdExists(int id_film) {
    bool ada = false; // flag
    int i = 0; // index

    i = 0;
    while (i < (int)daftarAnimasi.size() && !ada) {
        if (daftarAnimasi[i].getId() == id_film) {
            ada = true;
        }
        i++;
    }

    i = 0;
    while (i < (int)daftarAksi.size() && !ada) {
        if (daftarAksi[i].getId() == id_film) {
            ada = true;
        }
        i++;
    }

    i = 0;
    while (i < (int)daftarDokumenter.size() && !ada) {
        if (daftarDokumenter[i].getId() == id_film) {
            ada = true;
        }
        i++;
    }

    return ada;
}

// prosedur menampilkan seluruh data film secara lengkap (dipakai sebelum & sesudah tambah data)
void tampilkanSemuaData() {
    if (daftarAnimasi.empty() && daftarAksi.empty() && daftarDokumenter.empty()) {
        cout << "\nBelum ada data film.\n";
        return;
    }

    cout << "\n==================== DAFTAR FILM HOLO CINEMA ====================\n";

    cout << "\n-- Film Animasi --\n";
    for (size_t i = 0; i < daftarAnimasi.size(); i++) {
        cout << "\n--- Film ke-" << (i + 1) << " ---\n";
        daftarAnimasi[i].tampilkanDataAnimasi();
    }

    cout << "\n-- Film Aksi --\n";
    for (size_t i = 0; i < daftarAksi.size(); i++) {
        cout << "\n--- Film ke-" << (i + 1) << " ---\n";
        daftarAksi[i].tampilkanDataAksi();
    }

    cout << "\n-- Film Dokumenter --\n";
    for (size_t i = 0; i < daftarDokumenter.size(); i++) {
        cout << "\n--- Film ke-" << (i + 1) << " ---\n";
        daftarDokumenter[i].tampilkanDataDokumenter();
    }

    cout << "===================================================================\n";
}

// prosedur menambah 1 film baru, user memilih dulu jenisnya
void tambahData() {
    string inputStr;

    cout << "\nPilih jenis film:\n";
    cout << "1. Film Animasi\n";
    cout << "2. Film Aksi\n";
    cout << "3. Film Dokumenter\n";

    int jenis = 0;
    bool jenisValid = false; // flag validasi jenis
    while (!jenisValid) {
        try {
            cout << "Pilihan jenis: ";
            getline(cin, inputStr);
            jenis = stoi(inputStr);
            if (jenis >= 1 && jenis <= 3) {
                jenisValid = true;
            } else {
                cout << "Pilihan harus 1, 2, atau 3.\n";
            }
        } catch (const invalid_argument&) {
            cout << "Input tidak valid. Masukkan angka.\n";
        }
    }

    // ---- atribut dasar Film (wajib untuk semua jenis) ----
    int id_film = 0;
    bool idValid = false; // flag validasi ID
    while (!idValid) {
        try {
            cout << "ID Film: ";
            getline(cin, inputStr);
            id_film = stoi(inputStr);
            if (!isIdExists(id_film)) {
                idValid = true;
            } else {
                cout << "ID ini sudah ada. Silakan masukkan ID lain.\n";
            }
        } catch (const invalid_argument&) {
            cout << "Input tidak valid. Masukkan angka.\n";
        }
    }

    string judul, genre;
    cout << "Judul Film: ";
    getline(cin, judul);
    cout << "Genre Film: ";
    getline(cin, genre);

    int durasi = 0;
    bool durasiValid = false; // flag validasi durasi
    while (!durasiValid) {
        try {
            cout << "Durasi (menit): ";
            getline(cin, inputStr);
            durasi = stoi(inputStr);
            if (durasi < 0) {
                cout << "Input tidak valid. Durasi tidak boleh negatif.\n";
            } else {
                durasiValid = true;
            }
        } catch (const invalid_argument&) {
            cout << "Input tidak valid. Masukkan angka.\n";
        }
    }

    int harga = 0;
    bool hargaValid = false; // flag validasi harga
    while (!hargaValid) {
        try {
            cout << "Harga Tiket (Rp): ";
            getline(cin, inputStr);
            harga = stoi(inputStr);
            if (harga <= 0) {
                cout << "Input tidak valid. Harga harus lebih dari 0.\n";
            } else {
                hargaValid = true;
            }
        } catch (const invalid_argument&) {
            cout << "Input tidak valid. Masukkan angka.\n";
        }
    }

    // ---- atribut JadwalTayang (composition, wajib untuk semua jenis) ----
    string tanggal_tayang, jam_tayang, studio_bioskop;
    cout << "Tanggal Tayang (contoh: 12-10-2026): ";
    getline(cin, tanggal_tayang);
    cout << "Jam Tayang (contoh: 19:30): ";
    getline(cin, jam_tayang);
    cout << "Studio Bioskop (contoh: Studio 1): ";
    getline(cin, studio_bioskop);

    // ---- atribut tambahan sesuai jenis yang dipilih ----
    if (jenis == 1) {
        string studio_animasi, rating_usia;
        cout << "Studio Animasi: ";
        getline(cin, studio_animasi);
        cout << "Rating Usia (contoh: SU, 13+, 17+): ";
        getline(cin, rating_usia);

        int frame_rate = 0;
        bool frValid = false; // flag validasi frame rate
        while (!frValid) {
            try {
                cout << "Frame Rate (fps): ";
                getline(cin, inputStr);
                frame_rate = stoi(inputStr);
                if (frame_rate <= 0) {
                    cout << "Input tidak valid. Frame rate harus lebih dari 0.\n";
                } else {
                    frValid = true;
                }
            } catch (const invalid_argument&) {
                cout << "Input tidak valid. Masukkan angka.\n";
            }
        }

        daftarAnimasi.push_back(FilmAnimasi(id_film, judul, genre, durasi, harga,
                                             tanggal_tayang, jam_tayang, studio_bioskop,
                                             studio_animasi, rating_usia, frame_rate));
    } else if (jenis == 2) {
        string koreografer_laga, tingkat_bahaya;
        cout << "Koreografer Laga: ";
        getline(cin, koreografer_laga);
        cout << "Tingkat Bahaya (contoh: Ringan, Sedang, Berat): ";
        getline(cin, tingkat_bahaya);

        int jumlah_stuntman = 0;
        bool stuntValid = false; // flag validasi jumlah stuntman
        while (!stuntValid) {
            try {
                cout << "Jumlah Pemeran Pengganti: ";
                getline(cin, inputStr);
                jumlah_stuntman = stoi(inputStr);
                if (jumlah_stuntman < 0) {
                    cout << "Input tidak valid. Tidak boleh negatif.\n";
                } else {
                    stuntValid = true;
                }
            } catch (const invalid_argument&) {
                cout << "Input tidak valid. Masukkan angka.\n";
            }
        }

        daftarAksi.push_back(FilmAksi(id_film, judul, genre, durasi, harga,
                                       tanggal_tayang, jam_tayang, studio_bioskop,
                                       koreografer_laga, tingkat_bahaya, jumlah_stuntman));
    } else {
        string sutradara_riset, subjek_dokumenter;
        cout << "Sutradara Riset: ";
        getline(cin, sutradara_riset);
        cout << "Subjek Dokumenter: ";
        getline(cin, subjek_dokumenter);

        int jumlah_narasumber = 0;
        bool narasumberValid = false; // flag validasi jumlah narasumber
        while (!narasumberValid) {
            try {
                cout << "Jumlah Narasumber: ";
                getline(cin, inputStr);
                jumlah_narasumber = stoi(inputStr);
                if (jumlah_narasumber < 0) {
                    cout << "Input tidak valid. Tidak boleh negatif.\n";
                } else {
                    narasumberValid = true;
                }
            } catch (const invalid_argument&) {
                cout << "Input tidak valid. Masukkan angka.\n";
            }
        }

        daftarDokumenter.push_back(FilmDokumenter(id_film, judul, genre, durasi, harga,
                                                   tanggal_tayang, jam_tayang, studio_bioskop,
                                                   sutradara_riset, subjek_dokumenter, jumlah_narasumber));
    }

    cout << "\nFilm berhasil ditambahkan!\n";
}

int main() {
    // data awal (array of object, wajib ada sebelum input user)
    daftarAnimasi.push_back(FilmAnimasi(101, "Senja di Negeri Angin", "Slice of Life", 92, 38000,
                                         "05-10-2026", "16:00", "Studio 1",
                                         "Studio Awan", "SU", 24));
    daftarAnimasi.push_back(FilmAnimasi(102, "Petualangan Rimba", "Petualangan", 96, 40000,
                                         "05-10-2026", "19:00", "Studio 2",
                                         "Kagaya Studio", "SU", 24));
    daftarAksi.push_back(FilmAksi(201, "Garis Pertahanan", "Aksi", 118, 48000,
                                   "05-10-2026", "20:30", "Studio 3",
                                   "Andri Pratama", "Berat", 12));
    daftarAksi.push_back(FilmAksi(202, "Malam Pengejaran", "Aksi", 105, 45000,
                                   "06-10-2026", "21:00", "Studio 1",
                                   "Reza Saputra", "Sedang", 8));
    daftarDokumenter.push_back(FilmDokumenter(301, "Jejak Nusantara", "Dokumenter", 85, 35000,
                                               "06-10-2026", "15:00", "Studio 4",
                                               "Dian Kusuma", "Sejarah Rempah Indonesia", 6));

    cout << "\nDATA AWAL (SEBELUM PENAMBAHAN)\n";
    tampilkanSemuaData();

    string pilihan = "";
    while (pilihan != "3") { // berhenti jika user memilih 3 (Keluar)
        cout << "\n=== MENU HOLO CINEMA ===\n";
        cout << "1. Tampilkan Semua Data Film\n";
        cout << "2. Tambah Film Baru\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        getline(cin, pilihan);

        if (pilihan == "1") {
            tampilkanSemuaData();
        } else if (pilihan == "2") {
            tambahData();
        } else if (pilihan == "3") {
            cout << "\nDATA AKHIR (SESUDAH PENAMBAHAN)\n";
            tampilkanSemuaData();
            cout << "\nTerima kasih sudah menggunakan sistem Holo Cinema!\n";
        } else {
            cout << "Pilihan tidak valid. Coba lagi\n";
        }
    }

    return 0;
}
