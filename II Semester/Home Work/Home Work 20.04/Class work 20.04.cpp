#include <iostream>
#include <deque>
#include <fstream>

using namespace std;

class Utility {
protected:
    string Surname;
    double Paid;
public:
    Utility() : Surname(""), Paid(0) {}

    Utility(string surname, double paid) : Surname(surname), Paid(paid) {}

    virtual void input(istream &is) {
        is >> Surname >> Paid;
    }

    virtual void output(ostream &os) {
        os << "Surname - " << Surname << endl << "Paid - " << Paid << '$' << endl;
    }

    virtual double getPaid() {
        return Paid;
    }

    virtual int FeeType() = 0;

    virtual string getSureName() = 0;

    virtual int getPersonCount() = 0;
};

class GasFee : public Utility {
private:
    int PersonCount;
public:

    void input(istream &is) {
        Utility::input(is);
        is >> PersonCount;
    }

    void output(ostream &os) {
        os << "Gas fee: " << endl;
        Utility::output(os);
        os << "Person count - " << PersonCount << endl;
    }

    int getPersonCount() {
        return PersonCount;
    }

    bool operator<(GasFee &gasFee) {
        return PersonCount < gasFee.PersonCount;
    }

    int FeeType() {
        return 1;
    }

    string getSureName() {
        return Surname;
    }
};

class WaterFee : public Utility {
private:
    string CounterDisplay;
    double PaidWaterVolume;
public:

    void input(istream &is) {
        Utility::input(is);
        is >> CounterDisplay >> PaidWaterVolume;
    }

    void output(ostream &os) {
        os << "Water fee: " << endl;
        Utility::output(os);
        os << "Counter display - " << CounterDisplay << endl << "Paid water volume - " << PaidWaterVolume << "m^3"
           << endl;
    }

    string getSureName() {
        return Surname;
    }

    bool operator<(WaterFee &waterFee) {
        return Surname < waterFee.Surname;
    }

    int FeeType() {
        return 2;
    }

    int getPersonCount() {
        return 0;
    }
};

int main() {
    deque<Utility *> allDeque;

    //Read data
    ifstream file_data("data.txt");
    while (!file_data.eof()) {
        int number;
        Utility *temp;
        file_data >> number;
        if (number == -1) {
            temp = new GasFee();
        } else if (number = -2) {
            temp = new WaterFee();
        }
        temp->input(file_data);
        allDeque.push_back(temp);
        temp->output(cout);
        cout << endl;
    }
    file_data.close();

    deque<Utility *> GasDeque;
    deque<Utility *> WaterDeque;

    //Split Gas fees and Water fees
    for (Utility *elem: allDeque) {
        if (elem->FeeType() == 1) {
            GasDeque.push_back(elem);
        } else if (elem->FeeType() == 2) {
            WaterDeque.push_back(elem);
        }
    }
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    //Sort gas fees by person count and input in "Gas Result.txt"

    //Sort gas fees
    for (int i = 0; i < GasDeque.size(); i++) {
        for (int j = i; j < GasDeque.size(); j++) {
            if (GasDeque[i]->getPersonCount() < GasDeque[j]->getPersonCount()) {
                swap(GasDeque[i], GasDeque[j]);
            }
        }
    }
    //Print sorted GasDeque
    for (Utility *elem: GasDeque) {
        elem->output(cout);
        cout << endl;
    }
    //Input
    ofstream file_gasResult("Gas Result.txt");
    for (Utility *elem: GasDeque) {
        elem->output(file_gasResult);
        file_gasResult << endl;
    }
    file_gasResult.close();

    cout << endl;
    cout << "--------------------------------" << endl;
    cout << endl;

    //Sort water fees by surname and input in "Water Result.txt"

    //Sort gas fees
    for (int i = 0; i < WaterDeque.size(); i++) {
        for (int j = i; j < WaterDeque.size(); j++) {
            if (WaterDeque[i]->getSureName() > WaterDeque[j]->getSureName()) {
                swap(WaterDeque[i], WaterDeque[j]);
            }
        }
    }
    //Print sorted WaterDeque
    for (Utility *elem: WaterDeque) {
        elem->output(cout);
        cout << endl;
    }
    //Input
    ofstream file_WaterResult("Water Result.txt");
    for (Utility *elem: WaterDeque) {
        elem->output(file_WaterResult);
        file_WaterResult << endl;
    }
    file_WaterResult.close();

    cout << endl;
    cout << "--------------------------------" << endl;
    cout << endl;

    //Sort water fee by paid and input first five in "Water paid Result.txt"
    for (int i = 0; i < WaterDeque.size(); i++) {
        for (int j = i; j < WaterDeque.size(); j++) {
            if (WaterDeque[i]->getPaid() < WaterDeque[j]->getPaid()) {
                swap(WaterDeque[i], WaterDeque[j]);
            }
        }
    }
    //Resize deque for take five first
    WaterDeque.resize(5);
    //Couldn't use an iterator for this, I'll ask you in class :З

    //Print sorted WaterDeque
    for (Utility *elem: WaterDeque) {
        elem->output(cout);
        cout << endl;
    }
    //Input
    ofstream file_Water_Paid_Result("Water paid Result.txt");
    for (Utility *elem: WaterDeque) {
        elem->output(file_Water_Paid_Result);
        file_Water_Paid_Result << endl;
        file_Water_Paid_Result << endl;
    }
    file_Water_Paid_Result.close();
    return 0;
}
