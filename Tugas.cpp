#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Struktur untuk menyimpan data paket kursus
struct Course {
    string package_name;
    string type; // Privat atau Kelas
    int meetings;
    int session_duration; // Dalam menit
    double price_per_meeting;
    int registered_students;
    string payment_status;
};

// Vector untuk menyimpan semua paket kursus
vector<Course> courses;

// === Commit 1: Struktur dasar dan input data paket kursus ===
void addCourse() {
    Course newCourse;
    cout << "\nMasukkan nama paket kursus: ";
    cin.ignore();
    getline(cin, newCourse.package_name);
    cout << "Pilih tipe paket (1: Privat, 2: Kelas): ";
    int typeChoice;
    cin >> typeChoice;
    newCourse.type = (typeChoice == 1) ? "Privat" : "Kelas";
    cout << "Masukkan jumlah pertemuan: ";
    cin >> newCourse.meetings;
    cout << "Masukkan durasi per sesi (menit): ";
    cin >> newCourse.session_duration;
    cout << "Masukkan harga per pertemuan: ";
    cin >> newCourse.price_per_meeting;
    newCourse.registered_students = 0;
    newCourse.payment_status = "Belum Dibayar";
    courses.push_back(newCourse);
    cout << "Paket kursus berhasil ditambahkan!\n";
}

// === Commit 2: Fungsi tampilkan daftar paket kursus ===
void displayCourses() {
    if (courses.empty()) {
        cout << "\nTidak ada paket kursus!\n";
        return;
    }
    cout << "\nDaftar Paket Kursus:\n";
    cout << setw(20) << left << "Nama Paket" 
         << setw(10) << "Tipe" 
         << setw(15) << "Pertemuan" 
         << setw(15) << "Durasi (mnt)" 
         << setw(15) << "Harga/Pertemuan" << endl;
    cout << string(75, '-') << endl;
    for (const auto& course : courses) {
        cout << setw(20) << left << course.package_name 
             << setw(10) << course.type 
             << setw(15) << course.meetings 
             << setw(15) << course.session_duration 
             << setw(15) << course.price_per_meeting << endl;
    }
}
