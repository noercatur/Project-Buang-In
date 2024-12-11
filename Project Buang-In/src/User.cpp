#include "User.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ostream>

User ::User (const std::string& username, const std::string& email, const std::string& password)
    : username(username), email(email), password(password), statusLogin(false), pickupLocation("","","") {
    ID = generateRandomID(); 
    }
int User::generateRandomID() {
    std::srand(std::time(nullptr));
    return std::rand() % 900000 + 100000; 
}

int User::getID() const {
    return ID; 
}

std::string User::getUsername() const {
    return username; 
}

std::string User::getEmail() const {
    return email; 
}

std::string User::getPassword() const { 
    return password; 
}

bool User::getStatusLogin() const { 
    return statusLogin; 
}

void User::setUsername(const std::string& newUsername) {
    username = newUsername;
}

void User::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}

bool User::login(const std::string& username, const std::string& password) {
    if (this->username == username && this->password == password) {
        statusLogin = true;
        return true;
    }
    return false;
}

void User::registrasi(const std::string& newUsername, const std::string& newEmail, const std::string& newPassword) {
    
    if (newUsername.empty() || newEmail.empty() || newPassword.empty()) {
        std::cout << "Registrasi gagal: Username, email, dan password tidak boleh kosong." << std::endl;
        return; 
    }
    username = newUsername;
    email = newEmail;
    password = newPassword;
    ID = generateRandomID(); 
    statusLogin = true; 
    std::cout << "Registrasi berhasil! Selamat datang, " << username << "!" << std::endl; 
}

void User::logout() {
    statusLogin = false; 
}

bool User::statusSubscription() const { 
    return member.getstatusSubscription(); 
}

void User::subscribe(int durasiHari) {
    member.startSubscription(durasiHari); 
}

void User::cancelSubscription() {
    member.cancelSubscription(); 
}

int User::getSisaHariSubscription() const { 
    return member.getsisaHariSubscription(); 
}

void User::setPickupLocation(const Location& location) { 
    pickupLocation = location; 
}

Location User::getPickupLocation() const { 
    return pickupLocation; 
}

void User::addPayment(Payment* payment) {
    payments.push_back(payment); 
}