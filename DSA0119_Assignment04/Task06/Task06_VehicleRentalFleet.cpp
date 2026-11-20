
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class EnergyInfo {
private:
    double level;
    string unit;

public:
    EnergyInfo(double l, string u)
        : level(l), unit(u) {}

    void display() const {
        cout << "Energy Level: " << level
             << " " << unit << '\n';
    }
};

class ServiceRecord {
private:
    string serviceDueDate;

public:
    ServiceRecord(string date)
        : serviceDueDate(date) {}

    void display() const {
        cout << "Service Due Date: "
             << serviceDueDate << '\n';
    }
};

class Vehicle {
protected:
    string registrationNo;
    double dailyRate;
    bool rented;

public:
    Vehicle(string reg, double rate)
        : registrationNo(reg),
          dailyRate(rate),
          rented(false) {}

    virtual ~Vehicle() {}

    string getRegistrationNo() const {
        return registrationNo;
    }

    double getDailyRate() const {
        return dailyRate;
    }

    bool isRented() const {
        return rented;
    }

    bool rent() {
        if (rented)
            return false;

        rented = true;
        return true;
    }

    double lateCharge(int lateDays) const {
        if (lateDays < 0)
            lateDays = 0;

        return lateDays * dailyRate * 0.5;
    }

    virtual double calculateRentalCharge(int days) const = 0;

    virtual void display() const {
        cout << "Registration Number: "
             << registrationNo << '\n';

        cout << "Daily Rate: Rs. "
             << dailyRate << '\n';

        cout << "Status: "
             << (rented ? "Rented" : "Available")
             << '\n';
    }

    double returnVehicle(int days, int lateDays) {
        if (!rented || days <= 0 || lateDays < 0) {
            return -1;
        }

        double rentalAmount =
            calculateRentalCharge(days);

        double lateAmount =
            lateCharge(lateDays);

        double total = rentalAmount + lateAmount;

        rented = false;

        cout << "\nRental Amount: Rs. "
             << rentalAmount << '\n';

        cout << "Late Charge: Rs. "
             << lateAmount << '\n';

        cout << "Total Amount: Rs. "
             << total << '\n';

        return total;
    }
};

class MotorVehicle : public Vehicle {
protected:
    EnergyInfo energy;
    ServiceRecord service;

public:
    MotorVehicle(string reg, double rate,
                 double level, string unit,
                 string serviceDate)
        : Vehicle(reg, rate),
          energy(level, unit),
          service(serviceDate) {}

    void display() const override {
        Vehicle::display();
        energy.display();
        service.display();
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle(string reg, double rate)
        : Vehicle(reg, rate) {}

    double calculateRentalCharge(int days) const override {
        return dailyRate * days;
    }
};

class TwoWheeler : public MotorVehicle {
private:
    double fuelUsedLitres;
    double fuelPricePerLitre;

public:
    TwoWheeler(string reg, double rate,
               double level, string date,
               double fuelUsed, double fuelPrice)
        : MotorVehicle(reg, rate, level, "litres", date),
          fuelUsedLitres(fuelUsed),
          fuelPricePerLitre(fuelPrice) {}

    double calculateRentalCharge(int days) const override {
        return (dailyRate * days) +
               (fuelUsedLitres * fuelPricePerLitre);
    }
};

class Car : public MotorVehicle {
private:
    int seatingCapacity;
    double fuelUsedLitres;
    double fuelPricePerLitre;

public:
    Car(string reg, double rate,
        double level, string date,
        int seats, double fuelUsed,
        double fuelPrice)
        : MotorVehicle(reg, rate, level, "litres", date),
          seatingCapacity(seats),
          fuelUsedLitres(fuelUsed),
          fuelPricePerLitre(fuelPrice) {}

    double calculateRentalCharge(int days) const override {
        double basic = dailyRate * days;

        double fuelCost =
            fuelUsedLitres * fuelPricePerLitre;

        double seatingCharge =
            seatingCapacity * 50.0 * days;

        return basic + fuelCost + seatingCharge;
    }

