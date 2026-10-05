#include <iostream>
#include <string>
#include "JadwalTayang.cpp"

using namespace std;

// kelas dasar (parent dari hierarchical inheritance: Film -> FilmAnimasi, FilmAksi, FilmDokumenter)
class Film {
    // atribut private
    private:
        int id_film;
        string judul;
        string genre;
        int durasi;   // dalam menit
        int harga;    // harga tiket dalam rupiah
        JadwalTayang jadwalTayang; // composition: Film punya JadwalTayang

    public:
    // constructor, sekaligus membuat objek JadwalTayang
    Film(int id, string judul, string genre, int durasi, int harga,
         string tanggal_tayang, string jam_tayang, string studio_bioskop)
        : jadwalTayang(tanggal_tayang, jam_tayang, studio_bioskop) {
        setId(id); // inisialisasi
        setJudul(judul); // inisialisasi
        setGenre(genre); // inisialisasi
        setDurasi(durasi); // inisialisasi
        setHarga(harga); // inisialisasi
    }

    // setter
    void setId(const int& id) {
        this->id_film = id; // inisialisasi
    }
    void setJudul(const string& judul) {
        this->judul = judul; // inisialisasi
    }
    void setGenre(const string& genre) {
        this->genre = genre; // inisialisasi
    }
    void setDurasi(const int& durasi) {
        if (durasi >= 0) {
            this->durasi = durasi; // inisialisasi
        } else {
            cout << "Durasi tidak boleh negatif." << endl;
        }
    }
    void setHarga(const int& harga) {
        if (harga > 0) {
            this->harga = harga; // inisialisasi
        } else {
            cout << "Harga harus lebih dari 0." << endl;
        }
    }

    // getter
    int getId() const {
        return id_film; // mengambil value
    }
    string getJudul() const {
        return judul; // mengambil value
    }
    string getGenre() const {
        return genre; // mengambil value
    }
    int getDurasi() const {
        return durasi; // mengambil value
    }
    int getHarga() const {
        return harga; // mengambil value
    }
    JadwalTayang getJadwalTayang() const {
        return jadwalTayang; // mengambil objek composition
    }

    // prosedur untuk menampilkan data dasar (dipakai lagi oleh tiap kelas turunan)
    void tampilkanData() const {
        cout << "ID Film   : " << getId() << endl
             << "Judul     : " << getJudul() << endl
             << "Genre     : " << getGenre() << endl
             << "Durasi    : " << getDurasi() << " menit" << endl
             << "Harga     : Rp. " << getHarga() << endl;
        jadwalTayang.tampilkanJadwal();
    }
};
