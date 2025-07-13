#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <windows.h>

// Function to set console colors
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to clear screen
void clearScreen() {
    system("cls");
}

// Function to print centered text
void printCentered(const std::string& text, int width = 60) {
    int textLength = static_cast<int>(text.length());
    if (textLength >= width) {
        // If text is too long, just print it as is
        std::cout << text << std::endl;
        return;
    }
    
    int padding = (width - textLength) / 2;
    std::cout << std::string(padding, ' ') << text << std::endl;
}

// Function to print header
void printHeader() {
    clearScreen();
    setColor(11); // Light cyan
    std::cout << "================================================================\n";
    printCentered("                    PAY CALCULATOR 2025                    ");
    std::cout << "================================================================\n";
    setColor(7); // White
    printCentered("  Professional Pay Calculator with Tax Calculations         ");
    printCentered("  Calculate Gross Pay, Net Pay, and Detailed Breakdowns    ");
    std::cout << "================================================================\n\n";
}

// Function to print main menu
void printMainMenu() {
    setColor(14); // Yellow
    std::cout << "+--------------------------------------------------------------+\n";
    std::cout << "|                        MAIN MENU                            |\n";
    std::cout << "+--------------------------------------------------------------+\n";
    setColor(7); // White
    std::cout << "|  1. Calculate Pay (New Calculation)                         |\n";
    std::cout << "|  2. View Help & Instructions                                |\n";
    std::cout << "|  3. About This Program                                      |\n";
    std::cout << "|  4. Exit Program                                            |\n";
    setColor(14); // Yellow
    std::cout << "+--------------------------------------------------------------+\n";
    setColor(7); // White
}

// Function to print calculation menu
void printCalculationMenu() {
    setColor(10); // Green
    std::cout << "+--------------------------------------------------------------+\n";
    std::cout << "|                    CALCULATION TYPE                         |\n";
    std::cout << "+--------------------------------------------------------------+\n";
    setColor(7); // White
    std::cout << "|  1. Gross Pay Only (Before Taxes)                           |\n";
    std::cout << "|  2. Net Pay Only (After Taxes & Deductions)                 |\n";
    std::cout << "|  3. Complete Breakdown (Gross + Net + Details)              |\n";
    std::cout << "|  4. Back to Main Menu                                       |\n";
    setColor(10); // Green
    std::cout << "+--------------------------------------------------------------+\n";
    setColor(7); // White
}

