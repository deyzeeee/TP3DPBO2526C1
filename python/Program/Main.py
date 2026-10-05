from typing import List
from FilmAnimasi import FilmAnimasi
from FilmAksi import FilmAksi
from FilmDokumenter import FilmDokumenter

# Array of Object: 3 list terpisah (satu per jenis film)
daftarAnimasi: List[FilmAnimasi] = []
daftarAksi: List[FilmAksi] = []
daftarDokumenter: List[FilmDokumenter] = []

# cek ID sudah dipakai atau belum, dicek ke ketiga list
def isIdExists(id_film: int) -> bool:
    ada = False # flag

    i = 0
    while i < len(daftarAnimasi) and not ada:
        if daftarAnimasi[i].getId() == id_film:
            ada = True
        i += 1

    i = 0
    while i < len(daftarAksi) and not ada:
        if daftarAksi[i].getId() == id_film:
            ada = True
        i += 1

    i = 0
    while i < len(daftarDokumenter) and not ada:
        if daftarDokumenter[i].getId() == id_film:
            ada = True
        i += 1

    return ada

# prosedur menampilkan seluruh data film secara lengkap (dipakai sebelum & sesudah tambah data)
def tampilkanSemuaData() -> None:
    if not daftarAnimasi and not daftarAksi and not daftarDokumenter:
        print("\nBelum ada data film.")
        return

    print("\n==================== DAFTAR FILM HOLO CINEMA ====================")

    print("\n-- Film Animasi --")
    for i, film in enumerate(daftarAnimasi):
        print(f"\n--- Film ke-{i + 1} ---")
        film.tampilkanDataAnimasi()

    print("\n-- Film Aksi --")
    for i, film in enumerate(daftarAksi):
        print(f"\n--- Film ke-{i + 1} ---")
        film.tampilkanDataAksi()

    print("\n-- Film Dokumenter --")
    for i, film in enumerate(daftarDokumenter):
        print(f"\n--- Film ke-{i + 1} ---")
        film.tampilkanDataDokumenter()

    print("===================================================================")

# prosedur menambah 1 film baru, user memilih dulu jenisnya
def tambahData() -> None:
    print("\nPilih jenis film:")
    print("1. Film Animasi")
    print("2. Film Aksi")
    print("3. Film Dokumenter")

    jenis = 0
    jenis_valid = False # flag validasi jenis
    while not jenis_valid:
        try:
            jenis = int(input("Pilihan jenis: "))
            if 1 <= jenis <= 3:
                jenis_valid = True
            else:
                print("Pilihan harus 1, 2, atau 3.")
        except ValueError:
            print("Input tidak valid. Masukkan angka.")

    # ---- atribut dasar Film (wajib untuk semua jenis) ----
    id_film = 0
    id_valid = False # flag validasi ID
    while not id_valid:
        try:
            id_film = int(input("ID Film: "))
            if not isIdExists(id_film):
                id_valid = True
            else:
                print("ID ini sudah ada. Silakan masukkan ID lain.")
        except ValueError:
            print("Input tidak valid. Masukkan angka.")

    judul = input("Judul Film: ")
    genre = input("Genre Film: ")

    durasi = 0
    durasi_valid = False # flag validasi durasi
    while not durasi_valid:
        try:
            durasi = int(input("Durasi (menit): "))
            if durasi < 0:
                print("Input tidak valid. Durasi tidak boleh negatif.")
            else:
                durasi_valid = True
        except ValueError:
            print("Input tidak valid. Masukkan angka.")

    harga = 0
    harga_valid = False # flag validasi harga
    while not harga_valid:
        try:
            harga = int(input("Harga Tiket (Rp): "))
            if harga <= 0:
                print("Input tidak valid. Harga harus lebih dari 0.")
            else:
                harga_valid = True
        except ValueError:
            print("Input tidak valid. Masukkan angka.")

    # ---- atribut JadwalTayang (composition, wajib untuk semua jenis) ----
    tanggal_tayang = input("Tanggal Tayang (contoh: 12-10-2026): ")
    jam_tayang = input("Jam Tayang (contoh: 19:30): ")
    studio_bioskop = input("Studio Bioskop (contoh: Studio 1): ")

    # ---- atribut tambahan sesuai jenis yang dipilih ----
    if jenis == 1:
        studio_animasi = input("Studio Animasi: ")
        rating_usia = input("Rating Usia (contoh: SU, 13+, 17+): ")

        frame_rate = 0
        fr_valid = False # flag validasi frame rate
        while not fr_valid:
            try:
                frame_rate = int(input("Frame Rate (fps): "))
                if frame_rate <= 0:
                    print("Input tidak valid. Frame rate harus lebih dari 0.")
                else:
                    fr_valid = True
            except ValueError:
                print("Input tidak valid. Masukkan angka.")

        daftarAnimasi.append(FilmAnimasi(id_film, judul, genre, durasi, harga,
                                          tanggal_tayang, jam_tayang, studio_bioskop,
                                          studio_animasi, rating_usia, frame_rate))
    elif jenis == 2:
        koreografer_laga = input("Koreografer Laga: ")
        tingkat_bahaya = input("Tingkat Bahaya (contoh: Ringan, Sedang, Berat): ")

        jumlah_stuntman = 0
        stunt_valid = False # flag validasi jumlah stuntman
        while not stunt_valid:
            try:
                jumlah_stuntman = int(input("Jumlah Pemeran Pengganti: "))
                if jumlah_stuntman < 0:
                    print("Input tidak valid. Tidak boleh negatif.")
                else:
                    stunt_valid = True
            except ValueError:
                print("Input tidak valid. Masukkan angka.")

        daftarAksi.append(FilmAksi(id_film, judul, genre, durasi, harga,
                                    tanggal_tayang, jam_tayang, studio_bioskop,
                                    koreografer_laga, tingkat_bahaya, jumlah_stuntman))
    else:
        sutradara_riset = input("Sutradara Riset: ")
        subjek_dokumenter = input("Subjek Dokumenter: ")

        jumlah_narasumber = 0
        ns_valid = False # flag validasi jumlah narasumber
        while not ns_valid:
            try:
                jumlah_narasumber = int(input("Jumlah Narasumber: "))
                if jumlah_narasumber < 0:
                    print("Input tidak valid. Tidak boleh negatif.")
                else:
                    ns_valid = True
            except ValueError:
                print("Input tidak valid. Masukkan angka.")

        daftarDokumenter.append(FilmDokumenter(id_film, judul, genre, durasi, harga,
                                                tanggal_tayang, jam_tayang, studio_bioskop,
                                                sutradara_riset, subjek_dokumenter, jumlah_narasumber))

    print("\nFilm berhasil ditambahkan!")

