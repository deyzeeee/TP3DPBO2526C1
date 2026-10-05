// kelas turunan ke-1 (Hierarchical Inheritance: Film -> FilmAnimasi, sejajar dengan FilmAksi & FilmDokumenter)
class FilmAnimasi : public Film {
    private:
        string studio_animasi;
        string rating_usia;  // contoh: SU, 13+, 17+
        int frame_rate;      // dalam fps

    public:
    // constructor, memanggil constructor Film (termasuk membangun JadwalTayang)
    FilmAnimasi(int id, string judul, string genre, int durasi, int harga,
                string tanggal_tayang, string jam_tayang, string studio_bioskop,
                string studio_animasi, string rating_usia, int frame_rate)
        : Film(id, judul, genre, durasi, harga, tanggal_tayang, jam_tayang, studio_bioskop) {
        setStudioAnimasi(studio_animasi); // inisialisasi
        setRatingUsia(rating_usia); // inisialisasi
        setFrameRate(frame_rate); // inisialisasi
    }

    // setter
    void setStudioAnimasi(const string& studio_animasi) {
        this->studio_animasi = studio_animasi; // inisialisasi
    }
    void setRatingUsia(const string& rating_usia) {
        this->rating_usia = rating_usia; // inisialisasi
    }
    void setFrameRate(const int& frame_rate) {
        if (frame_rate > 0) {
            this->frame_rate = frame_rate; // inisialisasi
        } else {
            cout << "Frame rate harus lebih dari 0." << endl;
        }
    }

    // getter
    string getStudioAnimasi() const {
        return studio_animasi; // mengambil value
    }
    string getRatingUsia() const {
        return rating_usia; // mengambil value
    }
    int getFrameRate() const {
        return frame_rate; // mengambil value
    }

    // prosedur menampilkan data, memanggil dulu tampilkanData() milik Film (inheritance, bukan override)
    void tampilkanDataAnimasi() const {
        tampilkanData(); // pakai ulang method dari Film
        cout << "Tipe Film      : Film Animasi" << endl
             << "Studio Animasi : " << getStudioAnimasi() << endl
             << "Rating Usia    : " << getRatingUsia() << endl
             << "Frame Rate     : " << getFrameRate() << " fps" << endl;
    }
};
