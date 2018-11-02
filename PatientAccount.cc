#include <cstring>
#include <iostream>
#include "PatientAccount.h"
#include "Pharmacy.h"
#include <string>
#include "Surgery.h"

//default constructors
PatientAccount::PatientAccount() {
    charges = numDaysInHosp = 0;
    name = "";
    PatientAccount::setHospDailyRate();
}

void PatientAccount::setName(string n) {
    name = n;
}

void PatientAccount::setCharges() {
    charges = numDaysInHosp * hospDailyRate;
}

void PatientAccount::setHospDailyRate() {
    hospDailyRate = 1150.00;
}


void PatientAccount::setNumDaysInHosp(double n) {
    numDaysInHosp = n;
}

/*PatientAccount::~PatientAccount() {
  //delete [] name;
}*/
