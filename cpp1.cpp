#include <iostream>
using namespace std;

// ---------- Function Prototype ----------
int add(int a, int b);  

// ---------- Inline Function ----------
inline int cube(int x) {
    return x * x * x;
}

// ---------- Void Function ----------
void greet() {
    cout << "Hello! Welcome to the C++ Function Demonstration.\n";
}

// ---------- Default Arguments ----------
int multiply(int a, int b = 2) {
    return a * b;
}

// ---------- Function Overloading ----------
int square(int x) {
    return x * x;
}
double square(double x) {
    return x * x;
}

// ---------- Pass by Value ----------
void passByValue(int x) {
    x += 5;
    cout << "Inside passByValue: x = " << x << endl;
}

// ---------- Pass by Reference ----------
void passByReference(int &x) {
    x += 5;
    cout << "Inside passByReference: x = " << x << endl;
}

// ---------- Pass by Pointer ----------
void passByPointer(int *x) {
    *x += 5;
    cout << "Inside passByPointer: x = " << *x << endl;
}

// ---------- Recursive Function ----------
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// ---------- Function with return ----------
int add(int a, int b) {
    return a + b;
}

// ---------- CLASS with Friend and Static Functions ----------
class Box {
private:
    int length;

public:
    Box(int l) : length(l) {}

    // Static function
    static void showMessage() {
        cout << "This is a static function inside the Box class.\n";
    }

    // Declare friend function
    friend void printLength(Box b);
};

// Friend function
void printLength(Box b) {
    cout << "Length of the box (accessed by friend function) = " << b.length << endl;
}

// ---------- VIRTUAL FUNCTIONS ----------
class Animal {
public:
    virtual void speak() {  // Virtual function
        cout << "Animal makes a sound.\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks.\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows.\n";
    }
};

// ---------- PURE VIRTUAL FUNCTIONS (Abstract Class) ----------
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function → abstract class
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle.\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle.\n";
    }
};

// ---------- MAIN FUNCTION ----------
int main() {
    greet();  // void function

    // Return function
    int a = 5, b = 10;
    cout << "\nAdd(" << a << ", " << b << ") = " << add(a, b) << endl;

    // Default arguments
    cout << "Multiply(5) with default arg = " << multiply(5) << endl;
    cout << "Multiply(5, 4) = " << multiply(5, 4) << endl;

    // Inline function
    cout << "Cube of 3 (inline) = " << cube(3) << endl;

    // Overloading
    cout << "Square of 6 (int) = " << square(6) << endl;
    cout << "Square of 4.5 (double) = " << square(4.5) << endl;

    // Pass by value/reference/pointer
    int num = 20;
    cout << "\nBefore passByValue, num = " << num << endl;
    passByValue(num);
    cout << "After passByValue, num = " << num << endl;

    cout << "\nBefore passByReference, num = " << num << endl;
    passByReference(num);
    cout << "After passByReference, num = " << num << endl;

    cout << "\nBefore passByPointer, num = " << num << endl;
    passByPointer(&num);
    cout << "After passByPointer, num = " << num << endl;

    // Recursive function
    cout << "\nFactorial of 5 = " << factorial(5) << endl;

    // Friend function
    Box box1(50);
    printLength(box1);

    // Static function
    Box::showMessage();

    // Virtual function demo
    cout << "\n--- Virtual Function Demo ---\n";
    Animal *a1;
    Dog d;
    Cat c;

    a1 = &d;
    a1->speak(); // Dog’s version

    a1 = &c;
    a1->speak(); // Cat’s version

    // Pure virtual function demo
    cout << "\n--- Pure Virtual Function (Abstract Class) Demo ---\n";
    Shape *s1;
    Circle cir;
    Rectangle rect;

    s1 = &cir;
    s1->draw();

    s1 = &rect;
    s1->draw();

    return 0;
}
