#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Base Class: Vehicle
class Vehicle {
protected:
    char vehicleID[20];
    char make[20];
    char model[20];
    int year;
    bool isRented;
    double dailyRentalRate;

public:
    Vehicle(const char* id, const char* mk, const char* mdl, int yr, double rate)
        : year(yr), isRented(false), dailyRentalRate(rate) {
        strncpy(vehicleID, id, sizeof(vehicleID) - 1);
        vehicleID[sizeof(vehicleID) - 1] = '\0';
        strncpy(make, mk, sizeof(make) - 1);
        make[sizeof(make) - 1] = '\0';
        strncpy(model, mdl, sizeof(model) - 1);
        model[sizeof(model) - 1] = '\0';
    }

    virtual double calculateRentalCost(int days) = 0; // Pure virtual function
    virtual void displayDetails() = 0; // Pure virtual function

    void rentVehicle() { isRented = true; }
    void returnVehicle() { isRented = false; }
    bool isVehicleRented() const { return isRented; }
    const char* getVehicleID() const { return vehicleID; }
    double getDailyRentalRate() const { return dailyRentalRate; }
};

// Derived Class: Car
class Car : public Vehicle {
private:
    int numberOfDoors;
    char fuelType[20];

public:
    Car(const char* id, const char* mk, const char* mdl, int yr, double rate, int doors, const char* fuel)
        : Vehicle(id, mk, mdl, yr, rate), numberOfDoors(doors) {
        strncpy(fuelType, fuel, sizeof(fuelType) - 1);
        fuelType[sizeof(fuelType) - 1] = '\0';
    }

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days;
    }

    void displayDetails() override {
        cout << "Car ID: " << vehicleID << ", Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Doors: " << numberOfDoors << ", Fuel: " << fuelType
             << ", Daily Rate: $" << dailyRentalRate << ", Rented: " << (isRented ? "Yes" : "No") << endl;
    }
};

// Derived Class: Motorcycle
class Motorcycle : public Vehicle {
private:
    char engineType[20];
    bool hasSidecar;

public:
    Motorcycle(const char* id, const char* mk, const char* mdl, int yr, double rate, const char* engine, bool sidecar)
        : Vehicle(id, mk, mdl, yr, rate), hasSidecar(sidecar) {
        strncpy(engineType, engine, sizeof(engineType) - 1);
        engineType[sizeof(engineType) - 1] = '\0';
    }

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days + (hasSidecar ? 20 * days : 0);
    }

    void displayDetails() override {
        cout << "Motorcycle ID: " << vehicleID << ", Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Engine: " << engineType << ", Sidecar: " << (hasSidecar ? "Yes" : "No")
             << ", Daily Rate: $" << dailyRentalRate << ", Rented: " << (isRented ? "Yes" : "No") << endl;
    }
};

// Derived Class: Truck
class Truck : public Vehicle {
private:
    double cargoCapacity;
    int numberOfAxles;

public:
    Truck(const char* id, const char* mk, const char* mdl, int yr, double rate, double capacity, int axles)
        : Vehicle(id, mk, mdl, yr, rate), cargoCapacity(capacity), numberOfAxles(axles) {}

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days + (cargoCapacity * 10 * days);
    }

    void displayDetails() override {
        cout << "Truck ID: " << vehicleID << ", Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Cargo Capacity: " << cargoCapacity << " m³, Axles: " << numberOfAxles
             << ", Daily Rate: $" << dailyRentalRate << ", Rented: " << (isRented ? "Yes" : "No") << endl;
    }
};

// RentalSystem Class
class RentalSystem {
private:
    Vehicle* vehicles[100]; // Array to store pointers to vehicles
    int vehicleCount;

public:
    RentalSystem() : vehicleCount(0) {}

    void addVehicle(Vehicle* vehicle) {
        if (vehicleCount < 100) {
            vehicles[vehicleCount++] = vehicle;
        }
    }

    void displayAvailableVehicles() {
        cout << "Available Vehicles:\n";
        for (int i = 0; i < vehicleCount; i++) {
            if (!vehicles[i]->isVehicleRented()) {
                vehicles[i]->displayDetails();
            }
        }
    }

    Vehicle* findVehicle(const char* vehicleID) {
        for (int i = 0; i < vehicleCount; i++) {
            if (strcmp(vehicles[i]->getVehicleID(), vehicleID) == 0) {
                return vehicles[i];
            }
        }
        return nullptr;
    }

    void rentVehicle(const char* vehicleID, int days) {
        Vehicle* vehicle = findVehicle(vehicleID);
        if (vehicle && !vehicle->isVehicleRented()) {
            vehicle->rentVehicle();
            double cost = vehicle->calculateRentalCost(days);
            cout << "Rental Cost for " << days << " days: $" << fixed << setprecision(2) << cost << endl;
        } else {
            cout << "Vehicle not found or already rented." << endl;
        }
    }

    void returnVehicle(const char* vehicleID) {
        Vehicle* vehicle = findVehicle(vehicleID);
        if (vehicle && vehicle->isVehicleRented()) {
            vehicle->returnVehicle();
            cout << "Vehicle returned successfully." << endl;
        } else {
            cout << "Vehicle not found or not rented." << endl;
        }
    }

    ~RentalSystem() {
        for (int i = 0; i < vehicleCount; i++) {
            delete vehicles[i];
        }
    }
};

int main() {
    RentalSystem rentalSystem;

    rentalSystem.addVehicle(new Car("C001", "Toyota", "Camry", 2020, 50.0, 4, "Petrol"));
    rentalSystem.addVehicle(new Motorcycle("M001", "Honda", "CBR", 2019, 30.0, "Inline-4", false));
    rentalSystem.addVehicle(new Truck("T001", "Ford", "F-150", 2021, 100.0, 5.0, 2));

    rentalSystem.displayAvailableVehicles();

    rentalSystem.rentVehicle("C001", 3);
    rentalSystem.rentVehicle("T002", 2); //Vehicle Not Found

    rentalSystem.displayAvailableVehicles();

    rentalSystem.returnVehicle("C001");

    rentalSystem.displayAvailableVehicles();

    return 0;
}
