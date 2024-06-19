/*! \mainpage Sistem Manajemen Karyawan dan Proyek
 *
 * \section intro_sec Pengantar
 * Selamat datang di dokumentasi Sistem Manajemen Karyawan dan Proyek.
 * Sistem ini dirancang untuk mengelola karyawan dan proyek yang ada di perusahaan
 * 
 * \section structure _sec Struktur Kode
 * Kode ini terdiri dari dua kelas utama:
 * - \b Karyawan: Menangani informasi tentang karyawan dan proyek yang mereka ikuti.
 * - \b Proyek: Menangani informasi tentang proyek dan karyawan yang terlibat di dalamnya.
 * 
 * \section setup_sec Setup dan Konfigurasi
 * Untuk menjalankan sistem ini, pastikan Anda memiliki compiler yang mendukung standar C++11 atau lebih tinggi.
 * Kompilasi dan jalankan file ini menggunakan compiler pilihan Anda.
 * 
 * \section author_sec Tentang Pengembang
 * Sistem ini dikembangkan oleh Chesta Yurcel Zebada sebagai bagian dari inisiatif untuk meningkatkan manajemen sumber daya dalam perusahaan.
 * 
 * \section note_sec Catatan
 * Dokumentasi ini dihasilkan menggunakan Doxygen. Pastikan untuk mengikuti komentar yang disediakan dalam kode untuk pemahaman yang lebih baik.
 */

/**
 * @file main.cpp
 * @brief Sistem manajemen karyawan dan proyek untuk perusahaan.
 * @version 0.1
 * @date 2024-06-19
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @class Proyek
 * @brief Kelas untuk menangani informasi tentang proyek dan karyawan yang terlibat.
 */
class Proyek {
public:
    string namaproyek; ///< Nama dari proyek.
    vector<Karyawan*> daftar_karyawan; ///< Daftar karyawan yang terlibat dalam proyek.

    /**
     * @brief Konstruktor untuk kelas Proyek.
     * @param pNamaProyek Nama proyek yang dibuat.
     */
    Proyek(string pNamaProyek) :namaproyek(pNamaProyek) {
        cout << "Proyek dibuat dengan nama : " << namaproyek << endl;
    }
    ~Proyek() {
        cout << "Proyek " << namaproyek << " dibubarkan." << endl;
    }
    /**
     * @brief Menambahkan karyawan ke dalam daftar proyek.
     * @param Karyawan Pointer ke objek Karyawan yang akan ditambahkan.
     */
    void tambahKaryawan(Karyawan*);
    /**
     * @brief Mencetak daftar karyawan yang terlibat dalam proyek.
     */
    void cetakKaryawan();
};

/**
 * @class Karyawan
 * @brief Kelas untuk menangani informasi karyawan dan proyek yang diikuti.
 */
class Karyawan {
public:
    string namakaryawan; ///< Nama dari karyawan.
    vector<Proyek*> daftar_proyek; ///< Daftar proyek yang diikuti karyawan.

    /**
     * @brief Konstruktor untuk kelas Karyawan.
     * @param pNamaKaryawan Nama karyawan yang dibuat.
     */
    Karyawan(string pNamaKaryawan) :namakaryawan(pNamaKaryawan) {
        cout << "Karyawan direkrut dengan nama : " << namakaryawan << endl;
    }
    ~Karyawan() {
        cout << "Karyawan " << namakaryawan << " dipecat." << endl;
    }
    /**
     * @brief Menambahkan proyek ke dalam daftar proyek karyawan.
     * @param Proyek Pointer ke objek Proyek yang akan ditambahkan.
     */
    void tambahProyek(Proyek*);
    /**
     * @brief Mencetak daftar proyek yang diikuti oleh karyawan.
     * 
     */
    void cetakProyek();
};

/**
 * @brief Menambahkan karyawan ke dalam proyek.
 * @param pKaryawan Pointer ke objek Karyawan yang akan ditambahkan.
 */
void Proyek::tambahKaryawan(Karyawan* pKaryawan) {
    daftar_karyawan.push_back(pKaryawan);
}
/**
 * @brief Mencetak daftar karyawan yang terlibat dalam proyek.
 */
void Proyek::cetakKaryawan() {
    cout << "Daftar Karyawan Proyek " << this->namaproyek << " : " << endl;
    for (auto& a : daftar_karyawan) {
        cout << a->namakaryawan << endl;
    }
    cout << endl;
}

/**
 * @brief Menambahkan proyek ke dalam daftar proyek karyawan.
 * @param pProyek Pointer ke objek Proyek yang akan ditambahkan.
 */
void Karyawan::tambahProyek(Proyek* pProyek) {
    daftar_proyek.push_back(pProyek);
}
/**
 * @brief Mencetak daftar proyek yang diikuti oleh karyawan.
 */
void Karyawan::cetakProyek() {
    cout << "Daftar Proyek Karyawan " << this->namakaryawan << " : " << endl;
    for (auto& a : daftar_proyek) {
        cout << a->namaproyek << endl;
    }
    cout << endl;
}

/**
 * @brief Fungsi utama program.
 * Fungsi ini membuat beberapa objek Proyek dan Karyawan, menambahkan karyawan ke proyek,
 * menambahkan proyek ke karyawan, mencetak daftar karyawan untuk setiap proyek, mencetak daftar proyek untuk setiap karyawan, 
 * dan menghapus semua objek yang telah dibuat.
 * @return int Kode status eksekusi program.
 */
int main() {
    Proyek* varProyek1 = new Proyek("Sistem Informasi");
    Proyek* varProyek2 = new Proyek("Sistem Keamanan");
    Proyek* varProyek3 = new Proyek("Konstruksi Bangunan");
    Karyawan* varKaryawan1 = new Karyawan("Budi");
    Karyawan* varKaryawan2 = new Karyawan("Andi");
    Karyawan* varKaryawan3 = new Karyawan("Chesta Yurcel");

    varProyek1->tambahKaryawan(varKaryawan1);
    varProyek1->tambahKaryawan(varKaryawan2);
    varProyek2->tambahKaryawan(varKaryawan1);
    varProyek3->tambahKaryawan(varKaryawan3);

    varKaryawan1->tambahProyek(varProyek1);
    varKaryawan1->tambahProyek(varProyek2);
    varKaryawan2->tambahProyek(varProyek1);
    varKaryawan3->tambahProyek(varProyek3);

    varProyek1->cetakKaryawan();
    varProyek2->cetakKaryawan();
    varKaryawan1->cetakProyek();
    varKaryawan2->cetakProyek();
    varProyek3->cetakKaryawan();
    varKaryawan3->cetakProyek();

    delete varProyek1;
    delete varProyek2;
    delete varKaryawan1;
    delete varKaryawan2;
    delete varProyek3;
    delete varKaryawan3;
}