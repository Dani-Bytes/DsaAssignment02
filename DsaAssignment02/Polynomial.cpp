#include "Polynomial.h"
int main() {
    Polynomial p1, p2;
    char choice;
    int numTerms;

    do {
        cout << "\nPolynomial Operations Menu:\n";
        cout << "1. Input Polynomial 1\n";
        cout << "2. Input Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Subtract Polynomials\n";
        cout << "7. Multiply Polynomials\n";
        cout << "8. Evaluate Polynomial 1\n";
        cout << "9. Exit\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Enter the number of terms for Polynomial 1: ";
            cin >> numTerms;
            for (int i = 0; i < numTerms; ++i) {
                int coeff, exp;
                cout << "Enter coefficient and exponent for term " << (i + 1) << ": ";
                cin >> coeff >> exp;
                p1.insertTerm(coeff, exp);
            }
            break;
        case '2':
            cout << "Enter the number of terms for Polynomial 2: ";
            cin >> numTerms;
            for (int i = 0; i < numTerms; ++i) {
                int coeff, exp;
                cout << "Enter coefficient and exponent for term " << (i + 1) << ": ";
                cin >> coeff >> exp;
                p2.insertTerm(coeff, exp);
            }
            break;
        case '3':
            cout << "Polynomial 1: ";
            p1.display();
            break;
        case '4':
            cout << "Polynomial 2: ";
            p2.display();
            break;
        case '5': {
            Polynomial sum = p1 + p2;
            cout << "Sum: ";
            sum.display();
            break;
        }
        case '6': {
            Polynomial diff = p1 - p2;
            cout << "Difference: ";
            diff.display();
            break;
        }
        case '7': {
            Polynomial product = p1 * p2;
            cout << "Product: ";
            product.display();
            break;
        }
        case '8': {
            int x;
            cout << "Enter a value for x to evaluate Polynomial 1: ";
            cin >> x;
            cout << "Evaluation of Polynomial 1 at x = " << x << ": " << p1.evaluate(x) << endl;
            break;
        }
        case '9':
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
            break;
        }
    } while (choice != '9');

    return 0;
}