#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk menghitung IMT
double hitungIMT(double berat, double tinggi) {
    return berat / ((tinggi / 100) * (tinggi / 100));
}

// Fungsi untuk mengkategorikan IMT
string kategoriIMT(double imt) {
    if (imt < 18.5) {
        return "Underweight";
    } else if (imt >= 18.5 && imt < 24.9) {
        return "Normal";
    } else if (imt >= 25.0 && imt < 29.9) {
        return "Overweight";
    } else {
        return "Obesitas";
    }
}

// Fungsi untuk menghitung BMR
double hitungBMR(double berat, double tinggi, int usia, string gender) {
    if (gender == "pria") {
        return 88.362 + (13.397 * berat) + (4.799 * tinggi) - (5.677 * usia);
    } else if (gender == "wanita") {
        return 447.593 + (9.247 * berat) + (3.098 * tinggi) - (4.330 * usia);
    } else {
        cout << "Jenis kelamin tidak valid!" << endl;
        return 0;
    }
}

// Fungsi untuk menghitung TDEE berdasarkan aktivitas
double hitungTDEE(double bmr, int aktivitas) {
    switch (aktivitas) {
        case 1: return bmr * 1.2;    // Tidak aktif
        case 2: return bmr * 1.375;  // Aktivitas ringan
        case 3: return bmr * 1.55;   // Aktivitas sedang
        case 4: return bmr * 1.725;  // Aktivitas berat
        case 5: return bmr * 1.9;    // Sangat berat
        default:
            cout << "Pilihan aktivitas tidak valid!" << endl;
            return 0;
    }
}
// Fungsi untuk menghitung konsumsi gula harian maksimal
double hitungGulaMaksimal(double tdee) {
    return (tdee * 0.10) / 4; // 1 gram gula = 4 kkal
}
    
int main() {
    double berat, tinggi;
    int usia, aktivitas;
    string gender;

    cout << "Body Vibe" << endl;
    cout << "Masukkan berat badan (kg): ";
    cin >> berat;
    cout << "Masukkan tinggi badan (cm): ";
    cin >> tinggi;
    cout << "Masukkan usia: ";
    cin >> usia;
    cout << "Masukkan jenis kelamin (pria/wanita): ";
    cin >> gender;
    cout << "Pilih tingkat aktivitas:\n";
    cout << "1. Tidak aktif\n2. Aktivitas ringan (contoh : jalan, melakukan pekerjaan rumah, bersepada, yoga, berkebun)\n3. Aktivitas sedang (contoh : jogging, berenang, aerobik)\n4. Aktivitas berat (contoh : naik gunung, sepak bola, angkat beban)\n5. Sangat berat\n";
    cout << "Pilihan Anda: ";
    cin >> aktivitas;

    double imt = hitungIMT(berat, tinggi);
    double bmr = hitungBMR(berat, tinggi, usia, gender);
    double tdee = hitungTDEE(bmr, aktivitas);
    double gulaMaksimal = hitungGulaMaksimal(tdee);
    string kategori = kategoriIMT(imt);

    cout << "\nHasil:\n";
    cout << "IMT Anda: " << imt << " (" << kategori << ")" << endl;
    cout << "BMR Anda: " << bmr << " kkal" << endl;
    cout << "Kebutuhan kalori harian (TDEE): " << tdee << " kkal" << endl;
    cout << "Konsumsi gula harian maksimal: " << gulaMaksimal << " gram" << endl;

    return 0;
}
