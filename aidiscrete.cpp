#include <iostream>
#include <iomanip> // You had this
#include <algorithm> // For std::sort, if we decide to use it for sorting output (optional)

using namespace std;

// Forward declarations
int _intersec(int arr[], int brr[], int na, int nb);
void intersec(int arr[], int brr[], int na, int nb); // To print intersection
void diff(int arr[], int brr[], int na, int nb);
void _union(int arr[], int brr[], int na, int nb); // To print union

// Helper function to check if an element exists in an array up to a certain length
bool contains(const int an_array[], int len, int value) {
    for (int i = 0; i < len; ++i) {
        if (an_array[i] == value) {
            return true;
        }
    }
    return false;
}

// _intersec: Counts UNIQUE common elements without std::set
int _intersec(int arr[], int brr[], int na, int nb) {
    if (na == 0 || nb == 0) return 0;

    int* temp_common = new int[min(na, nb)]; // Max possible common elements
    int count = 0;

    for (int i = 0; i < na; ++i) {
        // Check if arr[i] is in brr
        bool found_in_brr = false;
        for (int j = 0; j < nb; ++j) {
            if (arr[i] == brr[j]) {
                found_in_brr = true;
                break;
            }
        }

        if (found_in_brr) {
            // Now check if this common element (arr[i]) is already counted in temp_common
            if (!contains(temp_common, count, arr[i])) {
                if (count < min(na, nb)) { // Boundary check for temp_common
                    temp_common[count++] = arr[i];
                }
            }
        }
    }
    delete[] temp_common;
    return count;
}

void _union(int arr[], int brr[], int na, int nb) {
    int c;
    c = _intersec(arr, brr, na, nb); // 'c' is count of UNIQUE common elements
    int u;
    u = na + nb - c;

    if (u < 0) u = 0;

    int *u_set = nullptr;
    if (u > 0) {
        u_set = new int[u];
    } else if (na == 0 && nb == 0) {
        cout << "Union of Set A and Set B." << endl;
        cout << "{ }" << endl;
        return;
    }

    int current_union_idx = 0;

    // 1. Add unique elements from arr to u_set
    for (int i = 0; i < na; i++) {
        if (!contains(u_set, current_union_idx, arr[i])) { // Check if arr[i] is already in u_set
            if (u_set && current_union_idx < u) {
                u_set[current_union_idx++] = arr[i];
            }
        }
    }

    // 2. Add unique elements from brr (that are not already in u_set) to u_set
    for (int i = 0; i < nb; i++) {
        if (!contains(u_set, current_union_idx, brr[i])) { // Check if brr[i] is already in u_set
             if (u_set && current_union_idx < u) {
                u_set[current_union_idx++] = brr[i];
            }
        }
    }

    cout << "Union of Set A and Set B." << endl;
    cout << "{ ";
    if (u_set) {
        // The number of elements to print is current_union_idx,
        // as 'u' might be an overestimate if na/nb had many internal duplicates
        // that _intersec didn't fully account for in the na+nb-c formula's inputs.
        // However, if _intersec is perfect and na/nb are considered "set sizes" initially,
        // u should be the correct size for the unique union.
        // For safety and correctness of what's *actually* populated:
        for (int i = 0; i < current_union_idx; i++) {
            cout << u_set[i];
            if (i < current_union_idx - 1) {
                cout << ", ";
            }
        }
    }
    cout << " }" << endl;
    delete[] u_set;
}

void intersec(int arr[], int brr[], int na, int nb) { // Print (AnB)
    if (na == 0 || nb == 0) {
        cout << "(AnB) = { }" << endl;
        return;
    }
    int estimated_max_common = min(na, nb);
    int *p_intersec = new int[estimated_max_common];
    int common_count = 0;

    for (int i = 0; i < na; ++i) {
        // Check if arr[i] is in brr
        bool found_in_brr = false;
        for (int j = 0; j < nb; ++j) {
            if (arr[i] == brr[j]) {
                found_in_brr = true;
                break;
            }
        }

        if (found_in_brr) {
            // Check if this common element (arr[i]) is already in p_intersec
            if (!contains(p_intersec, common_count, arr[i])) {
                 if (common_count < estimated_max_common) { // Boundary check
                    p_intersec[common_count++] = arr[i];
                }
            }
        }
    }

    cout << "(AnB) = { ";
    for (int i = 0; i < common_count; i++) {
        cout << p_intersec[i];
        if (i < common_count - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
    delete[] p_intersec;
}

void diff(int arr[], int brr[], int na, int nb) { // Print (A-B)
    if (na == 0) {
        cout << "(A-B) = { }" << endl;
        return;
    }

    int *p = new int[na]; // Max possible elements in A-B is all of A
    int diff_count = 0;

    for (int i = 0; i < na; ++i) {
        // Check if arr[i] is in brr
        bool found_in_brr = false;
        for (int j = 0; j < nb; ++j) {
            if (arr[i] == brr[j]) {
                found_in_brr = true;
                break;
            }
        }

        if (!found_in_brr) { // If arr[i] is NOT in brr
            // Check if arr[i] is already in our difference set p
            if (!contains(p, diff_count, arr[i])) {
                if (diff_count < na) { // Boundary check
                    p[diff_count++] = arr[i];
                }
            }
        }
    }

    cout << "(A-B) = { ";
    for (int i = 0; i < diff_count; i++) {
        cout << p[i];
        if (i < diff_count - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
    delete[] p;
}

int main() {
    int *a, n, choice;
    cout << "Enter the no. of elements of set A" << endl;
    cin >> n;
    // Basic validation for n
    if (n < 0) {
        cout << "Number of elements cannot be negative." << endl;
        return 1;
    }
    if (n > 0) a = new int[n];
    else a = nullptr;

    for (int i = 0; i < n; i++) {
        cout << "A [ " << i + 1 << " ]  = ";
        cin >> a[i];
    }

    int *b, n1;
   S: cout << "Enter the no. of elements of set B" << endl;
    cin >> n1;
    // Basic validation for n1
    if (n1 < 0) {
        cout << "Number of elements cannot be negative." << endl;
        if (a) delete[] a; // Clean up 'a' if allocated
        return 1;
    }
    if (n1 > 0) b = new int[n1];
    else b = nullptr;

    for (int i = 0; i < n1; i++) {
        cout << "B [ " << i + 1 << " ]  = ";
        cin >> b[i];
    }

    while (1) {
        cout << "Enter the choice" << endl << "1. Union" << endl << "2. Intersection" << endl << "3. Difference (A-B)" << endl <<"4. Restart"<<endl;"5. Exit" << endl;
        cout << "Enter(1-4) = ";
        if (!(cin >> choice)) { // Handle non-integer input
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
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
            diff(a, b, n, n1);
            break;
        case 4:
        goto S;
        case 5:
            if (a) delete[] a;
            if (b) delete[] b;
            return 0;
        default:
            cout << "Invalid Number Please try again!" << endl;
        }
    }
    // Should not be reached
    return 0;
}