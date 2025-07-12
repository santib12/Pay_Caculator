#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

void printHeader() {
    std::cout << "==============================================\n";
    std::cout << "           PAY CALCULATOR 2025                \n";
    std::cout << "==============================================\n";
    std::cout << "This program calculates your gross pay based on\n";
    std::cout << "the hours you worked and your hourly wage. You  \n";
    std::cout << "can view your weekly or bi-weekly earnings.     \n";
    std::cout << "(Taxes are not yet included in this version.)   \n";
    std::cout << "==============================================\n\n";
}

// Function to get validated user input for hours and pay rate
void getUserInput(double &hours, double &rate, int &period) {
    while (true) {
        std::cout << "> Enter hours worked: ";
        std::cin >> hours;
        if (std::cin.fail() || hours < 0) {
            std::cout << "  [!] Please enter a valid non-negative number for hours.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    while (true) {
        std::cout << "> Enter pay per hour: $";
        std::cin >> rate;
        if (std::cin.fail() || rate < 0) {
            std::cout << "  [!] Please enter a valid non-negative number for pay rate.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    while (true) {
        std::cout << "> Would you like to see your (1) weekly or (2) bi-weekly pay? Enter 1 or 2: ";
        std::cin >> period;
        if (std::cin.fail() || (period != 1 && period != 2)) {
            std::cout << "  [!] Please enter 1 for weekly or 2 for bi-weekly.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

// Function to calculate gross pay
double calculateGrossPay(double hours, double rate, int period) {
    if (period == 1) { // Weekly
        return hours * rate;
    } else { // Bi-weekly
        return hours * rate * 2;
    }
}

// Placeholder for future after-tax calculation
// double calculateAfterTax(double gross) {
//     // To be implemented later
//     return gross;
// }

int main() {
    printHeader();
    double hours = 0.0, rate = 0.0;
    int period = 1;
    getUserInput(hours, rate, period);
    double grossPay = calculateGrossPay(hours, rate, period);
    std::cout << "\n----------------------------------------------\n";
    if (period == 1) {
        std::cout << "  Your weekly gross pay is: $" << std::fixed << std::setprecision(2) << grossPay << "\n";
    } else {
        std::cout << "  Your bi-weekly gross pay is: $" << std::fixed << std::setprecision(2) << grossPay << "\n";
    }
    std::cout << "----------------------------------------------\n";
    std::cout << "Thank you for using Pay Calculator 2025!\n";
    return 0;
} 