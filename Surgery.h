#ifndef SURGERY_H
#define SURGERY_H

using std::cout;

class Surgery {
    private:
        char* surgeryName;
        double surgeryCharge;
    public:
        Surgery();
        Surgery(char*);
        void printSurgeryName()
            { cout << surgeryName; }
        void setSurgeryCharge(int);
        void setSurgeryName(char*);
        char* getSurgeryName()
            { return surgeryName; }
        double getSurgeryCharge()
            { return surgeryCharge; }
        ~Surgery();
};

#endif
