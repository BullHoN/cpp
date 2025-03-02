#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Vehicle {
private:
    string name;
public:
    Vehicle(string name) : name(name) {}
    virtual ~Vehicle() = default; // Virtual destructor for proper cleanup
    virtual void start() = 0; // Pure virtual function

    string type(){
        return name;
    }
};

class Car : public Vehicle {
public:
    Car() : Vehicle("Car") {} // Call base class constructor
    void start() override {
        cout << "Car Started" << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike() : Vehicle("Bike") {} // Call base class constructor
    void start() override {
        cout << "Bike Started" << endl;
    }
};

class VehicleFactory {
public:
    static unique_ptr<Vehicle> createVehicle(int choice) {
        switch (choice) {
            case 0:
                return make_unique<Car>(); // Correctly creating Car
            case 1:
                return make_unique<Bike>(); // Creating Bike
            default:
                return nullptr;
        }
    }
};

void printType(unique_ptr<Vehicle> veh){
    cout << veh.get()->type() << endl;
}

int main(){

    unique_ptr<Vehicle> myCar = VehicleFactory::createVehicle(0);
    if (myCar) myCar->start();
    
    printType(move(myCar));

    cout << myCar.get()->type() << endl;

    return 0;
}