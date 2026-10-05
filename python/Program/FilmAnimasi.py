from Film import Film

# kelas turunan ke-1 (Hierarchical Inheritance: Film -> FilmAnimasi, sejajar dengan FilmAksi & FilmDokumenter)
class FilmAnimasi(Film):
    # constructor, memanggil constructor Film (termasuk membangun JadwalTayang)
    def __init__(self, id_film: int, judul: str, genre: str, durasi: int, harga: int,
                 tanggal_tayang: str, jam_tayang: str, studio_bioskop: str,
                 studio_animasi: str, rating_usia: str, frame_rate: int):
        super().__init__(id_film, judul, genre, durasi, harga, tanggal_tayang, jam_tayang, studio_bioskop)
        self.__studio_animasi: str = ""
        self.__rating_usia: str = ""  # contoh: SU, 13+, 17+
        self.__frame_rate: int = 0    # dalam fps
        self.setStudioAnimasi(studio_animasi) # inisialisasi
        self.setRatingUsia(rating_usia) # inisialisasi
        self.setFrameRate(frame_rate) # inisialisasi

    # getter
    def getStudioAnimasi(self) -> str:
        return self.__studio_animasi # mengambil value

    def getRatingUsia(self) -> str:
        return self.__rating_usia # mengambil value

    def getFrameRate(self) -> int:
        return self.__frame_rate # mengambil value

    # setter
    def setStudioAnimasi(self, studio_animasi: str) -> None:
        self.__studio_animasi = studio_animasi # inisialisasi

    def setRatingUsia(self, rating_usia: str) -> None:
        self.__rating_usia = rating_usia # inisialisasi

    def setFrameRate(self, frame_rate: int) -> None:
        if frame_rate > 0:
            self.__frame_rate = frame_rate # inisialisasi
        else:
            print("Frame rate harus lebih dari 0.")

    # prosedur menampilkan data, memanggil dulu tampilkanData() milik Film (inheritance, bukan override)
    def tampilkanDataAnimasi(self) -> None:
        self.tampilkanData() # pakai ulang method dari Film
        print("Tipe Film      : Film Animasi")
        print("Studio Animasi :", self.getStudioAnimasi())
        print("Rating Usia    :", self.getRatingUsia())
        print("Frame Rate     :", self.getFrameRate(), "fps")
