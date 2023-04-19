#include <iostream>

void print_digits_reversed(int n) {
    if (n < 10) {
        std::cout << n << ' ';
    } else {
        std::cout << n % 10 << ' ';
        print_digits_reversed(n / 10);
    }
}

int main() {
    int n;
    std::cin >> n;
    print_digits_reversed(n);
    std::cout << '\n';
    return 0;
}