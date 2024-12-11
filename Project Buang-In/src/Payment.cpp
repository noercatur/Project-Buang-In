#include "Payment.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <iostream>


Payment::Payment() 
    : paymentID(0), paymentDate(getCurrentDate()), statusPayment(false), paymentType(PaymentType::Service) {}

Payment::Payment(int id, const std::string& date, bool status, PaymentType type)
    : paymentID(id), paymentDate(date), statusPayment(status), paymentType(type) {}

std::string Payment::getCurrentDate() const { 
    time_t now = time(0);
    tm* ltm = localtime(&now);
    std::ostringstream dateStream;
    dateStream << 1900 + ltm->tm_year << "-" 
               << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon << "-"
               << std::setw(2) << std::setfill('0') << ltm->tm_mday;
    return dateStream.str();
}

int Payment::getPaymentID() const { 
    return paymentID;
}

std::string Payment::getPaymentDate() const { 
    return paymentDate;
}

bool Payment::getStatusPayment() const { 
    return statusPayment;
}

PaymentType Payment::getPaymentType() const { 
    return paymentType;
}

void Payment::setPaymentID(int id) { 
    paymentID = id;
}

void Payment::setPaymentDate(const std::string& date) { 
    paymentDate = date;
}

void Payment::setStatusPayment(bool status) { 
    statusPayment = status;
}

void Payment::setPaymentType(PaymentType type) { 
    paymentType = type;
}

void Payment::displayPaymentInfo() const { 
    std::cout << "Payment ID: " << paymentID << std::endl;
    std::cout << "Payment Date: " << paymentDate << std::endl;
    std::cout << "Status: " << (statusPayment ? "Paid" : "Not Paid") << std::endl;
    std::cout << "Payment Type: " 
              << (paymentType == PaymentType::Subscription ? "Subscription" : "Service") << std::endl;
}