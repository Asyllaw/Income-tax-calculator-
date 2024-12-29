#include <stdio.h>

// Function to calculate CRA
double calculateCRA(double grossIncome) {
    double cra = 200000 + (0.2 * grossIncome);
    return cra;
}

// Function to calculate taxable income
double calculateTaxableIncome(double grossIncome, double cra, double pension, double nhf) {
    double taxableIncome = grossIncome - cra - pension - nhf;
    return taxableIncome > 0 ? taxableIncome : 0; // Ensure taxable income is not negative
}

// Function to calculate tax using graduated rates
double calculateTax(double taxableIncome) {
    double tax = 0.0;

    if (taxableIncome > 3200000) {
        tax += (taxableIncome - 3200000) * 0.24;
        taxableIncome = 3200000;
    }
    if (taxableIncome > 1600000) {
        tax += (taxableIncome - 1600000) * 0.21;
        taxableIncome = 1600000;
    }
    if (taxableIncome > 1000000) {
        tax += (taxableIncome - 1000000) * 0.19;
        taxableIncome = 1000000;
    }
    if (taxableIncome > 500000) {
        tax += (taxableIncome - 500000) * 0.15;
        taxableIncome = 500000;
    }
    if (taxableIncome > 300000) {
        tax += (taxableIncome - 300000) * 0.11;
        taxableIncome = 300000;
    }
    if (taxableIncome > 0) {
        tax += taxableIncome * 0.07;
    }

    return tax;
}

int main() {
    double grossIncome, pension, nhf, cra, taxableIncome, taxPayable;

    // Input gross income and deductions
    printf("Enter your gross annual income (in ₦): ");
    scanf("%lf", &grossIncome);

    printf("Enter your annual pension contribution (in ₦): ");
    scanf("%lf", &pension);

    printf("Enter your annual NHF contribution (in ₦): ");
    scanf("%lf", &nhf);

    // Calculate CRA
    cra = calculateCRA(grossIncome);

    // Calculate Taxable Income
    taxableIncome = calculateTaxableIncome(grossIncome, cra, pension, nhf);

    // Calculate Tax
    taxPayable = calculateTax(taxableIncome);

    // Display Results
    printf("\n=== Tax Calculation Results ===\n");
    printf("Gross Income: ₦%.2lf\n", grossIncome);
    printf("Consolidated Relief Allowance (CRA): ₦%.2lf\n", cra);
    printf("Taxable Income: ₦%.2lf\n", taxableIncome);
    printf("Total Tax Payable: ₦%.2lf\n", taxPayable);

    return 0;
}￼Enter￼Enter
