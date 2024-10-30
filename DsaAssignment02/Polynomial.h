#pragma once
#include"Node.h"
using namespace std;

int power(int base, int exp);

class Polynomial {
private:
    Node* head;




public:
    Polynomial() : head(nullptr) {}

    void insertTerm(int coefficient, int exponent) {
        Node* newNode = new Node(coefficient, exponent);
        if (head == nullptr || head->exponent < exponent) {
            if (head && head->exponent == exponent) {
                head->coefficient += coefficient;
                if (head->coefficient == 0) {
                    head = head->next;
                }
                delete newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && current->next->exponent > exponent) {
            current = current->next;
        }

        if (current->next && current->next->exponent == exponent) {
            current->next->coefficient += coefficient;
            if (current->next->coefficient == 0) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "0" << endl;
            return;
        }

        Node* current = head;
        while (current) {
            if (current->coefficient > 0 && current != head) {
                cout << "+";
            }
            cout << current->coefficient << "x^" << current->exponent << " ";
            current = current->next;
        }
        cout << endl;
    }

    Polynomial operator+(const Polynomial& other) {
        Polynomial result;
        Node* p1 = this->head;
        Node* p2 = other.head;

        while (p1 != nullptr || p2 != nullptr) {
            if (p1 == nullptr) {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
            else if (p2 == nullptr) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }
            else if (p1->exponent == p2->exponent) {
                result.insertTerm(p1->coefficient + p2->coefficient, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->exponent > p2->exponent) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }
            else {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) {
        Polynomial result;
        Node* p1 = this->head;
        Node* p2 = other.head;

        while (p1 != nullptr || p2 != nullptr) {
            if (p1 == nullptr) {
                result.insertTerm(-p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
            else if (p2 == nullptr) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }
            else if (p1->exponent == p2->exponent) {
                result.insertTerm(p1->coefficient - p2->coefficient, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->exponent > p2->exponent) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }
            else {
                result.insertTerm(-p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) {
        Polynomial result;
        for (Node* p1 = this->head; p1 != nullptr; p1 = p1->next) {
            Polynomial temp;
            for (Node* p2 = other.head; p2 != nullptr; p2 = p2->next) {
                int newCoeff = p1->coefficient * p2->coefficient;
                int newExp = p1->exponent + p2->exponent;
                temp.insertTerm(newCoeff, newExp);
            }
            result = result + temp;
        }
        return result;
    }

    int evaluate(int x) {
        int result = 0;
        Node* current = head;
        while (current) {
            result += current->coefficient * power(x, current->exponent);
            current = current->next;
        }
        return result;
    }

    ~Polynomial() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp - 1);
}
