//  letterGradeGenerator
/* This program prompts a user for a first name, a last name and test score.
 Based on the score identifies a corresponding letter grade (A, B, C, D, or F)*/
//  Created by Gerardo Cadagan on 9/19/24.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {

    string name;
    int test_Score;
    
    
    // Title
    
        cout << "Letter Grade Generator ..." << endl << endl;
    
    //Get user input for name, save input as string value to use later
        cout << "Please enter your name: ";
        getline(cin, name);
    
    // Get user input for test score, save input and assign to variable
        cout << "Enter your numeric test score: ";
        cin >> test_Score;
    
    //make variables for if/else if/ else statements to be processed for result displayed to user
    
    const int A_Score = 90;
    const int B_Score = 80;
    const int C_Score = 70;
    const int D_Score = 60;
    
    // create if-else if statement for result to display grade to user
            if (test_Score < 0 || test_Score > 100)
                cout << name << " you entered incorrect grade score." << endl;
        
                else if (test_Score >= A_Score)
                    cout << name << " your grade is A." << endl;
    
                    else if (test_Score >= B_Score)
                        cout << name << " your grade is B." << endl;
    
                        else if (test_Score >= C_Score)
                            cout << name << " your grade is C." << endl;
                            
                            else if (test_Score >= D_Score)
                                cout << name << " your grade is D." << endl;
            else
                cout << name << " your grade is F." << endl;
                            
    
        
        
    
return 0;
}
