// kelas turunan ke-3 (Hierarchical Inheritance: Film -> FilmDokumenter, sejajar dengan FilmAnimasi & FilmAksi)
public class FilmDokumenter extends Film {
    // atribut private tambahan
    private String sutradara_riset;   // penanggung jawab riset/investigasi
    private String subjek_dokumenter; // topik yang diangkat
    private int jumlah_narasumber;

    // constructor, memanggil constructor Film (termasuk membangun JadwalTayang)
    public FilmDokumenter(int id_film, String judul, String genre, int durasi, int harga,
                           String tanggal_tayang, String jam_tayang, String studio_bioskop,
                           String sutradara_riset, String subjek_dokumenter, int jumlah_narasumber) {
        super(id_film, judul, genre, durasi, harga, tanggal_tayang, jam_tayang, studio_bioskop);
        setSutradaraRiset(sutradara_riset); // inisialisasi
        setSubjekDokumenter(subjek_dokumenter); // inisialisasi
        setJumlahNarasumber(jumlah_narasumber); // inisialisasi
    }

    // getter
    public String getSutradaraRiset() {
        return sutradara_riset; // mengambil value
    }

    public String getSubjekDokumenter() {
        return subjek_dokumenter; // mengambil value
    }

    public int getJumlahNarasumber() {
        return jumlah_narasumber; // mengambil value
    }

    // setter
    public void setSutradaraRiset(String sutradara_riset) {
        this.sutradara_riset = sutradara_riset; // inisialisasi
    }

    public void setSubjekDokumenter(String subjek_dokumenter) {
        this.subjek_dokumenter = subjek_dokumenter; // inisialisasi
    }

    public void setJumlahNarasumber(int jumlah_narasumber) {
        if (jumlah_narasumber >= 0) {
            this.jumlah_narasumber = jumlah_narasumber; // inisialisasi
        } else {
            System.out.println("Jumlah narasumber tidak boleh negatif.");
        }
    }

    // prosedur menampilkan data, memanggil dulu tampilkanData() milik Film (inheritance, bukan override)
    public void tampilkanDataDokumenter() {
        tampilkanData(); // pakai ulang method dari Film
        System.out.println("Tipe Film         : Film Dokumenter");
        System.out.println("Sutradara Riset   : " + getSutradaraRiset());
        System.out.println("Subjek Dokumenter : " + getSubjekDokumenter());
        System.out.println("Jumlah Narasumber : " + getJumlahNarasumber() + " orang");
    }
}
