from Film import Film

# kelas turunan ke-2 (Hierarchical Inheritance: Film -> FilmAksi, sejajar dengan FilmAnimasi & FilmDokumenter)
class FilmAksi(Film):
    # constructor, memanggil constructor Film (termasuk membangun JadwalTayang)
    def __init__(self, id_film: int, judul: str, genre: str, durasi: int, harga: int,
                 tanggal_tayang: str, jam_tayang: str, studio_bioskop: str,
                 koreografer_laga: str, tingkat_bahaya: str, jumlah_pemeran_pengganti: int):
        super().__init__(id_film, judul, genre, durasi, harga, tanggal_tayang, jam_tayang, studio_bioskop)
        self.__koreografer_laga: str = ""
        self.__tingkat_bahaya: str = ""        # contoh: Ringan, Sedang, Berat
        self.__jumlah_pemeran_pengganti: int = 0 # jumlah stuntman
        self.setKoreograferLaga(koreografer_laga) # inisialisasi
        self.setTingkatBahaya(tingkat_bahaya) # inisialisasi
        self.setJumlahPemeranPengganti(jumlah_pemeran_pengganti) # inisialisasi

    # getter
    def getKoreograferLaga(self) -> str:
        return self.__koreografer_laga # mengambil value

    def getTingkatBahaya(self) -> str:
        return self.__tingkat_bahaya # mengambil value

    def getJumlahPemeranPengganti(self) -> int:
        return self.__jumlah_pemeran_pengganti # mengambil value

    # setter
    def setKoreograferLaga(self, koreografer_laga: str) -> None:
        self.__koreografer_laga = koreografer_laga # inisialisasi

    def setTingkatBahaya(self, tingkat_bahaya: str) -> None:
        self.__tingkat_bahaya = tingkat_bahaya # inisialisasi

    def setJumlahPemeranPengganti(self, jumlah_pemeran_pengganti: int) -> None:
        if jumlah_pemeran_pengganti >= 0:
            self.__jumlah_pemeran_pengganti = jumlah_pemeran_pengganti # inisialisasi
        else:
            print("Jumlah pemeran pengganti tidak boleh negatif.")

    # prosedur menampilkan data, memanggil dulu tampilkanData() milik Film (inheritance, bukan override)
    def tampilkanDataAksi(self) -> None:
        self.tampilkanData() # pakai ulang method dari Film
        print("Tipe Film                : Film Aksi")
        print("Koreografer Laga         :", self.getKoreograferLaga())
        print("Tingkat Bahaya           :", self.getTingkatBahaya())
        print("Jumlah Pemeran Pengganti :", self.getJumlahPemeranPengganti(), "orang")
