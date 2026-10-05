// kelas turunan ke-3 (Hierarchical Inheritance: Film -> FilmDokumenter, sejajar dengan FilmAnimasi & FilmAksi)
class FilmDokumenter : public Film {
    private:
        string sutradara_riset;   // penanggung jawab riset/investigasi
        string subjek_dokumenter; // topik yang diangkat
        int jumlah_narasumber;

    public:
    // constructor, memanggil constructor Film (termasuk membangun JadwalTayang)
    FilmDokumenter(int id, string judul, string genre, int durasi, int harga,
                   string tanggal_tayang, string jam_tayang, string studio_bioskop,
                   string sutradara_riset, string subjek_dokumenter, int jumlah_narasumber)
        : Film(id, judul, genre, durasi, harga, tanggal_tayang, jam_tayang, studio_bioskop) {
        setSutradaraRiset(sutradara_riset); // inisialisasi
        setSubjekDokumenter(subjek_dokumenter); // inisialisasi
        setJumlahNarasumber(jumlah_narasumber); // inisialisasi
    }

    // setter
    void setSutradaraRiset(const string& sutradara_riset) {
        this->sutradara_riset = sutradara_riset; // inisialisasi
    }
    void setSubjekDokumenter(const string& subjek_dokumenter) {
        this->subjek_dokumenter = subjek_dokumenter; // inisialisasi
    }
    void setJumlahNarasumber(const int& jumlah_narasumber) {
        if (jumlah_narasumber >= 0) {
            this->jumlah_narasumber = jumlah_narasumber; // inisialisasi
        } else {
            cout << "Jumlah narasumber tidak boleh negatif." << endl;
        }
    }

    // getter
    string getSutradaraRiset() const {
        return sutradara_riset; // mengambil value
    }
    string getSubjekDokumenter() const {
        return subjek_dokumenter; // mengambil value
    }
    int getJumlahNarasumber() const {
        return jumlah_narasumber; // mengambil value
    }

    // prosedur menampilkan data, memanggil dulu tampilkanData() milik Film (inheritance, bukan override)
    void tampilkanDataDokumenter() const {
        tampilkanData(); // pakai ulang method dari Film
        cout << "Tipe Film         : Film Dokumenter" << endl
             << "Sutradara Riset   : " << getSutradaraRiset() << endl
             << "Subjek Dokumenter : " << getSubjekDokumenter() << endl
             << "Jumlah Narasumber : " << getJumlahNarasumber() << " orang" << endl;
    }
};
