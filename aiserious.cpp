#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

namespace set_ops {

    class SetOperation {
    public:
        void readSet(vector<int>& set, const string& name) {
            int n;
            cout << "Enter number of elements in set " << name << ": ";
            while (!(cin >> n) || n < 0) {
                cout << "Invalid input. Try again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            set.clear();
            int value;
            cout << "Enter elements of set " << name << ": \n";
            for (int i = 0; i < n; ++i) {
                cout << name << "[" << i + 1 << "] = ";
                while (!(cin >> value)) {
                    cout << "Invalid input. Try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (find(set.begin(), set.end(), value) == set.end())
                    set.push_back(value);
                else
                    cout << "Duplicate! Skipping...\n";
            }
        }

        void printSet(const vector<int>& set, const string& label) {
            cout << label << " = { ";
            for (size_t i = 0; i < set.size(); ++i) {
                cout << set[i];
                if (i < set.size() - 1) cout << ", ";
            }
            cout << " }\n";
        }

        vector<int> getUnion(const vector<int>& a, const vector<int>& b) {
            vector<int> result = a;
            for (int val : b) {
                if (find(result.begin(), result.end(), val) == result.end())
                    result.push_back(val);
            }
            sort(result.begin(), result.end());
            return result;
        }

        vector<int> getIntersection(const vector<int>& a, const vector<int>& b) {
            vector<int> result;
            for (int val : a) {
                if (find(b.begin(), b.end(), val) != b.end() &&
                    find(result.begin(), result.end(), val) == result.end()) {
                    result.push_back(val);
                }
            }
            sort(result.begin(), result.end());
            return result;
        }

        vector<int> getDifference(const vector<int>& a, const vector<int>& b) {
            vector<int> result;
            for (int val : a) {
                if (find(b.begin(), b.end(), val) == b.end()) {
                    result.push_back(val);
                }
            }
            sort(result.begin(), result.end());
            return result;
        }
    };
}

int main() {
    using namespace set_ops;

    SetOperation op;
    vector<int> setA, setB;
    int choice;

    while (true) {
        op.readSet(setA, "A");
        op.readSet(setB, "B");

        while (true) {
            cout << "\nChoose an operation:\n"
                 << "1. Union\n"
                 << "2. Intersection\n"
                 << "3. Difference (A - B)\n"
                 << "4. Difference (B - A)\n"
                 << "5. Restart\n"
                 << "6. Exit\n"
                 << "Choice: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Try again.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    op.printSet(op.getUnion(setA, setB), "A ∪ B");
                    break;
                case 2:
                    op.printSet(op.getIntersection(setA, setB), "A ∩ B");
                    break;
                case 3:
                    op.printSet(op.getDifference(setA, setB), "A - B");
                    break;
                case 4:
                    op.printSet(op.getDifference(setB, setA), "B - A");
                    break;
                case 5:
                    cout << "Restarting...\n";
                    goto restart;
                case 6:
                    cout << "Exiting...\n";
                    return 0;
                default:
                    cout << "Invalid choice.\n";
            }
        }
        restart:;
    }
}
