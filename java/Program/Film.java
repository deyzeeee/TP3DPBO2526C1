// kelas dasar (parent dari hierarchical inheritance: Film -> FilmAnimasi, FilmAksi, FilmDokumenter)
public class Film {
    // atribut private
    private int id_film;
    private String judul;
    private String genre;
    private int durasi; // dalam menit
    private int harga;  // harga tiket dalam rupiah
    private JadwalTayang jadwalTayang; // composition: Film punya JadwalTayang

    // constructor, sekaligus membuat objek JadwalTayang
    public Film(int id_film, String judul, String genre, int durasi, int harga,
                String tanggal_tayang, String jam_tayang, String studio_bioskop) {
        setId(id_film); // inisialisasi
        setJudul(judul); // inisialisasi
        setGenre(genre); // inisialisasi
        setDurasi(durasi); // inisialisasi
        setHarga(harga); // inisialisasi
        this.jadwalTayang = new JadwalTayang(tanggal_tayang, jam_tayang, studio_bioskop);
    }

    // getter
    public int getId() {
        return id_film; // mengambil value
    }

    public String getJudul() {
        return judul; // mengambil value
    }

    public String getGenre() {
        return genre; // mengambil value
    }

    public int getDurasi() {
        return durasi; // mengambil value
    }

    public int getHarga() {
        return harga; // mengambil value
    }

    public JadwalTayang getJadwalTayang() {
        return jadwalTayang; // mengambil objek composition
    }

    // setter
    public void setId(int id_film) {
        this.id_film = id_film; // inisialisasi
    }

    public void setJudul(String judul) {
        this.judul = judul; // inisialisasi
    }

    public void setGenre(String genre) {
        this.genre = genre; // inisialisasi
    }

    public void setDurasi(int durasi) {
        if (durasi >= 0) {
            this.durasi = durasi; // inisialisasi
        } else {
            System.out.println("Durasi tidak boleh negatif.");
        }
    }

    public void setHarga(int harga) {
        if (harga > 0) {
            this.harga = harga; // inisialisasi
        } else {
            System.out.println("Harga harus lebih dari 0.");
        }
    }

    // prosedur menampilkan data dasar (dipakai lagi oleh tiap kelas turunan)
    public void tampilkanData() {
        System.out.println("ID Film   : " + getId());
        System.out.println("Judul     : " + getJudul());
        System.out.println("Genre     : " + getGenre());
        System.out.println("Durasi    : " + getDurasi() + " menit");
        System.out.println("Harga     : Rp. " + getHarga());
        jadwalTayang.tampilkanJadwal();
    }
}
