#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Vehicle{
protected:
    double Volume;
    string Name;
public:
    Vehicle(): Volume((0)), Name(""){}
    Vehicle(double volume, string name): Volume(volume), Name(name){}

    string getName(){
        return Name;
    }

    double getVolume(){
        return Volume;
    }

    virtual int getType() = 0;

    virtual void output(ostream& os)= 0;

};
class WaterVehicle: virtual public Vehicle{
protected:
    string TypeOfWater;
    double MaxSpeedOnWater;
public:
    WaterVehicle(): TypeOfWater(""), MaxSpeedOnWater(0){}
    WaterVehicle(double volume, string name, string typeOfWater, double maxSpeed):Vehicle(volume, name), TypeOfWater(typeOfWater), MaxSpeedOnWater(maxSpeed){}

    void output(ostream& os) {
        os << "Name: " << Name << " Volume: " << Volume <<'W'<< " Type: " << TypeOfWater << " Max water speed: " << MaxSpeedOnWater <<"km/h"<< endl;
    }

    int getType(){
        return 1;
    }
};
class LandVehicle: virtual public Vehicle{
protected:
    double MaxSpeedOnLand;
    int Seats;
public:
    LandVehicle():Vehicle(), MaxSpeedOnLand(0), Seats(0){}
    LandVehicle(double volume, string name, double maxSpeedOnLand, int seats):Vehicle(volume, name), MaxSpeedOnLand(maxSpeedOnLand), Seats(seats){}

    void output(ostream& os) {
        os << "Name: " << Name << " Volume: " << Volume << " Max speed: " << MaxSpeedOnLand <<"km/h"<< " Seats: " << Seats << endl;
    }
    int getType(){
        return 2;
    }
};
class Amphibian : public WaterVehicle, public LandVehicle {
private:
    int HoursOnWater;
    int HoursOnLand;
public:
    Amphibian(): HoursOnWater(0), HoursOnLand(0) {}
    Amphibian(double volume, string name, string typeOfWater, double maxSpeedOnWater, double maxSpeedOnLand, int seats, double hoursOnWater, double hoursOnLand):Vehicle(volume,name),WaterVehicle(volume, name, typeOfWater, maxSpeedOnWater), LandVehicle(volume, name, maxSpeedOnLand, seats), HoursOnWater(hoursOnWater), HoursOnLand(hoursOnLand){}
    void output(ostream& os) {
        os << "Name: " << Vehicle::Name << " Volume: " << Vehicle::Volume<<'W'<< " Max speed: " << LandVehicle::MaxSpeedOnLand<<"km/h"<< " Seats: " << LandVehicle::Seats << " Type: " << WaterVehicle::TypeOfWater << " Max water speed: " << WaterVehicle::MaxSpeedOnWater<<"km/h "<<"Hours on Water: "<<HoursOnWater<<"h "<<"Hours on Land: "<<HoursOnLand<<"h "<<endl;
    }
    int getType() {
        return 3;
    }

};
int main() {
    vector<Vehicle*> vehicle;

    WaterVehicle v1(1100, "Ship", "Ocean", 360);
    LandVehicle v2(125, "Motorcycle", 110, 2);
    LandVehicle v3(240, "Bus", 110, 24);
    WaterVehicle v4(400, "Boat", "River", 60);
    Amphibian v5(900, "Tit70-A", "Sea", 80, 170, 14, 240, 3660);
    Amphibian v6(660, "Amphibian-A1", "ocean", 200, 300, 10, 250, 4040);

    vehicle.push_back(&v1);
    vehicle.push_back(&v2);
    vehicle.push_back(&v3);
    vehicle.push_back(&v4);
    vehicle.push_back(&v5);
    vehicle.push_back(&v6);

    for(auto elem: vehicle){
        elem->output(cout);
    }

    sort(vehicle.begin(), vehicle.end(), [](Vehicle* a, Vehicle* b) {return a->getName() < b->getName(); });

    cout << "-----------------------------------------------------------" << endl;

    for (int i = 0; i < vehicle.size(); i++) {
        vehicle[i]->output(cout);
    }

    int min = 0;
    int max = 0;

    for (int i = 0; i < vehicle.size(); i++) {
        if (vehicle[min]->getVolume() > vehicle[i]->getVolume()) {
            min = i;
        }
        if (vehicle[max]->getVolume() < vehicle[i]->getVolume()) {
            max = i;
        }
    }
    cout << "-----------------------------------------------------------" << endl;
    vehicle[min]->output(cout);
    vehicle[max]->output(cout);
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < vehicle.size(); i++) {
        if (vehicle[i]->getType() == 3) {
            vehicle[i]->output(cout);
        }
    }
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < vehicle.size(); i++) {
        if (vehicle[i]->getType() == 1) {
            vehicle[i]->output(cout);
        }
    }



    return 0;
}
