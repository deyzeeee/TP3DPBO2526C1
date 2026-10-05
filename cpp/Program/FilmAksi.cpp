// kelas turunan ke-2 (Hierarchical Inheritance: Film -> FilmAksi, sejajar dengan FilmAnimasi & FilmDokumenter)
class FilmAksi : public Film {
    private:
        string koreografer_laga;
        string tingkat_bahaya;        // contoh: Ringan, Sedang, Berat
        int jumlah_pemeran_pengganti; // jumlah stuntman

    public:
    // constructor, memanggil constructor Film (termasuk membangun JadwalTayang)
    FilmAksi(int id, string judul, string genre, int durasi, int harga,
             string tanggal_tayang, string jam_tayang, string studio_bioskop,
             string koreografer_laga, string tingkat_bahaya, int jumlah_pemeran_pengganti)
        : Film(id, judul, genre, durasi, harga, tanggal_tayang, jam_tayang, studio_bioskop) {
        setKoreograferLaga(koreografer_laga); // inisialisasi
        setTingkatBahaya(tingkat_bahaya); // inisialisasi
        setJumlahPemeranPengganti(jumlah_pemeran_pengganti); // inisialisasi
    }

    // setter
    void setKoreograferLaga(const string& koreografer_laga) {
        this->koreografer_laga = koreografer_laga; // inisialisasi
    }
    void setTingkatBahaya(const string& tingkat_bahaya) {
        this->tingkat_bahaya = tingkat_bahaya; // inisialisasi
    }
    void setJumlahPemeranPengganti(const int& jumlah_pemeran_pengganti) {
        if (jumlah_pemeran_pengganti >= 0) {
            this->jumlah_pemeran_pengganti = jumlah_pemeran_pengganti; // inisialisasi
        } else {
            cout << "Jumlah pemeran pengganti tidak boleh negatif." << endl;
        }
    }

    // getter
    string getKoreograferLaga() const {
        return koreografer_laga; // mengambil value
    }
    string getTingkatBahaya() const {
        return tingkat_bahaya; // mengambil value
    }
    int getJumlahPemeranPengganti() const {
        return jumlah_pemeran_pengganti; // mengambil value
    }

    // prosedur menampilkan data, memanggil dulu tampilkanData() milik Film (inheritance, bukan override)
    void tampilkanDataAksi() const {
        tampilkanData(); // pakai ulang method dari Film
        cout << "Tipe Film                : Film Aksi" << endl
             << "Koreografer Laga         : " << getKoreograferLaga() << endl
             << "Tingkat Bahaya           : " << getTingkatBahaya() << endl
             << "Jumlah Pemeran Pengganti : " << getJumlahPemeranPengganti() << " orang" << endl;
    }
};
