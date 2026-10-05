from JadwalTayang import JadwalTayang

# kelas dasar (parent dari hierarchical inheritance: Film -> FilmAnimasi, FilmAksi, FilmDokumenter)
class Film:
    # constructor, sekaligus membuat objek JadwalTayang
    def __init__(self, id_film: int, judul: str, genre: str, durasi: int, harga: int,
                 tanggal_tayang: str, jam_tayang: str, studio_bioskop: str):
        self.__id_film: int = 0
        self.__judul: str = ""
        self.__genre: str = ""
        self.__durasi: int = 0  # dalam menit
        self.__harga: int = 0   # harga tiket dalam rupiah
        self.setId(id_film) # inisialisasi
        self.setJudul(judul) # inisialisasi
        self.setGenre(genre) # inisialisasi
        self.setDurasi(durasi) # inisialisasi
        self.setHarga(harga) # inisialisasi

        # composition: Film punya JadwalTayang
        self.__jadwal_tayang: JadwalTayang = JadwalTayang(tanggal_tayang, jam_tayang, studio_bioskop)

    # getter
    def getId(self) -> int:
        return self.__id_film # mengambil value

    def getJudul(self) -> str:
        return self.__judul # mengambil value

    def getGenre(self) -> str:
        return self.__genre # mengambil value

    def getDurasi(self) -> int:
        return self.__durasi # mengambil value

    def getHarga(self) -> int:
        return self.__harga # mengambil value

    def getJadwalTayang(self) -> JadwalTayang:
        return self.__jadwal_tayang # mengambil objek composition

    # setter
    def setId(self, id_film: int) -> None:
        self.__id_film = id_film # inisialisasi

    def setJudul(self, judul: str) -> None:
        self.__judul = judul # inisialisasi

    def setGenre(self, genre: str) -> None:
        self.__genre = genre # inisialisasi

    def setDurasi(self, durasi: int) -> None:
        if durasi >= 0:
            self.__durasi = durasi # inisialisasi
        else:
            print("Durasi tidak boleh negatif.")

    def setHarga(self, harga: int) -> None:
        if harga > 0:
            self.__harga = harga # inisialisasi
        else:
            print("Harga harus lebih dari 0.")

    # prosedur menampilkan data dasar (dipakai lagi oleh tiap kelas turunan)
    def tampilkanData(self) -> None:
        print("ID Film   :", self.getId())
        print("Judul     :", self.getJudul())
        print("Genre     :", self.getGenre())
        print("Durasi    :", self.getDurasi(), "menit")
        print("Harga     : Rp.", self.getHarga())
        self.getJadwalTayang().tampilkanJadwal()
