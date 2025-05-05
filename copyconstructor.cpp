#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Book {
    char* title;
    float price;

public:
    // Default constructor
    Book() {
        title = nullptr;
        price = 0.0;
        cout << "Default constructor called!" << endl;
    }

    // Parameterized constructor
    Book(const char* name, float _price) {
        title = new char[strlen(name) + 1];
        for (int i = 0; i < strlen(name) + 1; i++) {
            title[i] = name[i];  // copy character by character
        }
        price = _price;
    }

    // Copy constructor (deep copy)
    Book(const Book& s) {
        title = new char[strlen(s.title) + 1];
        for (int i = 0; i < strlen(s.title) + 1; i++) {
            title[i] = s.title[i];
        }
        price = s.price;
        cout << "Copy constructor called!" << endl;
    }

    // Destructor
    ~Book() {
        delete[] title;
        cout << "Destructor called!" << endl;
    }

    // Display function
    void copied() {
        cout << "Title: " << title << ", Price: " << price << endl;
    }
};

int main() {
    Book s0;  // default constructor

    Book s1("C Programming", 600);  // parameterized constructor
    Book s2 = s1;                   // copy constructor

    cout << "Book 1: ";
    s1.copied();

    cout << "Book 2: ";
    s2.copied();

    return 0;
}
