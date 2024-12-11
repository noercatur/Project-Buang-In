#ifndef _PAYMENT_H
#define _PAYMENT_H

#include <string>
#include <ctime>

enum class PaymentType { Subscription, Service };

class Payment {
private:
    int paymentID;
    std::string paymentDate;
    bool statusPayment;
    PaymentType paymentType;

public:

    Payment(); 
    Payment(int id, const std::string& date, bool status, PaymentType type); 
    
    void setPaymentID(int id); 
    void setPaymentDate(const std::string& date); 
    void setStatusPayment(bool status); 
    
    int getPaymentID() const; 
    std::string getPaymentDate() const; 
    bool getStatusPayment() const; 

    void setPaymentType(PaymentType type); 
    PaymentType getPaymentType() const; 
    
    std::string getCurrentDate() const; 
    void displayPaymentInfo() const; 
};

#endif