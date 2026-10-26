#include <iostream>
#include <fstream>
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

        std::ofstream file("password.txt");

        if (file.is_open()) {
            file << password << '\n';
            file.close();
            std::cout << "Password saved to password.txt\n";
        }
        else {
            std::cout << "Error: Could not save password to file.\n";
        }

        std::cout << "\nGenerated password: " << password << '\n';
        std::cout << "Password strength: "
                  << checkPasswordStrength(password) << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}