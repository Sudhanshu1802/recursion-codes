#include<iostream>
using namespace std;
int main() {
    char ch;
    while (true) {
        cin >> ch;
        if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%') {
            int n1, n2;
            cin >> n1 >> n2;
            if (ch == '+')  cout << n1 + n2 << "\n";

            else if (ch == '-') cout << n1 - n2 << "\n";

            else if (ch == '*') cout << n1 * n2 << "\n";

            else if (ch == '/') cout << n1 / n2 << "\n";

            else if (ch == '%') cout << n1 % n2 << "\n";
        }
        else if (ch == 'x' || ch == 'X') break;
        else cout << "Invalid operation. Try again.\n";
    }
    return 0;
}