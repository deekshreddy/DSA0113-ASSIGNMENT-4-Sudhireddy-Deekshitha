#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string city;
    int pin;

public:
    Address(string c, int p)
        : city(c), pin(p) {
        cout << "Address Constructor\n";
    }

    ~Address() {
        cout << "Address Destructor\n";
    }

    void display() const {
        cout << city << "-" << pin << '\n';
    }
};

class Course {
private:
    string courseName;
    int credits;

public:
    Course(string name, int c)
        : courseName(name), credits(c) {
        cout << "Course Constructor\n";
    }

    ~Course() {
        cout << "Course Destructor\n";
    }

    void display() const {
        cout << "Course: " << courseName
             << ", Credits: " << credits << '\n';
    }
};

class Person {
protected:
    string name;
    int age;
    Address home;

public:
    Person(string n, int a, string city, int pin)
        : name(n), age(a), home(city, pin) {
        cout << "Person Constructor\n";
    }

    ~Person() {
        cout << "Person Destructor\n";
    }

    void displayPerson() const {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "Address: ";
        home.display();
    }
};

class Student : virtual public Person {
protected:
    Course course;

public:
    Student(string n, int a, string city, int pin,
            string courseName, int credits)
        : Person(n, a, city, pin),
          course(courseName, credits) {
        cout << "Student Constructor\n";
    }

    ~Student() {
        cout << "Student Destructor\n";
    }

    void displayStudent() const {
        displayPerson();
        course.display();
    }
};

class Staff : virtual public Person {
protected:
    string department;

public:
    Staff(string n, int a, string city, int pin,
          string dept)
        : Person(n, a, city, pin),
          department(dept) {
        cout << "Staff Constructor\n";
    }

    ~Staff() {
        cout << "Staff Destructor\n";
    }

    void displayStaff() const {
        displayPerson();
        cout << "Department: " << department << '\n';
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant()
        : Person("Charitha", 21, "Chennai", 600001),
          Student("Charitha", 21, "Chennai", 600001,
                  "C++ Programming", 4),
          Staff("Charitha", 21, "Chennai", 600001,
                "Computer Science") {
        cout << "TeachingAssistant Constructor\n";
    }

    ~TeachingAssistant() {
        cout << "TeachingAssistant Destructor\n";
    }
};

int main() {

    cout << "\n===== STUDENT OBJECT =====\n";
    {
        Student s("Kavya", 19, "Salem", 636001,
                  "Data Structures", 4);
    }

    cout << "\n===== STAFF OBJECT =====\n";
    {
        Staff st("Arun", 35, "Chennai", 600001,
                 "Computer Science");
    }

    cout << "\n===== TEACHING ASSISTANT OBJECT =====\n";
    {
        TeachingAssistant ta;
    }

    cout << "\n===== PROGRAM COMPLETED =====\n";

    return 0;
}
