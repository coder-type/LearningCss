#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

namespace first {
    class _this {
        string name;
    public:
        void asc(string name) {
            this->name = name;
            cout << "Name in Ascending order = " << name << endl; 
        }
    };
}

int main() {
    first::_this n;
    string _name;
    char temp;

    cout << "Enter name = ";
    cin >> _name;

    // Sorting in ascending order
    for (int i = 0; i < _name.length(); i++) {
        for (int j = i + 1; j < _name.length(); j++) {
            if (_name[j] < _name[i]) {
                temp = _name[i];
                _name[i] = _name[j];
                _name[j] = temp;
            }
        }
    }

    n.asc(_name);  // Call member function

    return 0;
}
