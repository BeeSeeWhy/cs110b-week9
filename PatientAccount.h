#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

using std::cout;
using std::string;

class PatientAccount {
    private:
        double charges;
        double hospDailyRate;
        string name;
        double numDaysInHosp;
    public:
        PatientAccount();
        void setCharges();
        void setHospDailyRate();
        void setName(string);
        void setNumDaysInHosp(double);
        double getCharges()
            { return charges; }
        double getHospDailyRate()
            { return hospDailyRate; }
        string getName()
            { return name; }
        double getNumDaysInHosp()
            { return numDaysInHosp; }
        void printName()
            { cout << name; }
        //~PatientAccount();
};

#endif
