// kelas mandiri, dipakai lewat composition oleh Film (1 jadwal cuma milik 1 film)
public class JadwalTayang {
    // atribut private
    private String tanggal_tayang;
    private String jam_tayang;
    private String studio_bioskop;

    // constructor
    public JadwalTayang(String tanggal_tayang, String jam_tayang, String studio_bioskop) {
        setTanggalTayang(tanggal_tayang); // inisialisasi
        setJamTayang(jam_tayang); // inisialisasi
        setStudioBioskop(studio_bioskop); // inisialisasi
    }

    // getter
    public String getTanggalTayang() {
        return tanggal_tayang; // mengambil value
    }

    public String getJamTayang() {
        return jam_tayang; // mengambil value
    }

    public String getStudioBioskop() {
        return studio_bioskop; // mengambil value
    }

    // setter
    public void setTanggalTayang(String tanggal_tayang) {
        this.tanggal_tayang = tanggal_tayang; // inisialisasi
    }

    public void setJamTayang(String jam_tayang) {
        this.jam_tayang = jam_tayang; // inisialisasi
    }

    public void setStudioBioskop(String studio_bioskop) {
        this.studio_bioskop = studio_bioskop; // inisialisasi
    }

    // prosedur untuk menampilkan jadwal
    public void tampilkanJadwal() {
        System.out.println("Jadwal Tayang : " + getTanggalTayang() + ", " + getJamTayang()
                + " (" + getStudioBioskop() + ")");
    }
}
