#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>

void printHeader() {
    std::cout << "==============================================\n";
    std::cout << "           PAY CALCULATOR 2025                \n";
    std::cout << "==============================================\n";
    std::cout << "This program calculates your gross pay based on\n";
    std::cout << "the hours you worked and your hourly wage. You  \n";
    std::cout << "can view your weekly or bi-weekly earnings.     \n";
    std::cout << "Now with after-tax calculations!               \n";
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

// Function to get calculation type preference
int getCalculationType() {
    int choice;
    while (true) {
        std::cout << "\n> Choose calculation type:\n";
        std::cout << "  (1) Gross pay only (before taxes)\n";
        std::cout << "  (2) Net pay (after taxes and deductions)\n";
        std::cout << "  (3) Both gross and net pay\n";
        std::cout << "  Enter your choice (1, 2, or 3): ";
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 3) {
            std::cout << "  [!] Please enter 1, 2, or 3.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return choice;
}

// Function to get optional deductions
void getDeductions(double &retirement401k, double &healthInsurance) {
    std::cout << "\n--- Optional Deductions ---\n";
    
    while (true) {
        std::cout << "> Enter 401(k) contribution percentage (0-50): ";
        std::cin >> retirement401k;
        if (std::cin.fail() || retirement401k < 0 || retirement401k > 50) {
            std::cout << "  [!] Please enter a percentage between 0 and 50.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    
    while (true) {
        std::cout << "> Enter health insurance cost per pay period: $";
        std::cin >> healthInsurance;
        if (std::cin.fail() || healthInsurance < 0) {
            std::cout << "  [!] Please enter a valid non-negative amount.\n";
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

// Function to calculate federal income tax (simplified progressive)
double calculateFederalTax(double grossPay, int period) {
    // Convert to annual income for tax bracket calculation
    double annualIncome;
    if (period == 1) { // Weekly
        annualIncome = grossPay * 52;
    } else { // Bi-weekly
        annualIncome = grossPay * 26;
    }
    
    // Simplified 2024 federal tax brackets (single filer)
    double taxRate;
    if (annualIncome <= 11600) {
        taxRate = 0.10;
    } else if (annualIncome <= 47150) {
        taxRate = 0.12;
    } else if (annualIncome <= 100525) {
        taxRate = 0.22;
    } else if (annualIncome <= 191950) {
        taxRate = 0.24;
    } else if (annualIncome <= 243725) {
        taxRate = 0.32;
    } else if (annualIncome <= 609350) {
        taxRate = 0.35;
    } else {
        taxRate = 0.37;
    }
    
    return grossPay * taxRate;
}

// Function to calculate after-tax pay
double calculateAfterTax(double grossPay, int period, double retirement401k, double healthInsurance) {
    // Federal income tax
    double federalTax = calculateFederalTax(grossPay, period);
    
    // Social Security (6.2% up to limit)
    double socialSecurity = grossPay * 0.062;
    
    // Medicare (1.45%)
    double medicare = grossPay * 0.0145;
    
    // 401(k) contribution
    double retirementDeduction = grossPay * (retirement401k / 100.0);
    
    // Calculate net pay
    double netPay = grossPay - federalTax - socialSecurity - medicare - retirementDeduction - healthInsurance;
    
    return netPay;
}

// Function to display detailed breakdown
void displayBreakdown(double grossPay, int period, double retirement401k, double healthInsurance) {
    double federalTax = calculateFederalTax(grossPay, period);
    double socialSecurity = grossPay * 0.062;
    double medicare = grossPay * 0.0145;
    double retirementDeduction = grossPay * (retirement401k / 100.0);
    double netPay = calculateAfterTax(grossPay, period, retirement401k, healthInsurance);
    
    std::cout << "\n==============================================\n";
    std::cout << "              PAY BREAKDOWN                  \n";
    std::cout << "==============================================\n";
    std::cout << "  Gross Pay:                    $" << std::fixed << std::setprecision(2) << std::setw(10) << grossPay << "\n";
    std::cout << "  ----------------------------------------------\n";
    std::cout << "  DEDUCTIONS:\n";
    std::cout << "  Federal Income Tax:           $" << std::setw(10) << federalTax << "\n";
    std::cout << "  Social Security (6.2%):       $" << std::setw(10) << socialSecurity << "\n";
    std::cout << "  Medicare (1.45%):             $" << std::setw(10) << medicare << "\n";
    if (retirement401k > 0) {
        std::cout << "  401(k) Contribution (" << retirement401k << "%):    $" << std::setw(10) << retirementDeduction << "\n";
    }
    if (healthInsurance > 0) {
        std::cout << "  Health Insurance:             $" << std::setw(10) << healthInsurance << "\n";
    }
    std::cout << "  ----------------------------------------------\n";
    std::cout << "  NET PAY:                      $" << std::setw(10) << netPay << "\n";
    std::cout << "==============================================\n";
}

int main() {
    printHeader();
    double hours = 0.0, rate = 0.0;
    int period = 1;
    getUserInput(hours, rate, period);
    
    int calculationType = getCalculationType();
    double grossPay = calculateGrossPay(hours, rate, period);
    
    if (calculationType == 1) {
        // Gross pay only
        std::cout << "\n----------------------------------------------\n";
        if (period == 1) {
            std::cout << "  Your weekly gross pay is: $" << std::fixed << std::setprecision(2) << grossPay << "\n";
        } else {
            std::cout << "  Your bi-weekly gross pay is: $" << std::fixed << std::setprecision(2) << grossPay << "\n";
        }
        std::cout << "----------------------------------------------\n";
    } else {
        // Net pay or both - need deduction info
        double retirement401k = 0.0, healthInsurance = 0.0;
        getDeductions(retirement401k, healthInsurance);
        
        if (calculationType == 2) {
            // Net pay only
            double netPay = calculateAfterTax(grossPay, period, retirement401k, healthInsurance);
            std::cout << "\n----------------------------------------------\n";
            if (period == 1) {
                std::cout << "  Your weekly net pay is: $" << std::fixed << std::setprecision(2) << netPay << "\n";
            } else {
                std::cout << "  Your bi-weekly net pay is: $" << std::fixed << std::setprecision(2) << netPay << "\n";
            }
            std::cout << "----------------------------------------------\n";
        } else {
            // Both gross and net with breakdown
            displayBreakdown(grossPay, period, retirement401k, healthInsurance);
        }
    }
    
    std::cout << "Thank you for using Pay Calculator 2025!\n";
    return 0;
} 