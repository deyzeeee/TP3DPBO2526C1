# kelas mandiri, dipakai lewat composition oleh Film (1 jadwal cuma milik 1 film)
class JadwalTayang:
    # constructor
    def __init__(self, tanggal_tayang: str, jam_tayang: str, studio_bioskop: str):
        self.__tanggal_tayang: str = ""
        self.__jam_tayang: str = ""
        self.__studio_bioskop: str = ""
        self.setTanggalTayang(tanggal_tayang) # inisialisasi
        self.setJamTayang(jam_tayang) # inisialisasi
        self.setStudioBioskop(studio_bioskop) # inisialisasi

    # getter
    def getTanggalTayang(self) -> str:
        return self.__tanggal_tayang # mengambil value

    def getJamTayang(self) -> str:
        return self.__jam_tayang # mengambil value

    def getStudioBioskop(self) -> str:
        return self.__studio_bioskop # mengambil value

    # setter
    def setTanggalTayang(self, tanggal_tayang: str) -> None:
        self.__tanggal_tayang = tanggal_tayang # inisialisasi

    def setJamTayang(self, jam_tayang: str) -> None:
        self.__jam_tayang = jam_tayang # inisialisasi

    def setStudioBioskop(self, studio_bioskop: str) -> None:
        self.__studio_bioskop = studio_bioskop # inisialisasi

    # prosedur untuk menampilkan jadwal
    def tampilkanJadwal(self) -> None:
        print(f"Jadwal Tayang : {self.getTanggalTayang()}, {self.getJamTayang()} ({self.getStudioBioskop()})")
