    #include "generator.h"
#include <random>
#include <stdexcept>
#include <string>

std::string generatePassword(int length) {
    if (length < 1) {
        throw std::invalid_argument("Password length must be positive");
    }

    const std::string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(
        0, static_cast<int>(chars.size()) - 1
    );

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += chars[dist(gen)];
    }

    return password;
}