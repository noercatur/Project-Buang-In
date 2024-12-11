#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "User.h"
#include "Driver.h"
#include "PickupLocation.h"
#include "Admin.h"
#include "Member.h"
#include "Payment.h"

void mainmenu() {
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Selamat datang di Buang-In!" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Registrasi" << std::endl;
    std::cout << "3. Keluar" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Silakan masukkan pilihan Anda! (1/2/3)" << std::endl;
}

void registrasimenu(std::vector<User>& users) {
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Selamat Datang User Baru! Silakan buat akun!" << std::endl;
    std::string username, email, password;
    std::cout << "Username : ";
    std::cin >> username;
    std::cout << "Email    : ";
    std::cin >> email;
    std::cout << "Password : ";
    std::cin >> password;
    std::cout << std::string(40, '=') << std::endl;

    User newUser(username, email, password);
    users.push_back(newUser );

    std::cout << "Anda telah berhasil Registrasi! Silakan login" << std::endl;
}

void loginmenu(std::vector<User>& users, std::vector<Admin>& admins, User*& loggedInUser , Admin*& loggedInAdmin) {
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Selamat Datang di Laman Login!" << std::endl;
    std::cout << "1. Login sebagai User" << std::endl;
    std::cout << "2. Login sebagai Admin" << std::endl;
    std::cout << "3. Kembali" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Silakan masukkan pilihan Anda! (1/2/3)" << std::endl;

    int loginchoice;
    std::cin >> loginchoice;

    switch (loginchoice) {
        case 1: {
            std::string username, password;
            std::cout << "Masukkan Username : ";
            std::cin >> username;
            std::cout << "Masukkan Password : ";
            std::cin >> password;

            for (auto& user : users) {
                if (user.getUsername() == username && user.getPassword() == password) {
                    loggedInUser  = &user;
                    std::cout << "Anda berhasil Login!" << std::endl;
                    return;
                }
            }
            std::cout << "Login gagal! Periksa kembali Username dan Password anda!" << std::endl;
            break;
        }

        case 2: {
            std::string username, password;
            std::cout << "Masukkan Username : ";
            std::cin >> username;
            std::cout << "Masukkan Password : ";
            std::cin >> password;

            for (auto& admin : admins) {
                if (admin.getName() == username && admin.getPassword() == password) {
                    loggedInAdmin = &admin;
                    std::cout << "Anda berhasil Login!" << std::endl;
                    return;
                }
            }
            std::cout << "Login gagal! Periksa kembali Username dan Password anda!" << std::endl;
            break;
        }

        case 3:
            return;

        default:
            std::cout << "Pilihan anda tidak valid, silakan coba lagi!" << std::endl;
            break;
    }
}


void adminmenu(Admin* loggedInAdmin) {
    int choiceadmin;
    std::vector<Payment*> payments; 
    std::vector<Location> pickups;
    do{
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Selamat datang admin!" << std::endl; 
    std::cout << "1. Monitor Pembayaran" << std::endl;
    std::cout << "2. Monitor Penjemputan" << std::endl;
    std::cout << "3. Logout" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Silakan masukkan pilihan Anda! (1/2/3)" << std::endl;
    std::cin >> choiceadmin;

    switch (choiceadmin){
    

        case 1:
         loggedInAdmin->monitorPayment(payments);
                break;
        case 2:
                loggedInAdmin->monitorPickup(pickups);
                break;
        case 3:
                std::cout << "Anda telah logout" << std::endl;
                loggedInAdmin = nullptr; 
                break;
            default:
                std::cout << "Pilihan anda tidak valid, silakan coba lagi!" << std::endl;
                break;
        }
    } while (choiceadmin != 3);
}
    
    
    


