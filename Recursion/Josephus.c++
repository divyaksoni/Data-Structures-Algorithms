#include <iostream>
using namespace std;

// Recursive function to find the Josephus position
int josephus(int n, int k) {
    // Base case: when only one person is left
    if (n == 1)
        return 1;
    
    // The position returned by josephus(n - 1, k) is adjusted
    // because the recursive call josephus(n - 1, k) considers
    // the position starting from 1 in the reduced circle.
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    cout << josephus(n, k) << endl;
    
    return 0;
}
