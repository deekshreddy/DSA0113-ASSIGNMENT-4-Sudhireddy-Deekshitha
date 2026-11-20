
#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string city;
    int pin;

public:
    Address(string c, int p)
        : city(c), pin(p) {}

    string str() const {
        return city + "-" + to_string(pin);
    }
};

class Student {
private:
    string name;
    Address* home;

public:
    Student(string n, string city, int pin)
        : name(n), home(new Address(city, pin)) {}

    Student(const Student& other)
        : name(other.name),
          home(new Address(*other.home)) {}

    Student& operator=(const Student& other) {
        if (this != &other) {
            name = other.name;

            Address* temp = new Address(*other.home);
            delete home;
            home = temp;
        }

        return *this;
    }

    ~Student() {
        delete home;
    }

    void display() const {
        cout << name << " - " << home->str() << '\n';
    }
};

int main() {

    Student s1("Kavya", "Salem", 636001);

    Student s2 = s1;

    Student s3("Arun", "Chennai", 600001);

    s3 = s1;

    cout << "Original Student:\n";
    s1.display();

    cout << "Copied Student:\n";
    s2.display();

    cout << "Assigned Student:\n";
    s3.display();

    return 0;
}