    void display() const override {
        MotorVehicle::display();

        cout << "Seating Capacity: "
             << seatingCapacity << '\n';
    }
};

class ElectricCar : public MotorVehicle {
private:
    double batteryCapacityKWh;
    double energyUsedKWh;
    double pricePerKWh;

public:
    ElectricCar(string reg, double rate,
                double chargeLevel, string date,
                double capacity, double energyUsed,
                double price)
        : MotorVehicle(reg, rate, chargeLevel,
                       "kWh", date),
          batteryCapacityKWh(capacity),
          energyUsedKWh(energyUsed),
          pricePerKWh(price) {}

    double calculateRentalCharge(int days) const override {
        return (dailyRate * days) +
               (energyUsedKWh * pricePerKWh);
    }

    void display() const override {
        MotorVehicle::display();

        cout << "Battery Capacity: "
             << batteryCapacityKWh << " kWh\n";
    }
};

class ElectricBus : public MotorVehicle {
private:
    double batteryCapacityKWh;
    double energyUsedKWh;
    double pricePerKWh;

public:
    ElectricBus(string reg, double rate,
                double chargeLevel, string date,
                double capacity, double energyUsed,
                double price)
        : MotorVehicle(reg, rate, chargeLevel,
                       "kWh", date),
          batteryCapacityKWh(capacity),
          energyUsedKWh(energyUsed),
          pricePerKWh(price) {}

    double calculateRentalCharge(int days) const override {
        return (dailyRate * days) +
               (energyUsedKWh * pricePerKWh);
    }

    void display() const override {
        MotorVehicle::display();

        cout << "Bus Battery Capacity: "
             << batteryCapacityKWh << " kWh\n";
    }
};

Vehicle* findVehicle(Vehicle* fleet[],
                     int size, string reg) {
    for (int i = 0; i < size; i++) {
        if (fleet[i]->getRegistrationNo() == reg) {
            return fleet[i];
        }
    }

    return nullptr;
}

void listVehicles(Vehicle* fleet[], int size) {
    cout << "\n========== VEHICLE FLEET ==========\n";

    for (int i = 0; i < size; i++) {
        cout << "\nVehicle " << i + 1 << '\n';
        fleet[i]->display();
    }
}

void rentVehicle(Vehicle* fleet[],
                 int size, string reg) {
    Vehicle* vehicle = findVehicle(fleet, size, reg);

    if (vehicle == nullptr) {
        cout << "\nVehicle " << reg << " not found.\n";
        return;
    }

    if (vehicle->rent()) {
        cout << "\nVehicle " << reg
             << " rented successfully.\n";
    } else {
        cout << "\nVehicle " << reg
             << " is already rented.\n";
    }
}

void returnVehicle(Vehicle* fleet[],
                   int size, string reg,
                   int days, int lateDays) {
    Vehicle* vehicle = findVehicle(fleet, size, reg);

    if (vehicle == nullptr) {
        cout << "\nVehicle not found.\n";
        return;
    }

    cout << "\nReturning Vehicle: " << reg << '\n';

    double amount =
        vehicle->returnVehicle(days, lateDays);

    if (amount == -1) {
        cout << "Invalid return operation.\n";
    } else {
        cout << "Vehicle returned successfully.\n";
    }
}

int main() {
    cout << fixed << setprecision(2);

    Bicycle bicycle("BIKE101", 100);

    TwoWheeler twoWheeler(
        "TW201", 100, 5, "2026-12-15", 2, 110
    );

    Car car(
        "CAR301", 150, 20, "2026-12-20",
        4, 5, 110
    );

    ElectricCar electricCar(
        "EV401", 200, 80, "2026-12-25",
        60, 12, 8
    );

    ElectricBus electricBus(
        "BUS501", 300, 90, "2027-01-05",
        200, 30, 8
    );

    Vehicle* fleet[5] = {
        &bicycle,
        &twoWheeler,
        &car,
        &electricCar,
        &electricBus
    };

    int size = 5;

    listVehicles(fleet, size);

    cout << "\n========== RENTING VEHICLES ==========\n";

    for (int i = 0; i < size; i++) {
        rentVehicle(
            fleet, size,
            fleet[i]->getRegistrationNo()
        );
    }

    cout << "\n========== RETURNING VEHICLES ==========\n";

    for (int i = 0; i < size; i++) {
        returnVehicle(
            fleet, size,
            fleet[i]->getRegistrationNo(),
            2, 1
        );
    }

    cout << "\n========== FINAL FLEET STATUS ==========\n";

    listVehicles(fleet, size);

    return 0;
}
