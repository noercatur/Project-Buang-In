#ifndef _USER_H
#define _USER_H

#include <string>
#include <vector>
#include "PickupLocation.h"
#include "Member.h"
#include "Payment.h"

class User {
private: 
    int ID; 
    std::string username;
    std::string email;
    std::string password;
    Location pickupLocation;
    bool statusLogin;
    Member member; 
    std::vector<Payment*> payments;

    int generateRandomID(); 
public: 
    User(const std::string& username, const std::string& email, const std::string& password); 

    int getID() const; 
    std::string getUsername() const; 
    std::string getEmail() const; 
    std::string getPassword() const; 
    void setID(int newID); 
    void setUsername(const std::string& newUsername); 
    void setEmail(const std::string& newEmail); 
    void setPassword(const std::string& newPassword); 

    bool login(const std::string& inputUsername, const std::string& inputPassword); 
    void registrasi(const std::string& newUsername, const std::string& newEmail, const std::string& newPassword);
    void logout(); 
    bool getStatusLogin() const; 

    bool statusSubscription() const; 
    void subscribe(int durasiHari); 
    void cancelSubscription(); 
    int getSisaHariSubscription() const; 

    void setPickupLocation(const Location& location); 
    Location getPickupLocation() const; 

    void addPayment(Payment* payment);
};

#endif