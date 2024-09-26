/*
 
Gerardo Cadagan
 
loanCalculator.cpp
 
 This program prompts the user for the loan amount, annual interest rate, and term of the loan (in years) and displays the expected monthly payment, total amount to be paid, and total interest to be paid.
 
 1.) Input
            - Loan Amount
            - Annual Interest Rate
            - Term Of The Loan (In years)
            - Borrowers Name
            - Loaning Institution Name
 2.) Processing
            -Get Loan Amount
            - Get Annual Interst Rate
            - Get Term Of Loan (In Years)
            -Get Borrowers Name & Loaning Institution Name
            - Calculate monthly payment using formula
            - Calculate Total Amount to be paid using mathematical expressions
            - Calculate Total Interest to be paid using mathematical expressions
            - Calculate number of payments using mathematical expressions
 3.) Output
            - Display Expected monthy payment
            - Display Total amount to be paid
            - Display Total interest to be paid
            - Loan payment summary report
 
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{

// Variables
    
    string borrower_Name,
            institution,
            date;
    
    int loan_Term,
        loan_Amount,
        num_Payments;
    
    double monthly_Payment,
            total_Amount_Paid,
            total_Interest_Paid,
            annual_Interest_Rate,
            monthly_Rate,
            formula_Rate;
            
    
// Title
    
    cout << "Loan Payment Calculator ... " << endl;
    cout << endl;

// Display and prompting user for inputs
    
    cout << "Please enter the following information: " << endl;
    cout << endl;
    
    cout << "Borrower's Name:" << "\t\t\t\t\t\t";
    getline (cin, borrower_Name);                   //Store string
    
    cout << "Loaning Institution:" << "\t\t\t\t\t";
    getline (cin, institution);                     //Store string
    cout << endl;
    
    cout << "Loan Amount ($):" << "\t\t\t\t\t\t";
    cin >> loan_Amount;
    
    cout << "Annual Interest Rate (%):" << "\t\t\t\t";
    cin >> annual_Interest_Rate;
    
    cout << "Term of Loan (years):" << "\t\t\t\t\t";
    cin >> loan_Term;
    
    cout << endl;
    
    cout << "Date of Report:" << "\t\t\t\t\t\t\t";
    cin.ignore();                                   // Clear leftover newline from cin >>
    getline (cin, date);
    
    cout << endl;
    
// Mark a dashed line to mark the start of the report from gathered inputs
    
    cout << "------------------------------------------------------" << endl;

// Report title
    cout << "Loan Payment Summary Report" << endl << endl;
    
// output data
    cout << institution << "\t\t\t\t\t\t\t" << borrower_Name << endl;
    cout << "Annual Interest Rate: " << annual_Interest_Rate << "%" << endl;
    cout << "Date: " << date << endl << endl;

// Defining variables for mathematical operations to process and display outputs
    
    monthly_Rate = annual_Interest_Rate / 12;
    
    num_Payments = loan_Term * 12;
    
    formula_Rate = annual_Interest_Rate / 12 / 100;
    
    monthly_Payment = ( formula_Rate * pow( 1 + formula_Rate, num_Payments ) / ( pow( 1 + formula_Rate, num_Payments ) - 1 ) ) * loan_Amount;
            
    total_Amount_Paid = monthly_Payment * num_Payments;
    
    total_Interest_Paid = total_Amount_Paid - loan_Amount;
    
// Display processing outputs to user for last parts of report
    
    cout << "Loan Amount:" << "\t\t\t\t\t\t\t\t$ " << fixed << showpoint << setprecision(2) << setw(10) << static_cast<double>(loan_Amount) << endl;
    
    cout << "Monthly Interest Rate:" << "\t\t\t\t\t\t " << fixed << showpoint << setprecision(2) <<setw(10) << monthly_Rate << "%" << endl;
    
    cout << "Number of Payments:" << "\t\t\t\t\t\t\t  " << setw(10) << num_Payments << endl;
    
    cout << "Monthly Payment:" << "\t\t\t\t\t\t\t$ " << fixed << showpoint << setprecision(2) << setw(10) << monthly_Payment << endl << endl;
    
    cout << "Total Amount to Pay:" << "\t\t\t\t\t\t$ " << fixed << showpoint << setprecision(2) << setw(10) << total_Amount_Paid << endl;
    
    cout << "Total Interest:" << "\t\t\t\t\t\t\t\t$ " << fixed << showpoint << setprecision(2) <<setw(10) << total_Interest_Paid << endl << endl;
    
    cout << "------------------------------------------------------" << endl << endl;
    
    
    
    return 0;
}
