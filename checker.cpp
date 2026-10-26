#include "checker.h"

#include <cctype>
#include <string>

std::string checkPasswordStrength(const std::string& password) {
    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (unsigned char ch : password) {
        if (std::islower(ch)) {
            hasLower = true;
        } else if (std::isupper(ch)) {
            hasUpper = true;
        } else if (std::isdigit(ch)) {
            hasDigit = true;
        } else {
            hasSpecial = true;
        }
    }

    int score = 0;

    if (password.length() >= 8) score++;
    if (hasLower) score++;
    if (hasUpper) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    if (password.length() < 8) {
        return "Weak: password must contain at least 8 characters";
    }

    if (score <= 2) return "Weak";
    if (score <= 4) return "Medium";

    return "Strong";
}