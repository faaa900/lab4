#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Template function for updating scale
template <typename T>
void update_scale(T& m1, T& m2, T m3 = 10) {
    T original_m1 = m1;
    T original_m2 = m2;
    
    // Update m1 and m2 as per the given requirements
    m1 = (original_m1 + original_m2) * m3;
    m2 = (original_m1 - original_m2) * m3;
}

// Function to print a real number with formatting
void print_real(float number, int fieldspace, int precision);

int main(void) {
    float a, b;
    cout << "Please input two real numbers: ";
    cin >> a >> b;

    // Print original values
    print_real(a, 7, 3);
    print_real(b, 7, 3);

    // Call the update_scale function with a and b
    update_scale(a, b);

    // Print updated values
    print_real(a, 7, 3);
    print_real(b, 7, 3);

    return 0;
}

// Function definition for printing formatted output
void print_real(float number, int fieldspace, int precision) {
    cout << fixed << setw(fieldspace) << setprecision(precision) << number << endl;
}
