#include <iostream>

int break_chocolate(int n, int m) {
    if (n <= 0 || m <= 0) {
        return 0;
    } else {
        return (n * m) - 1;
    }
}

int main() {
    std::cout << break_chocolate(5, 5) << std::endl; // 24
    std::cout << break_chocolate(7, 4) << std::endl; // 27
    std::cout << break_chocolate(1, 1) << std::endl; // 0
    std::cout << break_chocolate(0, 0) << std::endl; // 0
    std::cout << break_chocolate(6, 1) << std::endl; // 5
    return 0;
}