#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"

using namespace std;

void patientsName(PatientAccount*);
void surgeryMenu(Surgery* );
void findDaysInHosp(PatientAccount*, Surgery*);
void rxMenu(Pharmacy*);
void patientCharges(PatientAccount*, Surgery*, Pharmacy*);

int main() {
    char choice;
    do {
        //initialize pointers to nullptr
        PatientAccount *patientPtr = nullptr;
        Surgery *surgeryPtr = nullptr;
        Pharmacy *pharmacyPtr = nullptr;

        //loop basis: checkout patient
        do {
            cout << "Would you like to check a patient out of the hospital?";
            cout << " (Y or N) ";
            cin >> choice;
            cin.ignore();

            // if no, quit program
            if (toupper(choice) == 'N') {
                cout << endl << endl << "Goodbye" << endl;
                return 0;
            }
        } while (toupper(choice) != 'N' && toupper(choice) != 'Y');

        //create pointer objects
        patientPtr = new PatientAccount;
        surgeryPtr = new Surgery;
        pharmacyPtr = new Pharmacy;

        patientsName(patientPtr); //get patient's name
        surgeryMenu(surgeryPtr); //get surgery performed and set charge
        findDaysInHosp(patientPtr, surgeryPtr); //get num days in hosp
        rxMenu(pharmacyPtr); //get rx
        patientCharges(patientPtr, surgeryPtr, pharmacyPtr); //pt receipt

        //delete so no memory leaks
        delete patientPtr;
        delete surgeryPtr;
        delete pharmacyPtr;
        patientPtr = nullptr;
        surgeryPtr = nullptr;
        pharmacyPtr = nullptr;
    } while (toupper(choice) == 'Y');
    return 0;
  }

void patientsName(PatientAccount *patientPtr) {
    string ptname;
    cout << "Enter the patient's name: ";
    getline(cin, ptname);
    patientPtr->setName(ptname);
}

void surgeryMenu(Surgery *surgeryPtr) {
    int surgeryChoice;
    do {
        cout << "What type of surgery did the patient have:" << endl;
        cout << "1. Heart Transplant" << endl;
        cout << "2. Kidney Transplant" << endl;
        cout << "3. Liver Transplant" << endl;
        cout << "4. Open Heart Surgery" << endl;
        cout << "5. Sex Reassignment Surgery" << endl;
        cout << "6. Exit Program" << endl;
        cout << "Enter 1-6: ";
        cin >> surgeryChoice;
    } while (surgeryChoice < 1 || surgeryChoice > 6);

    switch (surgeryChoice) {
        case 1 :  surgeryPtr->setSurgeryName("Heart Transplant");
                  surgeryPtr->setSurgeryCharge(surgeryChoice);
                  break;
        case 2 :  surgeryPtr->setSurgeryName("Kidney Transplant");
                  surgeryPtr->setSurgeryCharge(surgeryChoice);
                  break;
        case 3 :  surgeryPtr->setSurgeryName("Liver Transplant");
                  surgeryPtr->setSurgeryCharge(surgeryChoice);
                  break;
        case 4 :  surgeryPtr->setSurgeryName("Open Heart Surgery");
                  surgeryPtr->setSurgeryCharge(surgeryChoice);
                  break;
        case 5 :  surgeryPtr->setSurgeryName("Sex Reassignment Surgery");
                  surgeryPtr->setSurgeryCharge(surgeryChoice);
                  break;
        case 6 :  cout << endl << endl << "Goodbye" << endl;
                  exit(EXIT_SUCCESS);
    }
}

void findDaysInHosp(PatientAccount *patientPtr, Surgery *surgeryPtr) {
    bool flag = false;
    double days;
    do {
        cout << "How many days did the patient stay?: ";
        cin >> days;
        if (days <= 0) {
            cout << "Patient must be in hospital longer than that";
            cout << "after having " << surgeryPtr->getSurgeryName() << endl;
        }
    } while (days <= 0);
    patientPtr->setNumDaysInHosp(days);
}

void rxMenu(Pharmacy *pharmacyPtr) {
    int rxChoice;
    do {
        cout << "What medications did the patient take? " << endl;
        cout << "1. Dilaudid" << endl;
        cout << "2. Fentanyl" << endl;
        cout << "3. Morphine" << endl;
        cout << "4. Oxycodone" << endl;
        cout << "5. Tacrolimus" << endl;
        cout << "6. End Program" << endl;
        cout << "Enter 1-6: ";
        cin >> rxChoice;
    } while (rxChoice < 1 || rxChoice > 6);

    switch(rxChoice) {
        case 1 :  pharmacyPtr->setMedicationName("Dilaudid");
                  pharmacyPtr->setPrice(rxChoice);
                  break;
        case 2 :  pharmacyPtr->setMedicationName("Fentanyl");
                  pharmacyPtr->setPrice(rxChoice);
                  break;
        case 3 :  pharmacyPtr->setMedicationName("Morphine");
                  pharmacyPtr->setPrice(rxChoice);
                  break;
        case 4 :  pharmacyPtr->setMedicationName("Oxycodone");
                  pharmacyPtr->setPrice(rxChoice);
                  break;
        case 5 :  pharmacyPtr->setMedicationName("Tacrolimus");
                  pharmacyPtr->setPrice(rxChoice);
                  break;
        case 6 :  cout << endl << endl << "Goodbye" << endl;
                  exit(EXIT_SUCCESS);
    }
    int timesPerDay;
    do {
        cout << "How many times a day did the patient take the Rx: ";
        cin >> timesPerDay;
    } while ( timesPerDay <= 0);
    pharmacyPtr->setTimesPerDay(timesPerDay);
}

void patientCharges(PatientAccount *patientPtr, Surgery *surgeryPtr,
  Pharmacy *pharmacyPtr) {
    pharmacyPtr->setPharmacyCharges(patientPtr->getNumDaysInHosp());
    const int columnWidth = 20;
    patientPtr->setCharges();

    cout << endl << endl;
    cout << "- - - - - - - Patient Receipt - - - - - - -" << endl;
    cout << setw(columnWidth) << left << "Patient:";
    cout << patientPtr->getName() << endl;
    cout << setw(columnWidth) << left << "Length of Stay:";
    cout << patientPtr->getNumDaysInHosp() << endl;
    cout << setw(columnWidth) << left << "Cost of Stay:";
    cout << setprecision(2) << fixed << patientPtr->getCharges() << endl;

    cout << setw(columnWidth) << left << "Type Of Surgery:";
    cout << surgeryPtr->getSurgeryName() << endl;
    cout << setprecision(2) << fixed;
    cout << setw(columnWidth) << left << "Surgery Charges:" << '$';
    cout << surgeryPtr->getSurgeryCharge() << endl;

    cout << setw(columnWidth) << left << "Medication:";
    cout << pharmacyPtr->getMedicationName() << endl;

    cout << setw(columnWidth) << left << "Cost of medication:";
    cout << '$' << pharmacyPtr->getPharmacyCharges() << endl;


    double charges = patientPtr->getCharges() + surgeryPtr->getSurgeryCharge() +
                      pharmacyPtr->getPharmacyCharges();
    cout << setprecision(2) << fixed;
    cout << setw(columnWidth) << left << "Amount due:" << '$' << charges << endl;
}