void profilmenu(User& user) {
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Profil Anda" << std::endl;
    std::cout << "ID            : " << user.getID() << std::endl;
    std::cout << "Username      : " << user.getUsername() << std::endl;
    std::cout << "Email         : " << user.getEmail() << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    
    if (user.statusSubscription()) {
        std::cout << "Status Subscription: Aktif" << std::endl;
        std::cout << "Sisa Hari Subscription: " << user.getSisaHariSubscription() << " hari" << std::endl;
    } else {
        std::cout << "Status Subscription: Tidak Aktif" << std::endl;
    }

    std::cout << std::string(40, '=') << std::endl;
    std::cout << "1. Edit Profil" << std::endl;
    std::cout << "2. Kembali" << std::endl;
    std::cout << "Ketik 1 untuk edit profil, 2 untuk kembali ke menu sebelumnya" << std::endl;

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::string newUsername, newEmail, newPassword;
        std::cout << "Masukkan Username baru: ";
        std::cin >> newUsername;
        std::cout << "Masukkan Email baru: ";
        std::cin >> newEmail;
        std::cout << "Masukkan Password baru: ";
        std::cin >> newPassword;

        user.setUsername(newUsername);
        user.setEmail(newEmail);
        user.setPassword(newPassword);

        std::cout << "Profil Anda telah diperbarui!" << std::endl;
    } else if (choice == 2) {
        return; // Kembali ke usermenu
    } else {
        std::cout << "Pilihan tidak valid!" << std::endl;
    }
}

void processPayment(double amount, User* loggedInUser , PaymentType paymentType) {
    Payment payment;
    std::string paymentDate = payment.getCurrentDate();

    Payment* newPayment = new Payment(0, paymentDate, true, paymentType);

    loggedInUser ->addPayment(newPayment);

    if (paymentType == PaymentType::Subscription) {
        std::cout << "Pembayaran langganan berhasil!" << std::endl;
        std::cout << "Jumlah yang dibayar: Rp " << amount << std::endl;
        std::cout << "Jenis Pembayaran: Langganan" << std::endl;
        std::cout << "Terimakasih sudah berlangganan! :)" << std::endl;
    } else if (paymentType == PaymentType::Service) {
        std::cout << "Pembayaran jasa pengambilan sampah di alamat " << loggedInUser ->getPickupLocation().getFullAddress() << " berhasil!" << std::endl;
        std::cout << "Jumlah yang dibayar: Rp " << amount << std::endl;
        std::cout << "Jenis Pembayaran: Jasa Pengambilan Sampah" << std::endl;
        std::cout << "Terimakasih sudah menggunakan jasa kami! :)" << std::endl;
    }

    std::cout << "Tanggal Pembayaran: " << paymentDate << std::endl;
}

void jemputsampah(User* loggedInUser ) {
     
     if (loggedInUser ->getPickupLocation().getAddress().empty()) {
        std::cout << "Anda harus mengatur alamat penjemputan terlebih dahulu!" << std::endl;
        return;
    }
    
    double weight;
    std::cout << "Masukkan jumlah sampah dalam kg: ";
    std::cin >> weight;

    const double pricePerKg = 5000.0;
    double totalPrice = weight * pricePerKg;

    std::cout << "Jumlah sampah: " << weight << " kg" << std::endl;
    std::cout << "Biaya pengambilan sampah: Rp " << totalPrice << std::endl;

    char choice;
    std::cout << "Apakah Anda ingin membayar? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        processPayment(totalPrice, loggedInUser , PaymentType::Service);
    } else {
        std::cout << "Penjemputan dibatalkan." << std::endl;
    }
}

void jadimember(User* loggedInUser ) {
    int choicemember;
    double price = 0;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Silakan pilih plan untuk Subscription!" << std::endl;
    std::cout << "1. 7 hari (Rp25.000)" << std::endl;
    std::cout << "2. 14 hari (Rp45.000)" << std::endl;
    std::cout << "3. 28 hari (Rp.85.000)" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Silakan masukkan pilihan Anda! (1/2/3)" << std::endl;

    std::cin >> choicemember;

    switch (choicemember) {
        case 1:
            price = 25000;
            loggedInUser ->subscribe(7);
            std::cout << "Langganan 7 hari berhasil! Biaya: Rp 25.000" << std::endl;
            break;
        case 2:
            price = 45000; 
            loggedInUser ->subscribe(14);
            std::cout << "Langganan 14 hari berhasil! Biaya: Rp 45.000" << std::endl;
            break;
        case 3:
            price = 85000; 
            loggedInUser ->subscribe(28);
            std::cout << "Langganan 28 hari berhasil! Biaya: Rp 85.000" << std::endl;
            break;
        default:
            std::cout << "Pilihan anda tidak valid!" << std::endl;
            return;
    }

    char choicePay;
    std::cout << "Apakah Anda ingin melakukan pembayaran? (y/n): ";
    std::cin >> choicePay;

    if (choicePay == 'y' || choicePay == 'Y') {
        processPayment(price, loggedInUser , PaymentType::Subscription);
    } else {
        std::cout << "Langganan dibatalkan." << std::endl;
    }
}

