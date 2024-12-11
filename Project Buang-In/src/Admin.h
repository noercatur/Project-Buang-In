#ifndef _ADMIN_H
#define _ADMIN_H
#include <string>
#include <vector>
#include "Payment.h"
#include "PickupLocation.h"
class Admin {
private: 
    int ID;
    std::string name;
    std::string email;
    std::string password;
    std::vector<Payment> payments; 
    std::vector<std::string> pickups;
public: 
    Admin(int ID, const std::string& name, const std::string& email, const std::string& password);
    
    int getID() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPassword() const;
   
    void setID(int newID);
    void setName(const std::string& newName);
    void setEmail(const std::string& newEmail);
    void setPassword(const std::string& newPassword);

    void monitorPickup(const std::vector<Location>& pickups) const;
    void monitorPayment(const std::vector<Payment*>& payments) const;
    void addPayment(const Payment& payment);
    void addPickup(const std::string& pickup);
};

#endif //_ADMIN_H