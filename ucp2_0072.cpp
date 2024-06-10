#include <iostream>
#include <vector>
using namespace std;

class Karyawan;
class Proyek {
public:
    string namaproyek;
    vector<Karyawan*> daftar_karyawan;

    Proyek(string pNamaProyek) :namaproyek(pNamaProyek) {
        cout << "Proyek dibuat dengan nama : " << namaproyek << endl;
    }
    ~Proyek() {
        cout << "Proyek " << namaproyek << " dibubarkan." << endl;
    }

    void tambahKaryawan(Karyawan*);
    void cetakKaryawan();
};

class Karyawan {
public:
    string namakaryawan;
    vector<Proyek*> daftar_proyek;

    Karyawan(string pNamaKaryawan) :namakaryawan(pNamaKaryawan) {
        cout << "Karyawan direkrut dengan nama : " << namakaryawan << endl;
    }
    ~Karyawan() {
        cout << "Karyawan " << namakaryawan << " dipecat." << endl;
    }

    void tambahProyek(Proyek*);
    void cetakProyek();
};

class Perusahaan {
public:
    string namaperusahaan;
    vector<Karyawan*> daftar_karyawan;

    Perusahaan(string pNamaPerusahaan) :namaperusahaan (pNamaPerusahaan) {
        cout << "Perusahaan dibuat dengan nama : " << namaperusahaan << "\n";
    }
    ~Perusahaan() {
        cout << "Perusahaan " << namaperusahaan << "telah bangkrut.\n";
    }
    void tambahKaryawan(Karyawan*);
    void cetakKaryawan();
};



void Proyek::tambahKaryawan(Karyawan* pKaryawan) {
    daftar_karyawan.push_back(pKaryawan);
}
void Proyek::cetakKaryawan() {
    cout << "Daftar Karyawan Proyek " << this->namaproyek << " : " << endl;
    for (auto& a : daftar_karyawan) {
        cout << a->namakaryawan << endl;
    }
    cout << endl;
}

void Karyawan::tambahProyek(Proyek* pProyek) {
    daftar_proyek.push_back(pProyek);
}
void Karyawan::cetakProyek() {
    cout << "Daftar Proyek Karyawan " << this->namakaryawan << " : " << endl;
    for (auto& a : daftar_proyek) {
        cout << a->namaproyek << endl;
    }
    cout << endl;
}

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