void setalamat(User* loggedInUser ) {
    std::string address, city, postalCode;

    std::cout << "Masukkan alamat penjemputan: ";
    std::cin.ignore();
    std::getline(std::cin, address);

     std::cout << "Pilih Kota untuk alamat penjemputan:" << std::endl;
    std::cout << "1. Jogja" << std::endl;
    std::cout << "2. Bantul" << std::endl;
    std::cout << "3. Sleman" << std::endl;
    std::cout << "4. Gunungkidul" << std::endl;
    std::cout << "5. Kulonprogo" << std::endl;

    int cityChoice;
    std::cout << "Masukkan pilihan sesuai kota Anda! (1-5): ";
    std::cin >> cityChoice;

    switch (cityChoice) {
        case 1: city = "Jogja"; break;
        case 2: city = "Bantul"; break;
        case 3: city = "Sleman"; break;
        case 4: city = "Gunkid"; break;
        case 5: city = "Kulonprogo"; break;
        default: 
            std::cout << "Pilihan tidak valid, alamat tidak diubah." << std::endl;
            return;
    }


    std::cout << "Masukkan kode pos: ";
    std::cin >> postalCode;

    Location newLocation(address, city, postalCode);
    loggedInUser ->setPickupLocation(newLocation);

    std::cout << "Alamat penjemputan telah diatur ke: " << loggedInUser ->getPickupLocation().getFullAddress() << std::endl;
}

void usermenu(User* loggedInUser ) {
    int choiceuser;
    do {
        std::cout << std::string(40, '=') << std::endl;
        std::cout << "Selamat Datang, " << loggedInUser ->getUsername() << "!" << std::endl;
        std::cout << "1. Lihat profil" << std::endl;
        std::cout << "2. Jemput sampahku!" << std::endl;
        std::cout << "3. Jadi member" << std::endl;
        std::cout << "4. Set alamat penjemputan" << std::endl;
        std::cout << "5. Logout" << std::endl;
        std::cout << std::string(40, '=') << std::endl;
        std::cout << "Silakan masukkan pilihan Anda! (1-5)" << std::endl;
        std::cin >> choiceuser;

        switch (choiceuser) {
            case 1:
                profilmenu(*loggedInUser );
                break;
            case 2:
                jemputsampah(loggedInUser );
                break;
            case 3:
                jadimember(loggedInUser );
                break;
            case 4:
                setalamat(loggedInUser );
                break;
            case 5:
                std::cout << "Anda telah logout" << std::endl;
                loggedInUser  = nullptr;
                return;
            default:
                std::cout << "Pilihan tidak valid!" << std::endl;
                break;
        }
    }  while (true);
      
    
}


int main() {
    std::vector<User> users;
    std::vector<Admin> admins;
    std::vector<Driver> drivers;
    std::vector<Payment> payments;
    User* loggedinUser  = nullptr;
    Admin* loggedinAdmin = nullptr;
    bool running = true;

    std::srand(static_cast<unsigned int>(std::time(0)));

    admins.push_back(Admin(123,"Kurfato", "Buangin@gmail.com", "FokusIPK4"));

    while (running) {
        int choice;
        mainmenu();
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                loginmenu(users, admins, loggedinUser , loggedinAdmin);
                if (loggedinUser ) {
                    usermenu(loggedinUser );
                    loggedinUser  = nullptr;
                } else if (loggedinAdmin) {
                    adminmenu(loggedinAdmin);
                    loggedinAdmin = nullptr;
                }
                break;

            case 2:
                registrasimenu(users);
                break;

            case 3:
                std::cout << std::string(40, '+') << std::endl;
                std::cout << "Terimakasih telah menggunakan Buang-In!" <<std::endl;
                std::cout << "Kami tunggu kehadiranmu selanjutnya! :)" << std::endl;
                std::cout << std::string(40, '+') << std::endl;
                return 0;

            default:
                std::cout << "Pilihan tidak valid!" << std::endl;
                break;
        }
    }
}