// kelas turunan ke-1 (Hierarchical Inheritance: Film -> FilmAnimasi, sejajar dengan FilmAksi & FilmDokumenter)
public class FilmAnimasi extends Film {
    // atribut private tambahan
    private String studio_animasi;
    private String rating_usia; // contoh: SU, 13+, 17+
    private int frame_rate;     // dalam fps

    // constructor, memanggil constructor Film (termasuk membangun JadwalTayang)
    public FilmAnimasi(int id_film, String judul, String genre, int durasi, int harga,
                        String tanggal_tayang, String jam_tayang, String studio_bioskop,
                        String studio_animasi, String rating_usia, int frame_rate) {
        super(id_film, judul, genre, durasi, harga, tanggal_tayang, jam_tayang, studio_bioskop);
        setStudioAnimasi(studio_animasi); // inisialisasi
        setRatingUsia(rating_usia); // inisialisasi
        setFrameRate(frame_rate); // inisialisasi
    }

    // getter
    public String getStudioAnimasi() {
        return studio_animasi; // mengambil value
    }

    public String getRatingUsia() {
        return rating_usia; // mengambil value
    }

    public int getFrameRate() {
        return frame_rate; // mengambil value
    }

    // setter
    public void setStudioAnimasi(String studio_animasi) {
        this.studio_animasi = studio_animasi; // inisialisasi
    }

    public void setRatingUsia(String rating_usia) {
        this.rating_usia = rating_usia; // inisialisasi
    }

    public void setFrameRate(int frame_rate) {
        if (frame_rate > 0) {
            this.frame_rate = frame_rate; // inisialisasi
        } else {
            System.out.println("Frame rate harus lebih dari 0.");
        }
    }

    // prosedur menampilkan data, memanggil dulu tampilkanData() milik Film (inheritance, bukan override)
    public void tampilkanDataAnimasi() {
        tampilkanData(); // pakai ulang method dari Film
        System.out.println("Tipe Film      : Film Animasi");
        System.out.println("Studio Animasi : " + getStudioAnimasi());
        System.out.println("Rating Usia    : " + getRatingUsia());
        System.out.println("Frame Rate     : " + getFrameRate() + " fps");
    }
}
