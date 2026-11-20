DSA01 – Assignment 4: Designing Reusable Class Hierarchies

Student Details
- Name: Mudireddy Charitha
- Register Number: 192424118
- Course: Object Oriented Programming with C++ (DSA01)
- Course Outcome: CO4
- Assignment: Assignment 4 – Designing Reusable Class Hierarchies
- Programming Language: C++
- C++ Standard: C++17

---

1. Assignment Overview
This assignment focuses on designing reusable and extensible C++ class hierarchies using object-oriented programming concepts.

The main concepts covered are:
- Inheritance and types of inheritance
- Virtual base classes
- Abstract classes and pure virtual functions
- Constructors in derived classes
- Member classes and composition
- Pointers to objects and pointers to derived classes
- The `this` pointer
- Runtime polymorphism
- Class design, reusability and extensibility

2. Development Environment
| Component | Details |
|---|---|
| IDE | Embarcadero Dev-C++ 6.3 |
| Compiler | TDM-GCC 9.2.0 (64-bit) |
| Programming Language | C++ |
| C++ Standard | C++17 |
| Compiler Flags | `-std=c++17 -Wall -Wextra` |

Compilation Command
```bash
g++ -std=c++17 -Wall -Wextra filename.cpp -o program
```

Steps to Compile and Run
1. Open the required task folder.
2. Open the `.cpp` file in Embarcadero Dev-C++.
3. Select **Execute → Compile & Run**.
4. Check the program output.
5. Capture the execution screenshot.
6. Save the screenshot in the corresponding task folder.

3. Repository Structure
```text
DSA01-RegisterNumber-Assignment4/
│
├── README.md
│
├── Task01/
│   ├── Task01_CompleteCode.cpp
│   ├── Report/
│   └── Screenshots/
│
├── Task02/
│   ├── Task02_CompleteCode.cpp
│   ├── Report/
│   └── Screenshots/
│
├── Task03/
│   ├── Task03_ConstructionTrace.cpp
│   ├── Task03_CompleteCode.cpp
│   ├── Report/
│   └── Screenshots/
│
├── Task04/
│   ├── Task04_Faulty.cpp
│   ├── Task04_Repaired.cpp
│   ├── Task04_PredictOutput.cpp
│   ├── Report/
│   └── Screenshots/
│
├── Task05/
│   ├── Task05_FourWays.cpp
│   ├── Task05_HighestCart.cpp
│   ├── Task05_CompleteCode.cpp
│   ├── Report/
│   └── Screenshots/
│
└── Task06/
    ├── Task06_VehicleRentalFleet.cpp
    ├── Report/
    └── Screenshots/
```

4. Task-wise Description and Results

Task 1 – Class Design Review
Topic: Diagnose and Repair Duplicated Classes
- Identified design problems in the existing Professor, LabAssistant and GuestFaculty classes.
- Redesigned the classes using a common base class and derived classes.
- Applied encapsulation and function overriding.
- Compared inheritance with a single class using a type field and switch statement.
Result: The duplicated design was analysed and a reusable class hierarchy was developed.

Task 2 – From Requirement to Hierarchy
Topic: University People Management
- Identified relationships between Person, Student and Staff.
- Designed a TeachingAssistant class using multiple inheritance.
- Applied virtual inheritance to avoid duplicate base-class objects.
- Considered ResearchScholar and fellowship-related data.
Result: A class hierarchy was designed to represent university people and their relationships.

Task 3 – Construction and Destruction
Topic: Constructors in Derived Classes and Member Classes
- Implemented constructor initializer lists.
- Examined construction and destruction order.
- Demonstrated member-class composition.
- Analysed constructor behaviour and object memory management.
Result: Construction and destruction behaviour was demonstrated through C++ programs.

Task 4 – Runtime Polymorphism and Memory Safety
Topic: Diagnose and Repair Faulty Polymorphic Code
- Identified problems involving non-virtual functions and destructors.
- Repaired the class hierarchy using virtual functions and overriding.
- Examined object slicing and memory management.
- Compared safe ownership using smart pointers.
Result: The faulty design was repaired and the importance of runtime polymorphism and safe memory management was demonstrated.

Task 5 – Pointers to Objects and the `this` Pointer
Topic: Object Access, Method Chaining and Cart Management

- Demonstrated four ways of accessing objects.
- Implemented an array of pointers to objects.
- Used the `this` pointer and `return *this` for method chaining.
- Compared an array of object pointers with `std::vector<Cart>`.
Result: Object pointers, method chaining and object management were implemented and analysed.

Task 6 – Design Challenge
Topic: Vehicle Rental Fleet
- Designed an abstract Vehicle base class.
- Implemented Bicycle, TwoWheeler, Car and ElectricCar classes.
- Used inheritance, composition and runtime polymorphism.
- Stored vehicles using an array of base-class pointers.
- Implemented vehicle renting, returning and late-return charges.
- Added an ElectricBus class without modifying the existing vehicle classes.
- Compared virtual functions with a switch-based design.
Result: A working vehicle rental system was implemented and extended using an additional vehicle type.

5. Execution and Verification
Each completed C++ program was compiled using the C++17 standard.
The following verification activities are included where applicable:
- Compilation and execution of source files
- Expected output and actual output comparison
- Construction and destruction traces
- Runtime polymorphism demonstrations
- Memory-safety analysis and sanitizer reports
- Demonstration of new class extensions
Execution screenshots are stored in the respective task folders.

6. Learning Outcomes
Through this assignment, I gained practical understanding of:
1. Designing reusable class hierarchies.
2. Applying different types of inheritance.
3. Understanding virtual base classes and abstract classes.
4. Implementing constructors and member classes.
5. Using pointers to objects and derived classes.
6. Applying the `this` pointer for method chaining.
7. Implementing runtime polymorphism.
8. Improving code reusability, maintainability and extensibility.

7. Conclusion
This assignment provided practical experience in designing and implementing reusable C++ class hierarchies. It demonstrated how inheritance, abstraction, composition, pointers and runtime polymorphism help create maintainable and extensible applications.
All task implementations, reports and execution screenshots are organised in their respective folders for verification.