// Function to get main menu choice
int getMainMenuChoice() {
    int choice;
    while (true) {
        std::cout << "\n  Enter your choice (1-4): ";
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 4) {
            setColor(12); // Red
            std::cout << "  [!] Please enter a number between 1 and 4.\n";
            setColor(7); // White
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return choice;
}

// Function to get calculation menu choice
int getCalculationMenuChoice() {
    int choice;
    while (true) {
        std::cout << "\n  Enter your choice (1-4): ";
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 4) {
            setColor(12); // Red
            std::cout << "  [!] Please enter a number between 1 and 4.\n";
            setColor(7); // White
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return choice;
}

// Function to get validated user input for hours and pay rate
void getUserInput(double &hours, double &rate, int &period) {
    setColor(11); // Light cyan
    std::cout << "\n+--------------------------------------------------------------+\n";
    std::cout << "|                    ENTER PAY INFORMATION                    |\n";
    std::cout << "+--------------------------------------------------------------+\n";
    setColor(7); // White
    
    while (true) {
        std::cout << "\n  Hours worked: ";
        std::cin >> hours;
        if (std::cin.fail() || hours < 0) {
            setColor(12); // Red
            std::cout << "  [!] Please enter a valid non-negative number for hours.\n";
            setColor(7); // White
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    
    while (true) {
        std::cout << "  Pay per hour: $";
        std::cin >> rate;
        if (std::cin.fail() || rate < 0) {
            setColor(12); // Red
            std::cout << "  [!] Please enter a valid non-negative number for pay rate.\n";
            setColor(7); // White
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    
    while (true) {
        std::cout << "  Pay period:\n";
        std::cout << "     1. Weekly\n";
        std::cout << "     2. Bi-weekly\n";
        std::cout << "     Enter choice (1 or 2): ";
        std::cin >> period;
        if (std::cin.fail() || (period != 1 && period != 2)) {
            setColor(12); // Red
            std::cout << "  [!] Please enter 1 for weekly or 2 for bi-weekly.\n";
            setColor(7); // White
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

// Function to get optional deductions
void getDeductions(double &retirement401k, double &healthInsurance) {
    setColor(10); // Green
    std::cout << "\n+--------------------------------------------------------------+\n";
    std::cout << "|                  OPTIONAL DEDUCTIONS                        |\n";
    std::cout << "+--------------------------------------------------------------+\n";
    setColor(7); // White
    
    while (true) {
        std::cout << "\n  401(k) contribution percentage (0-50): ";
        std::cin >> retirement401k;
        if (std::cin.fail() || retirement401k < 0 || retirement401k > 50) {
            setColor(12); // Red
            std::cout << "  [!] Please enter a percentage between 0 and 50.\n";
            setColor(7); // White
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    
    while (true) {
        std::cout << "  Health insurance cost per pay period: $";
        std::cin >> healthInsurance;
        if (std::cin.fail() || healthInsurance < 0) {
            setColor(12); // Red
            std::cout << "  [!] Please enter a valid non-negative amount.\n";
            setColor(7); // White
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

// Function to display gross pay result
void displayGrossPay(double grossPay, int period) {
    setColor(14); // Yellow
    std::cout << "\n+--------------------------------------------------------------+\n";
    std::cout << "|                        GROSS PAY                            |\n";
    std::cout << "+--------------------------------------------------------------+\n";
    setColor(7); // White
    
    if (period == 1) {
        std::cout << "  Your weekly gross pay is: ";
        setColor(10); // Green
        std::cout << "$" << std::fixed << std::setprecision(2) << grossPay << "\n";
        setColor(7); // White
    } else {
        std::cout << "  Your bi-weekly gross pay is: ";
        setColor(10); // Green
        std::cout << "$" << std::fixed << std::setprecision(2) << grossPay << "\n";
        setColor(7); // White
    }
}

// Function to display net pay result
void displayNetPay(double netPay, int period) {
    setColor(14); // Yellow
    std::cout << "\n+--------------------------------------------------------------+\n";
    std::cout << "|                         NET PAY                             |\n";
    std::cout << "+--------------------------------------------------------------+\n";
    setColor(7); // White
    
    if (period == 1) {
        std::cout << "  Your weekly net pay is: ";
        setColor(10); // Green
        std::cout << "$" << std::fixed << std::setprecision(2) << netPay << "\n";
        setColor(7); // White
    } else {
        std::cout << "  Your bi-weekly net pay is: ";
        setColor(10); // Green
        std::cout << "$" << std::fixed << std::setprecision(2) << netPay << "\n";
        setColor(7); // White
    }
}

// Function to display detailed breakdown
void displayBreakdown(double grossPay, int period, double retirement401k, double healthInsurance) {
    double federalTax = calculateFederalTax(grossPay, period);
    double socialSecurity = grossPay * 0.062;
    double medicare = grossPay * 0.0145;
    double retirementDeduction = grossPay * (retirement401k / 100.0);
    double netPay = calculateAfterTax(grossPay, period, retirement401k, healthInsurance);
    
    setColor(11); // Light cyan
    std::cout << "\n+--------------------------------------------------------------+\n";
    std::cout << "|                    DETAILED BREAKDOWN                       |\n";
    std::cout << "+--------------------------------------------------------------+\n";
    setColor(7); // White
    
    std::cout << "  +----------------------------------------------------------+\n";
    std::cout << "  |  Gross Pay:                    $" << std::fixed << std::setprecision(2) << std::setw(10) << grossPay << "  |\n";
    std::cout << "  +----------------------------------------------------------+\n";
    std::cout << "  |  DEDUCTIONS:                                              |\n";
    std::cout << "  |  Federal Income Tax:           $" << std::setw(10) << federalTax << "  |\n";
    std::cout << "  |  Social Security (6.2%):       $" << std::setw(10) << socialSecurity << "  |\n";
    std::cout << "  |  Medicare (1.45%):             $" << std::setw(10) << medicare << "  |\n";
    if (retirement401k > 0) {
        std::cout << "  |  401(k) Contribution (" << std::setw(2) << retirement401k << "%):    $" << std::setw(10) << retirementDeduction << "  |\n";
    }
    if (healthInsurance > 0) {
        std::cout << "  |  Health Insurance:             $" << std::setw(10) << healthInsurance << "  |\n";
    }
    std::cout << "  +----------------------------------------------------------+\n";
    setColor(10); // Green
    std::cout << "  |  NET PAY:                      $" << std::setw(10) << netPay << "  |\n";
    setColor(7); // White
    std::cout << "  +----------------------------------------------------------+\n";
}

// Function to show help
void showHelp() {
    clearScreen();
    setColor(11); // Light cyan
    std::cout << "================================================================\n";
    printCentered("                        HELP & INSTRUCTIONS                    ");
    std::cout << "================================================================\n\n";
    setColor(7); // White
    
    std::cout << "  HOW TO USE THIS PROGRAM:\n\n";
    std::cout << "  1. Select 'Calculate Pay' from the main menu\n";
    std::cout << "  2. Choose your calculation type:\n";
    std::cout << "     * Gross Pay: Shows your pay before taxes\n";
    std::cout << "     * Net Pay: Shows your pay after taxes and deductions\n";
    std::cout << "     * Complete Breakdown: Shows both with detailed analysis\n\n";
    std::cout << "  3. Enter your work information:\n";
    std::cout << "     * Hours worked\n";
    std::cout << "     * Pay per hour\n";
    std::cout << "     * Pay period (weekly or bi-weekly)\n\n";
    std::cout << "  4. If calculating net pay, enter optional deductions:\n";
    std::cout << "     * 401(k) contribution percentage\n";
    std::cout << "     * Health insurance costs\n\n";
    std::cout << "  TIPS:\n";
    std::cout << "  * Use 0 for deductions you don't have\n";
    std::cout << "  * This calculator uses 2024 federal tax rates\n";
    std::cout << "  * Texas has no state income tax\n\n";
    
    setColor(14); // Yellow
    std::cout << "  Press Enter to return to main menu...";
    setColor(7); // White
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Function to show about
void showAbout() {
    clearScreen();
    setColor(11); // Light cyan
    std::cout << "================================================================\n";
    printCentered("                        ABOUT PROGRAM                         ");
    std::cout << "================================================================\n\n";
    setColor(7); // White
    
    std::cout << "  PAY CALCULATOR 2025\n\n";
    std::cout << "  Version: 2.0\n";
    std::cout << "  Language: C++\n";
    std::cout << "  Features:\n";
    std::cout << "  * Gross and net pay calculations\n";
    std::cout << "  * Federal tax estimation\n";
    std::cout << "  * Social Security and Medicare calculations\n";
    std::cout << "  * 401(k) and health insurance deductions\n";
    std::cout << "  * Professional menu interface\n\n";
    std::cout << "  Tax Information:\n";
    std::cout << "  * Uses 2024 federal tax brackets\n";
    std::cout << "  * Social Security: 6.2% (up to annual limit)\n";
    std::cout << "  * Medicare: 1.45% (no limit)\n";
    std::cout << "  * Texas: No state income tax\n\n";
    
    setColor(14); // Yellow
    std::cout << "  Press Enter to return to main menu...";
    setColor(7); // White
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Function to perform calculation
void performCalculation() {
    double hours = 0.0, rate = 0.0;
    int period = 1;
    
    getUserInput(hours, rate, period);
    
    printCalculationMenu();
    int calculationType = getCalculationMenuChoice();
    
    if (calculationType == 4) {
        return; // Back to main menu
    }
    
    double grossPay = calculateGrossPay(hours, rate, period);
    
    if (calculationType == 1) {
        // Gross pay only
        displayGrossPay(grossPay, period);
    } else {
        // Net pay or both - need deduction info
        double retirement401k = 0.0, healthInsurance = 0.0;
        getDeductions(retirement401k, healthInsurance);
        
        if (calculationType == 2) {
            // Net pay only
            double netPay = calculateAfterTax(grossPay, period, retirement401k, healthInsurance);
            displayNetPay(netPay, period);
        } else {
            // Complete breakdown
            displayBreakdown(grossPay, period, retirement401k, healthInsurance);
        }
    }
    
    setColor(14); // Yellow
    std::cout << "\n  Press Enter to continue...";
    setColor(7); // White
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main() {
    int choice;
    
    do {
        printHeader();
        printMainMenu();
        choice = getMainMenuChoice();
        
        switch (choice) {
            case 1:
                performCalculation();
                break;
            case 2:
                showHelp();
                break;
            case 3:
                showAbout();
                break;
            case 4:
                setColor(11); // Light cyan
                std::cout << "\n  Thank you for using Pay Calculator 2025!\n";
                std::cout << "  Goodbye!\n\n";
                setColor(7); // White
                break;
        }
    } while (choice != 4);
    
    return 0;
} 