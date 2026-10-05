// kelas turunan ke-2 (Hierarchical Inheritance: Film -> FilmAksi, sejajar dengan FilmAnimasi & FilmDokumenter)
public class FilmAksi extends Film {
    // atribut private tambahan
    private String koreografer_laga;
    private String tingkat_bahaya;        // contoh: Ringan, Sedang, Berat
    private int jumlah_pemeran_pengganti; // jumlah stuntman

    // constructor, memanggil constructor Film (termasuk membangun JadwalTayang)
    public FilmAksi(int id_film, String judul, String genre, int durasi, int harga,
                     String tanggal_tayang, String jam_tayang, String studio_bioskop,
                     String koreografer_laga, String tingkat_bahaya, int jumlah_pemeran_pengganti) {
        super(id_film, judul, genre, durasi, harga, tanggal_tayang, jam_tayang, studio_bioskop);
        setKoreograferLaga(koreografer_laga); // inisialisasi
        setTingkatBahaya(tingkat_bahaya); // inisialisasi
        setJumlahPemeranPengganti(jumlah_pemeran_pengganti); // inisialisasi
    }

    // getter
    public String getKoreograferLaga() {
        return koreografer_laga; // mengambil value
    }

    public String getTingkatBahaya() {
        return tingkat_bahaya; // mengambil value
    }

    public int getJumlahPemeranPengganti() {
        return jumlah_pemeran_pengganti; // mengambil value
    }

    // setter
    public void setKoreograferLaga(String koreografer_laga) {
        this.koreografer_laga = koreografer_laga; // inisialisasi
    }

    public void setTingkatBahaya(String tingkat_bahaya) {
        this.tingkat_bahaya = tingkat_bahaya; // inisialisasi
    }

    public void setJumlahPemeranPengganti(int jumlah_pemeran_pengganti) {
        if (jumlah_pemeran_pengganti >= 0) {
            this.jumlah_pemeran_pengganti = jumlah_pemeran_pengganti; // inisialisasi
        } else {
            System.out.println("Jumlah pemeran pengganti tidak boleh negatif.");
        }
    }

    // prosedur menampilkan data, memanggil dulu tampilkanData() milik Film (inheritance, bukan override)
    public void tampilkanDataAksi() {
        tampilkanData(); // pakai ulang method dari Film
        System.out.println("Tipe Film                : Film Aksi");
        System.out.println("Koreografer Laga         : " + getKoreograferLaga());
        System.out.println("Tingkat Bahaya           : " + getTingkatBahaya());
        System.out.println("Jumlah Pemeran Pengganti : " + getJumlahPemeranPengganti() + " orang");
    }
}
