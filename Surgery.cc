#include <cstring>
#include <iostream>
#include "PatientAccount.h"
#include "Pharmacy.h"
#include <string>
#include "Surgery.h"

using std::cout;
using std::endl;

Surgery::Surgery() {
  surgeryCharge = 0;
  surgeryName = new char[128];
}

void Surgery::setSurgeryName(char* n) {
  strcpy(surgeryName, n);
}

void Surgery::setSurgeryCharge(int c) {
    switch (c) {
        case 1 :  surgeryCharge = 80000.75;
                  break;
        case 2 :  surgeryCharge = 60000.99;
                  break;
        case 3 :  surgeryCharge = 70000.25;
                  break;
        case 4 :  surgeryCharge = 75000.30;
                  break;
        case 5 :  surgeryCharge = 45000.15;
                  break;
        default:  cout << "Surgery not offered at the hospital" << endl;
    }
}

Surgery::~Surgery() {
  delete [] surgeryName;
}
