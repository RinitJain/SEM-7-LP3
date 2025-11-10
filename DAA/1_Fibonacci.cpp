#include<iostream>
using namespace std;

void fibo_recursive(int n) {
    static int a = 0, b = 1;
    if (n > 0) {
        cout << a << " ";
        int c = a + b;
        a = b;
        b = c;
        fibo_recursive(n - 1);
    }
}

void fibo_iterative(int n) {
    int a = 0, b = 1;
    
    for(int i = 0; i < n; i++) {
        cout << a << " ";
        int c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Sequence (Recursive): ";
    fibo_recursive(n);
    cout << endl;

    cout << "Fibonacci Sequence (Iterative): ";
    fibo_iterative(n);

    return 0;
}