#include "Admin.h"
#include <iostream>

Admin::Admin(int ID, const std::string& name, const std::string& email, const std::string& password)
: ID(ID), name(name), email(email), password(password) {}

int Admin::getID() const {
    return ID;
}

std::string Admin::getName() const {
    return name;
}

std::string Admin::getEmail() const {
    return email;
}

std::string Admin::getPassword() const {
    return password;
}

void Admin::setID(int newID) {
    ID = newID;
}

void Admin::setName(const std::string& newName) {
    name = newName;
}

void Admin::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void Admin::setPassword(const std::string& newPassword) {
    password = newPassword;
}

void Admin::monitorPickup(const std::vector<Location>& pickups) const {
    std::cout << "Monitoring Pickups:" << std::endl;
    for (const auto& pickup : pickups) {
        std::cout << "- " << pickup << std::endl;
    }
}

void Admin::addPayment(const Payment& payment) {
    payments.push_back(payment);
}

void Admin::addPickup(const std::string& pickup) {
    pickups.push_back(pickup);
}

void Admin::monitorPayment(const std::vector<Payment*>& payments) const {
    std::cout << "=== Monitoring Pembayaran ===" << std::endl;
    for (const auto& payment : payments) {
        payment->displayPaymentInfo();;
    }
}
