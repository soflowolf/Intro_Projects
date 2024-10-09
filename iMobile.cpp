/* iMobileBillCalculator.cpp
 This program calculates a customers monthly bill.
 It prompts the user for the customers plan and the number
 of gigabytes of data used. It should then calculate and display the total amount due
 */

/*
    1. INPUT - Customers plan, number of gigabytes of data used.
 
    2. Processing - Calculate total monthly bill using user inoputs.
                    Verify it is withing valid menu options, and valid values for
                    data.
    3. Output - Display the monthy amount due formatted with a precision of 2 decimal place value.
 */


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()  {
    
//variables
    
    int number_Plan;       //Save which number plan they choose
            
    double gigabytes,       // save how many gigabytes were used
            monthly_Total;  //monthly total amount
    
    
//Title
        cout << "iMobile Bill Calculator ... " << endl << endl;
    
// Prompt user to make selection of their subscription package and display options
        cout << "Select a subscription package: " << endl;
    
        cout << "\t\t1. Package A" << endl;
    
        cout << "\t\t2. Package B" << endl;
        
        cout << "\t\t3. Package C" << endl;

    //Get user input with variables that are defined
    
    cout <<"Package: ";
    cin >> number_Plan;
    
    cout << endl;
    

        
    cout << "How many gigabytes of data were used? ";
    cin >> gigabytes;
    cout << endl << endl;
    
    // making sure gigabytes input is valid
    
if (gigabytes < 0)
{
    cout << "Error ... invalid gigabytes. Try again.";
    
    cin >> gigabytes;
}
// Determine plan and its calculations to display monthly after
    
    if (number_Plan == 1)
    {
        monthly_Total = ( gigabytes - 4 ) * 10 + 39.99;
        
        cout <<"The total amount due is " << "$" << fixed << setprecision(2) << monthly_Total << endl;
    }
        else if ( number_Plan == 2 )
        {
            monthly_Total = ( (gigabytes - 8) * 5 + 59.99 );
            
            cout << "The total amount due is " << "$" << fixed <<setprecision(2) << monthly_Total << endl;
            
        }
            else if  ( number_Plan == 3)
            {
                monthly_Total = 69.99;
                
                cout << "The total amount due is " << "$" << fixed << setprecision(2) << monthly_Total << endl;
            }
    
    else
        
        cout << endl << "Error ... invalid package. Try again." << endl;
        
        
        
        
    return 0;
}
