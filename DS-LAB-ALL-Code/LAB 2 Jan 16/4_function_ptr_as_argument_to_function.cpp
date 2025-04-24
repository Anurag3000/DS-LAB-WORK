#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

void operate(int x, int y, int (*func)(int, int)) {
    int result = func(x, y);
    cout << "Result: " << result << endl;
}

int main() {
    int a = 5, b = 3;
    operate(a, b, add);
    return 0;
}
