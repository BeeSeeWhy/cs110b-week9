#ifndef PHARMACY_H
#define PHARMACY_H

using std::cout;

class Pharmacy {
    private:
        char* medicationName;
        double price;
        int timesPerDay;
        double pharmacyCharges;
    public:
        Pharmacy();
        void setPharmacyCharges(double);
        void setMedicationName(char*);
        void setPrice(int);
        void setTimesPerDay(int);
        double getPharmacyCharges()
            { return pharmacyCharges; }
        double getPrice()
            { return price; }
        int getTimesPerDay(char*)
            { return timesPerDay; }
        char* getMedicationName()
            { return medicationName; }
        void printMedicationName()
            { cout << medicationName; }
        ~Pharmacy();
};

#endif
