#include <iostream>
#include <string>
#include <limits>

#include "generator.h"
#include "checker.h"

int main() {
    int length;

    std::cout << "=== Password Generator ===\n";
    std::cout << "Enter password length (minimum 8): ";

    if (!(std::cin >> length) || length < 8) {
        std::cout << "Invalid length. Enter a number of at least 8.\n";
        return 1;
    }

    try {
        std::string password = generatePassword(length);

        std::cout << "\nGenerated password: " << password << '\n';
        std::cout << "Password strength: "
                  << checkPasswordStrength(password) << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}