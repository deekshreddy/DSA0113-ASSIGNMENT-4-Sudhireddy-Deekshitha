
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

using namespace std;

const double ALLOWANCE_RATE = 0.42;

class Staff {
protected:
    string name;
    int id;

public:
    Staff(string n, int i) : name(n), id(i) {}

    virtual double pay() const = 0;

    virtual void display() const {
        cout << "Staff Name: " << name << '\n';
        cout << "Staff ID: " << id << '\n';
    }

    virtual ~Staff() = default;
};

class Professor : public Staff {
private:
    double basic;
    double research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i), basic(b), research(r) {}

    double pay() const override {
        return basic + basic * ALLOWANCE_RATE + research;
    }

    void display() const override {
        cout << "\n--- Professor ---\n";
        Staff::display();
        cout << "Basic Salary: Rs. " << basic << '\n';
        cout << "Research Allowance: Rs. " << research << '\n';
        cout << "Total Pay: Rs. " << pay() << '\n';
    }
};

class LabAssistant : public Staff {
private:
    double basic;

public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i), basic(b) {}

    double pay() const override {
        return basic + basic * ALLOWANCE_RATE;
    }

    void display() const override {
        cout << "\n--- Lab Assistant ---\n";
        Staff::display();
        cout << "Basic Salary: Rs. " << basic << '\n';
        cout << "Total Pay: Rs. " << pay() << '\n';
    }
};

class GuestFaculty : public Staff {
private:
    double hours;
    double rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }

    void display() const override {
        cout << "\n--- Guest Faculty ---\n";
        Staff::display();
        cout << "Working Hours: " << hours << '\n';
        cout << "Hourly Rate: Rs. " << rate << '\n';
        cout << "Total Pay: Rs. " << pay() << '\n';
    }
};

int main() {
    cout << fixed << setprecision(2);

    vector<unique_ptr<Staff>> employees;

    employees.push_back(
        make_unique<Professor>("Arun", 101, 50000, 10000)
    );

    employees.push_back(
        make_unique<LabAssistant>("Priya", 102, 30000)
    );

    employees.push_back(
        make_unique<GuestFaculty>("Kumar", 103, 40, 500)
    );

    cout << "===== COLLEGE PAYROLL SYSTEM =====\n";

    double totalPayroll = 0;

    for (const auto& employee : employees) {
        employee->display();
        totalPayroll += employee->pay();
    }

    cout << "\n==================================\n";
    cout << "Total Payroll: Rs. " << totalPayroll << '\n';
    cout << "Number of Employees: " << employees.size() << '\n';

    return 0;
}
