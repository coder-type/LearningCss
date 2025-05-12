#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll;
    float* marks;

public:
    Student() {
        marks = new float[3];
    }

    ~Student() {
        delete[] marks;
    }

    void input() {
        cout << "Name: ";
        cin >> name;
        cout << "Roll: ";
        cin >> roll;
        cout << "Marks:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void display() {
        cout << "Name: " << name << "\nRoll: " << roll << "\nMarks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nAverage: " << fixed << setprecision(2) << average() << "\n\n";
    }

    float average() {
        float sum = 0;
        for (int i = 0; i < 3; i++) sum += marks[i];
        return sum / 3;
    }
};

int main() {
    int input;
    cout << "How many students do you want to input? ";
    while (!(cin >> input) || input <= 0) {
        cout << "Invalid Input. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Student* s = new Student[input];

    for (int i = 0; i < input; i++) {
        cout << "\n--- Student [" << i + 1 << "] ---\n";
        s[i].input(); // Fix: use s[i], not s.input()
    }

    cout << "\n=== Student Records ===\n";
    for (int i = 0; i < input; i++) {
        s[i].display();
    }

    // Find top scorer
    float max_avg = s[0].average();
    int top_index = 0;
    for (int i = 1; i < input; i++) {
        if (s[i].average() > max_avg) {
            max_avg = s[i].average();
            top_index = i;
        }
    }

    cout << "\n>>> Top Scorer:\n";
    s[top_index].display();

    delete[] s; // Free memory
    return 0;
}
