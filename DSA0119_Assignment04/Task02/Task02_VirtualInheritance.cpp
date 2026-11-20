#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int id;
    string phone;

public:
    Person() : name("Charitha"), id(101),
               phone("9876543210") {
        cout << "Person ";
    }

    void displayPerson() const {
        cout << "Name: " << name << '\n';
        cout << "ID: " << id << '\n';
        cout << "Phone: " << phone << '\n';
    }
};

#ifdef REMOVE_VIRTUAL
class Student : public Person {
#else
class Student : virtual public Person {
#endif

private:
    string programme;
    double cgpa;

public:
    Student() : Person(), programme("CSE"), cgpa(9.1) {
        cout << "Student ";
    }

    void displayStudent() const {
        cout << "Programme: " << programme << '\n';
        cout << "CGPA: " << cgpa << '\n';
    }
};

#ifdef REMOVE_VIRTUAL
class Staff : public Person {
#else
class Staff : virtual public Person {
#endif

private:
    string department;
    double salary;

public:
    Staff() : Person(), department("Computer Science"),
              salary(45000) {
        cout << "Staff ";
    }

    void displayStaff() const {
        cout << "Department: " << department << '\n';
        cout << "Salary: Rs. " << salary << '\n';
    }
};

class TeachingAssistant : public Student, public Staff {
public:
#ifdef REMOVE_VIRTUAL
    TeachingAssistant() : Student(), Staff() {
#else
    TeachingAssistant() : Person(), Student(), Staff() {
#endif
        cout << "TA ";
    }

    void display() const {
        displayPerson();
        displayStudent();
        displayStaff();
    }
};

class ResearchScholar : public Student {
private:
    double fellowship;

public:
    ResearchScholar() : Person(), Student(),
                        fellowship(12000) {}

    void displayFellowship() const {
        cout << "Fellowship: Rs. " << fellowship << '\n';
    }
};

class ComposedTeachingAssistant {
public:
    Student student;
    Staff staff;
};

int main() {

    cout << "===== VIRTUAL INHERITANCE =====\n";

    TeachingAssistant ta;

    cout << "\n\n===== TEACHING ASSISTANT DETAILS =====\n";
    ta.display();

    cout << "\n===== SIZE COMPARISON =====\n";

    cout << "TeachingAssistant size: "
         << sizeof(TeachingAssistant) << " bytes\n";

    cout << "Student size: "
         << sizeof(Student) << " bytes\n";

    cout << "Staff size: "
         << sizeof(Staff) << " bytes\n";

    cout << "Composition size: "
         << sizeof(ComposedTeachingAssistant) << " bytes\n";

    return 0;
}
