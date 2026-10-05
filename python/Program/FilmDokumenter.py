from Film import Film

# kelas turunan ke-3 (Hierarchical Inheritance: Film -> FilmDokumenter, sejajar dengan FilmAnimasi & FilmAksi)
class FilmDokumenter(Film):
    # constructor, memanggil constructor Film (termasuk membangun JadwalTayang)
    def __init__(self, id_film: int, judul: str, genre: str, durasi: int, harga: int,
                 tanggal_tayang: str, jam_tayang: str, studio_bioskop: str,
                 sutradara_riset: str, subjek_dokumenter: str, jumlah_narasumber: int):
        super().__init__(id_film, judul, genre, durasi, harga, tanggal_tayang, jam_tayang, studio_bioskop)
        self.__sutradara_riset: str = ""   # penanggung jawab riset/investigasi
        self.__subjek_dokumenter: str = "" # topik yang diangkat
        self.__jumlah_narasumber: int = 0
        self.setSutradaraRiset(sutradara_riset) # inisialisasi
        self.setSubjekDokumenter(subjek_dokumenter) # inisialisasi
        self.setJumlahNarasumber(jumlah_narasumber) # inisialisasi

    # getter
    def getSutradaraRiset(self) -> str:
        return self.__sutradara_riset # mengambil value

    def getSubjekDokumenter(self) -> str:
        return self.__subjek_dokumenter # mengambil value

    def getJumlahNarasumber(self) -> int:
        return self.__jumlah_narasumber # mengambil value

    # setter
    def setSutradaraRiset(self, sutradara_riset: str) -> None:
        self.__sutradara_riset = sutradara_riset # inisialisasi

    def setSubjekDokumenter(self, subjek_dokumenter: str) -> None:
        self.__subjek_dokumenter = subjek_dokumenter # inisialisasi

    def setJumlahNarasumber(self, jumlah_narasumber: int) -> None:
        if jumlah_narasumber >= 0:
            self.__jumlah_narasumber = jumlah_narasumber # inisialisasi
        else:
            print("Jumlah narasumber tidak boleh negatif.")

    # prosedur menampilkan data, memanggil dulu tampilkanData() milik Film (inheritance, bukan override)
    def tampilkanDataDokumenter(self) -> None:
        self.tampilkanData() # pakai ulang method dari Film
        print("Tipe Film         : Film Dokumenter")
        print("Sutradara Riset   :", self.getSutradaraRiset())
        print("Subjek Dokumenter :", self.getSubjekDokumenter())
        print("Jumlah Narasumber :", self.getJumlahNarasumber(), "orang")