# main program
def main() -> None:
    # data awal (array of object, wajib ada sebelum input user)
    daftarAnimasi.append(FilmAnimasi(101, "Senja di Negeri Angin", "Slice of Life", 92, 38000,
                                      "05-10-2026", "16:00", "Studio 1",
                                      "Studio Awan", "SU", 24))
    daftarAnimasi.append(FilmAnimasi(102, "Petualangan Rimba", "Petualangan", 96, 40000,
                                      "05-10-2026", "19:00", "Studio 2",
                                      "Kagaya Studio", "SU", 24))
    daftarAksi.append(FilmAksi(201, "Garis Pertahanan", "Aksi", 118, 48000,
                                "05-10-2026", "20:30", "Studio 3",
                                "Andri Pratama", "Berat", 12))
    daftarAksi.append(FilmAksi(202, "Malam Pengejaran", "Aksi", 105, 45000,
                                "06-10-2026", "21:00", "Studio 1",
                                "Reza Saputra", "Sedang", 8))
    daftarDokumenter.append(FilmDokumenter(301, "Jejak Nusantara", "Dokumenter", 85, 35000,
                                            "06-10-2026", "15:00", "Studio 4",
                                            "Dian Kusuma", "Sejarah Rempah Indonesia", 6))

    print("\nDATA AWAL (SEBELUM PENAMBAHAN)")
    tampilkanSemuaData()

    pilihan = ""
    while pilihan != '3': # berhenti jika user memilih 3 (Keluar)
        print("\n=== MENU HOLO CINEMA ===")
        print("1. Tampilkan Semua Data Film")
        print("2. Tambah Film Baru")
        print("3. Keluar")
        pilihan = input("Pilih menu: ")

        if pilihan == '1':
            tampilkanSemuaData()
        elif pilihan == '2':
            tambahData()
        elif pilihan == '3':
            print("\nDATA AKHIR (SESUDAH PENAMBAHAN)")
            tampilkanSemuaData()
            print("\nTerima kasih sudah menggunakan sistem Holo Cinema!")
        else:
            print("Pilihan tidak valid. Coba lagi")

if __name__ == "__main__":
    main()
