#include <iostream>
#include <string>

using namespace std;

// kelas mandiri, dipakai lewat composition oleh Film (1 jadwal cuma milik 1 film)
class JadwalTayang {
    // atribut private
    private:
        string tanggal_tayang;
        string jam_tayang;
        string studio_bioskop;

    public:
    // constructor
    JadwalTayang(string tanggal_tayang, string jam_tayang, string studio_bioskop) {
        setTanggalTayang(tanggal_tayang); // inisialisasi
        setJamTayang(jam_tayang); // inisialisasi
        setStudioBioskop(studio_bioskop); // inisialisasi
    }

    // setter
    void setTanggalTayang(const string& tanggal_tayang) {
        this->tanggal_tayang = tanggal_tayang; // inisialisasi
    }
    void setJamTayang(const string& jam_tayang) {
        this->jam_tayang = jam_tayang; // inisialisasi
    }
    void setStudioBioskop(const string& studio_bioskop) {
        this->studio_bioskop = studio_bioskop; // inisialisasi
    }

    // getter
    string getTanggalTayang() const {
        return tanggal_tayang; // mengambil value
    }
    string getJamTayang() const {
        return jam_tayang; // mengambil value
    }
    string getStudioBioskop() const {
        return studio_bioskop; // mengambil value
    }

    // prosedur untuk menampilkan jadwal
    void tampilkanJadwal() const {
        cout << "Jadwal Tayang : " << getTanggalTayang() << ", " << getJamTayang()
             << " (" << getStudioBioskop() << ")" << endl;
    }
};
