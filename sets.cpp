#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

// Helper function
bool contains(const int an_array[], int len, int value) {
    for (int i = 0; i < len; ++i) {
        if (an_array[i] == value) {
            return true;
        }
    }
    return false;
}

int _intersec(int arr[], int brr[], int na, int nb) {
    if (na == 0 || nb == 0) return 0;

    int* temp_common = new int[min(na, nb)];
    int count = 0;

    for (int i = 0; i < na; ++i) {
        for (int j = 0; j < nb; ++j) {
            if (arr[i] == brr[j] && !contains(temp_common, count, arr[i])) {
                temp_common[count++] = arr[i];
                break;
            }
        }
    }

    delete[] temp_common;
    return count;
}

void _union(int arr[], int brr[], int na, int nb) {
    int u = na + nb;
    int *u_set = new int[u];
    int current_union_idx = 0;

    for (int i = 0; i < na; i++) {
        if (!contains(u_set, current_union_idx, arr[i])) {
            u_set[current_union_idx++] = arr[i];
        }
    }

    for (int i = 0; i < nb; i++) {
        if (!contains(u_set, current_union_idx, brr[i])) {
            u_set[current_union_idx++] = brr[i];
        }
    }

    sort(u_set, u_set + current_union_idx);

    cout << "Union of Set A and Set B: { ";
    for (int i = 0; i < current_union_idx; i++) {
        cout << u_set[i];
        if (i < current_union_idx - 1) cout << ", ";
    }
    cout << " }" << endl;
    delete[] u_set;
}

void intersec(int arr[], int brr[], int na, int nb) {
    int estimated_max_common = min(na, nb);
    int *p_intersec = new int[estimated_max_common];
    int common_count = 0;

    for (int i = 0; i < na; ++i) {
        for (int j = 0; j < nb; ++j) {
            if (arr[i] == brr[j] && !contains(p_intersec, common_count, arr[i])) {
                p_intersec[common_count++] = arr[i];
                break;
            }
        }
    }

    sort(p_intersec, p_intersec + common_count);

    cout << "(A ∩ B) = { ";
    for (int i = 0; i < common_count; i++) {
        cout << p_intersec[i];
        if (i < common_count - 1) cout << ", ";
    }
    cout << " }" << endl;
    delete[] p_intersec;
}

void diff(int arr[], int brr[], int na, int nb, const string& label = "(A - B)") {
    int *p = new int[na];
    int diff_count = 0;

    for (int i = 0; i < na; ++i) {
        bool found_in_brr = false;
        for (int j = 0; j < nb; ++j) {
            if (arr[i] == brr[j]) {
                found_in_brr = true;
                break;
            }
        }

        if (!found_in_brr && !contains(p, diff_count, arr[i])) {
            p[diff_count++] = arr[i];
        }
    }

    sort(p, p + diff_count);

    cout << label << " = { ";
    for (int i = 0; i < diff_count; i++) {
        cout << p[i];
        if (i < diff_count - 1) cout << ", ";
    }
    cout << " }" << endl;
    delete[] p;
}

void readSet(int*& arr, int& n, const string& setName) {
    cout << "Enter the number of elements of set " << setName << ": ";
    while (!(cin >> n) || n < 0) {
        cout << "Invalid input. Please enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (arr) delete[] arr;
    arr = (n > 0) ? new int[n] : nullptr;

    for (int i = 0; i < n; i++) {
        cout << setName << " [" << i + 1 << "] = ";
        cin >> arr[i];
    }
}

int main() {
    int *a = nullptr, *b = nullptr;
    int n = 0, n1 = 0;
    int choice;

    while (true) {
        readSet(a, n, "A");
        readSet(b, n1, "B");

        while (true) {
            cout << "\nChoose an operation:\n"
                 << "1. Union\n"
                 << "2. Intersection\n"
                 << "3. Difference (A - B)\n"
                 << "4. Difference (B - A)\n"
                 << "5. Restart (Enter new sets)\n"
                 << "6. Exit\n"
                 << "Enter choice (1-6): ";

            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
                case 1:
                    _union(a, b, n, n1);
                    break;
                case 2:
                    intersec(a, b, n, n1);
                    break;
                case 3:
                    diff(a, b, n, n1, "(A - B)");
                    break;
                case 4:
                    diff(b, a, n1, n, "(B - A)");
                    break;
                case 5:
                    cout << "\nRestarting...\n";
                    goto restart;
                case 6:
                    cout << "Exiting........\n";
                    if (a) delete[] a;
                    if (b) delete[] b;
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }

        restart:;
    }

    return 0;
}