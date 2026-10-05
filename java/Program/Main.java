import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    // Array of Object: 3 ArrayList terpisah (satu per jenis film)
    private static ArrayList<FilmAnimasi> daftarAnimasi = new ArrayList<>();
    private static ArrayList<FilmAksi> daftarAksi = new ArrayList<>();
    private static ArrayList<FilmDokumenter> daftarDokumenter = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    // cek ID sudah dipakai atau belum, dicek ke ketiga ArrayList
    private static boolean isIdExists(int id_film) {
        boolean ada = false; // flag
        int i = 0; // index

        i = 0;
        while (i < daftarAnimasi.size() && !ada) {
            if (daftarAnimasi.get(i).getId() == id_film) {
                ada = true;
            }
            i++;
        }

        i = 0;
        while (i < daftarAksi.size() && !ada) {
            if (daftarAksi.get(i).getId() == id_film) {
                ada = true;
            }
            i++;
        }

        i = 0;
        while (i < daftarDokumenter.size() && !ada) {
            if (daftarDokumenter.get(i).getId() == id_film) {
                ada = true;
            }
            i++;
        }

        return ada;
    }

    // prosedur menampilkan seluruh data film secara lengkap (dipakai sebelum & sesudah tambah data)
    private static void tampilkanSemuaData() {
        if (daftarAnimasi.isEmpty() && daftarAksi.isEmpty() && daftarDokumenter.isEmpty()) {
            System.out.println("\nBelum ada data film.");
            return;
        }

        System.out.println("\n==================== DAFTAR FILM HOLO CINEMA ====================");

        System.out.println("\n-- Film Animasi --");
        for (int i = 0; i < daftarAnimasi.size(); i++) {
            System.out.println("\n--- Film ke-" + (i + 1) + " ---");
            daftarAnimasi.get(i).tampilkanDataAnimasi();
        }

        System.out.println("\n-- Film Aksi --");
        for (int i = 0; i < daftarAksi.size(); i++) {
            System.out.println("\n--- Film ke-" + (i + 1) + " ---");
            daftarAksi.get(i).tampilkanDataAksi();
        }

        System.out.println("\n-- Film Dokumenter --");
        for (int i = 0; i < daftarDokumenter.size(); i++) {
            System.out.println("\n--- Film ke-" + (i + 1) + " ---");
            daftarDokumenter.get(i).tampilkanDataDokumenter();
        }

        System.out.println("===================================================================");
    }

    // prosedur menambah 1 film baru, user memilih dulu jenisnya
    private static void tambahData() {
        System.out.println("\nPilih jenis film:");
        System.out.println("1. Film Animasi");
        System.out.println("2. Film Aksi");
        System.out.println("3. Film Dokumenter");

        int jenis = 0;
        boolean jenisValid = false; // flag validasi jenis
        while (!jenisValid) {
            try {
                System.out.print("Pilihan jenis: ");
                jenis = Integer.parseInt(scanner.nextLine());
                if (jenis >= 1 && jenis <= 3) {
                    jenisValid = true;
                } else {
                    System.out.println("Pilihan harus 1, 2, atau 3.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Input tidak valid. Masukkan angka.");
            }
        }

        // ---- atribut dasar Film (wajib untuk semua jenis) ----
        int id_film = 0;
        boolean idValid = false; // flag validasi ID
        while (!idValid) {
            try {
                System.out.print("ID Film: ");
                id_film = Integer.parseInt(scanner.nextLine());
                if (!isIdExists(id_film)) {
                    idValid = true;
                } else {
                    System.out.println("ID ini sudah ada. Silakan masukkan ID lain.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Input tidak valid. Masukkan angka.");
            }
        }

        System.out.print("Judul Film: ");
        String judul = scanner.nextLine();

        System.out.print("Genre Film: ");
        String genre = scanner.nextLine();

        int durasi = 0;
        boolean durasiValid = false; // flag validasi durasi
        while (!durasiValid) {
            try {
                System.out.print("Durasi (menit): ");
                durasi = Integer.parseInt(scanner.nextLine());
                if (durasi < 0) {
                    System.out.println("Input tidak valid. Durasi tidak boleh negatif.");
                } else {
                    durasiValid = true;
                }
            } catch (NumberFormatException e) {
                System.out.println("Input tidak valid. Masukkan angka.");
            }
        }

        int harga = 0;
        boolean hargaValid = false; // flag validasi harga
        while (!hargaValid) {
            try {
                System.out.print("Harga Tiket (Rp): ");
                harga = Integer.parseInt(scanner.nextLine());
                if (harga <= 0) {
                    System.out.println("Input tidak valid. Harga harus lebih dari 0.");
                } else {
                    hargaValid = true;
                }
            } catch (NumberFormatException e) {
                System.out.println("Input tidak valid. Masukkan angka.");
            }
        }

        // ---- atribut JadwalTayang (composition, wajib untuk semua jenis) ----
        System.out.print("Tanggal Tayang (contoh: 12-10-2026): ");
        String tanggal_tayang = scanner.nextLine();
        System.out.print("Jam Tayang (contoh: 19:30): ");
        String jam_tayang = scanner.nextLine();
        System.out.print("Studio Bioskop (contoh: Studio 1): ");
        String studio_bioskop = scanner.nextLine();

        // ---- atribut tambahan sesuai jenis yang dipilih ----
        if (jenis == 1) {
            System.out.print("Studio Animasi: ");
            String studio_animasi = scanner.nextLine();
            System.out.print("Rating Usia (contoh: SU, 13+, 17+): ");
            String rating_usia = scanner.nextLine();

            int frame_rate = 0;
            boolean frValid = false; // flag validasi frame rate
            while (!frValid) {
                try {
                    System.out.print("Frame Rate (fps): ");
                    frame_rate = Integer.parseInt(scanner.nextLine());
                    if (frame_rate <= 0) {
                        System.out.println("Input tidak valid. Frame rate harus lebih dari 0.");
                    } else {
                        frValid = true;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Input tidak valid. Masukkan angka.");
                }
            }

            daftarAnimasi.add(new FilmAnimasi(id_film, judul, genre, durasi, harga,
                    tanggal_tayang, jam_tayang, studio_bioskop,
                    studio_animasi, rating_usia, frame_rate));
        } else if (jenis == 2) {
            System.out.print("Koreografer Laga: ");
            String koreografer_laga = scanner.nextLine();
            System.out.print("Tingkat Bahaya (contoh: Ringan, Sedang, Berat): ");
            String tingkat_bahaya = scanner.nextLine();

            int jumlahStuntman = 0;
            boolean stuntValid = false; // flag validasi jumlah stuntman
            while (!stuntValid) {
                try {
                    System.out.print("Jumlah Pemeran Pengganti: ");
                    jumlahStuntman = Integer.parseInt(scanner.nextLine());
                    if (jumlahStuntman < 0) {
                        System.out.println("Input tidak valid. Tidak boleh negatif.");
                    } else {
                        stuntValid = true;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Input tidak valid. Masukkan angka.");
                }
            }

            daftarAksi.add(new FilmAksi(id_film, judul, genre, durasi, harga,
                    tanggal_tayang, jam_tayang, studio_bioskop,
                    koreografer_laga, tingkat_bahaya, jumlahStuntman));
        } else {
            System.out.print("Sutradara Riset: ");
            String sutradara_riset = scanner.nextLine();
            System.out.print("Subjek Dokumenter: ");
            String subjek_dokumenter = scanner.nextLine();

            int jumlahNarasumber = 0;
            boolean nsValid = false; // flag validasi jumlah narasumber
            while (!nsValid) {
                try {
                    System.out.print("Jumlah Narasumber: ");
                    jumlahNarasumber = Integer.parseInt(scanner.nextLine());
                    if (jumlahNarasumber < 0) {
                        System.out.println("Input tidak valid. Tidak boleh negatif.");
                    } else {
                        nsValid = true;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Input tidak valid. Masukkan angka.");
                }
            }

            daftarDokumenter.add(new FilmDokumenter(id_film, judul, genre, durasi, harga,
                    tanggal_tayang, jam_tayang, studio_bioskop,
                    sutradara_riset, subjek_dokumenter, jumlahNarasumber));
        }

        System.out.println("\nFilm berhasil ditambahkan!");
    }

    public static void main(String[] args) {
        // data awal (array of object, wajib ada sebelum input user)
        daftarAnimasi.add(new FilmAnimasi(101, "Senja di Negeri Angin", "Slice of Life", 92, 38000,
                "05-10-2026", "16:00", "Studio 1",
                "Studio Awan", "SU", 24));
        daftarAnimasi.add(new FilmAnimasi(102, "Petualangan Rimba", "Petualangan", 96, 40000,
                "05-10-2026", "19:00", "Studio 2",
                "Kagaya Studio", "SU", 24));
        daftarAksi.add(new FilmAksi(201, "Garis Pertahanan", "Aksi", 118, 48000,
                "05-10-2026", "20:30", "Studio 3",
                "Andri Pratama", "Berat", 12));
        daftarAksi.add(new FilmAksi(202, "Malam Pengejaran", "Aksi", 105, 45000,
                "06-10-2026", "21:00", "Studio 1",
                "Reza Saputra", "Sedang", 8));
        daftarDokumenter.add(new FilmDokumenter(301, "Jejak Nusantara", "Dokumenter", 85, 35000,
                "06-10-2026", "15:00", "Studio 4",
                "Dian Kusuma", "Sejarah Rempah Indonesia", 6));

        System.out.println("\nDATA AWAL (SEBELUM PENAMBAHAN)");
        tampilkanSemuaData();

        String pilihan = "";
        while (!pilihan.equals("3")) { // berhenti jika user memilih 3 (Keluar)
            System.out.println("\n=== MENU HOLO CINEMA ===");
            System.out.println("1. Tampilkan Semua Data Film");
            System.out.println("2. Tambah Film Baru");
            System.out.println("3. Keluar");
            System.out.print("Pilih menu: ");
            pilihan = scanner.nextLine();

            if (pilihan.equals("1")) {
                tampilkanSemuaData();
            } else if (pilihan.equals("2")) {
                tambahData();
            } else if (pilihan.equals("3")) {
                System.out.println("\nDATA AKHIR (SESUDAH PENAMBAHAN)");
                tampilkanSemuaData();
                System.out.println("\nTerima kasih sudah menggunakan sistem Holo Cinema!");
            } else {
                System.out.println("Pilihan tidak valid. Coba lagi");
            }
        }
    }
}
