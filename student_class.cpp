#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display() { cout << "Name: " << name << ", Age: " << age << endl; }
};

// Use virtual inheritance to avoid duplication of Person
class Student : virtual public Person {
protected:
    int rollNumber;
    string branch;
    double marks;
public:
    Student(string n, int a, int roll, string b, double m)
        : Person(n, a), rollNumber(roll), branch(b), marks(m) {}
    
    double calculateCGPA() { return marks / 10; }

    void display() {
        Person::display();
        cout << "Roll: " << rollNumber << ", Branch: " << branch << ", CGPA: " << calculateCGPA() << endl;
    }

    friend class Administration;
};

class Faculty : virtual public Person {
protected:
    int facultyID;
    string department;
    double salary;
public:
    Faculty(string n, int a, int id, string dep, double sal)
        : Person(n, a), facultyID(id), department(dep), salary(sal) {}

    void display() {
        Person::display();
        cout << "ID: " << facultyID << ", Dept: " << department << ", Salary: " << salary << endl;
    }

    friend class Administration;
};

class TeachingAssistant : public Student, public Faculty {
public:
    TeachingAssistant(string name, int age, int roll, string branch, double marks,
                      int id, string dep, double sal)
        : Person(name, age), Student(name, age, roll, branch, marks),
          Faculty(name, age, id, dep, sal) {}

    void display() {
        Student::display();
        cout << "Teaching Assistant Additional Info:" << endl;
        Faculty::display(); // Optional if you want to show faculty-specific info
    }
};

class Administration {
public:
    static void showDetails(const Student& s, const Faculty& f) {
        cout << "Admin: " << s.name << " scored " << s.marks
             << ", " << f.name << " teaches " << f.department << endl;
    }
};

int main() {
    Student s("Raj", 20, 1, "CSE", 89);
    Faculty f("Dr. A", 45, 1001, "CS", 120000);
    TeachingAssistant ta("Priya", 25, 5, "AI", 90, 2005, "AI", 35000);

    s.display(); cout << endl;
    f.display(); cout << endl;
    ta.display(); cout << endl;

    Administration::showDetails(s, f);

    return 0;
}
