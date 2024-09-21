#include <iostream>
#include <set>

using namespace std;

bool operation_checker(const char &c, const set<char> &math_operations) {
    if (math_operations.find(c) != math_operations.end())
        return true;
    cout << "Error: not correct operation. Try again: " << endl;
    return false;
}

int main() {
    set<char> math_operations = {'+', '-', '*', '/'};
    string a, b; long double result = 0; bool flag = false; string temp;

    cout << "Enter 1 integer: "; cin >> a;
    cout << "Enter 2 integer: "; cin >> b;

    long long res1;
    long long res2;

    while (true) {
        try {
            res1 = stoll(a);
            res2 = stoll(b);
            break;
        } catch (...) {
            cout << "Error: invalid integer. Try again." << endl;
        }
        cout << "Enter 1 integer: "; cin >> a;
        cout << "Enter 2 integer: "; cin >> b;
    }

    while (!flag)  {
        cout << "Enter the certain operation (+ or - or * or /): "; cin >> temp;
        flag = operation_checker(temp[0], math_operations);
    }


    switch (temp[0]) {
        case '+': result = res1 + res2; cout << "Result: " << result << endl; break;
        case '-': result = res1 - res2; cout << "Result: " << result << endl; break;
        case '*': result = res1 * res2; cout << "Result: " << result << endl; break;
        case '/':
            if (stoi(b) != 0) {
                result = static_cast<long double>(res1) / static_cast<long double>(res2);
                cout << "Result: " << result << endl;
                break;
            }
        cout << "Error: invalid integer (the second integer is 0)" << endl;
        default: break;
    }
}