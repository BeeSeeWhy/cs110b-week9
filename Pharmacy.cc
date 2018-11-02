#include <cstring>
#include <iostream>
#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"
#include <string>

using std::endl;

Pharmacy::Pharmacy() {
  price = 0;
  medicationName = new char[128];
  pharmacyCharges = 0.00;
}

void Pharmacy::setMedicationName(char* n) {
  strcpy(medicationName, n);
}

void Pharmacy::setPrice(int rxChoice) {
    switch (rxChoice) {
        case 1 :  price = 800.75;
                  break;
        case 2 :  price = 12000.30;
                  break;
        case 3 :  price = 900.99;
                  break;
        case 4 :  price = 700.15;
                  break;
        case 5 :  price = 500.25;
                  break;
        default:  cout << "Medication not offered at hospital" << endl;
    }
}

void Pharmacy::setTimesPerDay(int t) {
    timesPerDay = t;
}

void Pharmacy::setPharmacyCharges(double numDaysInHosp) {
    pharmacyCharges = (((double)price * (double)timesPerDay) * numDaysInHosp);
}
Pharmacy::~Pharmacy() {
    delete [] medicationName;
}
