//
//  main.cpp
//  courseSummary
//
//  Created by Gerardo Cadagan on 10/15/24.
//
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main ()
{
    
    // File stream object and variable
    
    ifstream in_File;
    
    string file_Name, class_Name, professor_Name, term, student_Name;
    
    int option, student_Grade,num_Students;
    
    double highest_Grade, lowest_Grade, total_Grade;
    
    highest_Grade = 0;
    lowest_Grade = 100;
    total_Grade = 0;
    num_Students = 0;
    double average_Grade;
    average_Grade = total_Grade / num_Students;
    
    // implement do-while loop to execute selection atleast once.
    
    do
    {           // Display the user menu interface of options
        
        cout << "Course Summary App ... " << endl;
        cout <<endl;
        
        cout << "Choose one of the folowing options" << endl;
        
        cout << "\t\t1. Process Grades Summary report." << endl;
        cout << "\t\t2. Quit." << endl;
        
        // Allow for user input of selection from menu
        cout <<  "Option: ";
        cin >> option;
        cout << endl << endl;
        
            if ( option  < 1 || option > 2 )        // if expression evaluates to true loop back to top
                {
                    
                    cout << "Error ... Incorrect option. Try again." << endl;
                    cout << endl;
                    
                    continue;
                }
        
        
        
    

                        switch  ( option )
                            
                        {
                            case 1 :
                            {
                                cout << "Grades Summary Report ..." << endl;
                                cout << endl;
                                
                                cout << "Enter name of file: ";
                                
                                
                                cin >> file_Name;
                                
                                
                                in_File.open(file_Name);                //Open file
                                
                                if ( in_File )
                                {
                                    cout <<"--------------------------------------------------" << endl;
                                    cout << endl;
                                    
                                    getline(in_File, class_Name );      //Display first line course
                                    
                                    cout << class_Name << endl;
                                    cout << endl;
                                    
                                    getline (in_File, professor_Name);  // display second line professor name with term
                                    getline ( in_File, term);
                                    
                                    cout << professor_Name << setw(21) <<"Term: " << term << endl;
                                    cout << endl << endl;
                                    
                                    cout << "List of students" << endl;
                                    cout <<"--------------------------------------------------" << endl;
                                    
                                    while (getline(in_File, student_Name ))
                                    {
                                        num_Students++;
                                        
                                        in_File >> student_Grade;
                                        in_File.ignore();
                                       
                                        cout << setw(20) << left << student_Name << setw(20) << right << student_Grade << endl;
                                        cout << endl;
                                        
                                        if ( student_Grade > highest_Grade  )
                                        {
                                            
                                            highest_Grade = student_Grade;
                                            
                                        }
                                        if ( student_Grade < lowest_Grade )
                                        {
                                            lowest_Grade = student_Grade;
                                        }
                                        
                                        total_Grade += student_Grade;
                                        
                                        
                                    
                                        
                                    }
                                    
                                    cout << "Highest Grade: " << highest_Grade << endl;
                                    cout << "Lowest  Grade: " << lowest_Grade << endl;
                                    cout << "Average Grade: " << setprecision(1) << fixed << total_Grade / num_Students << endl;
                                    cout << endl;
                                    cout << "--------------------------------------------------" << endl;
                                    cout << endl;
                            
                                    in_File.close();
                                    
                                    
                                    
                                    
                                    
                                    
                                }
                                else
                                {
                                    cout << "Error cannot open " << file_Name << "." << endl;
                                    cout << endl;
                                }
                                
                                
                            }break;
                                
                            case 2:
                            {
                                cout << "Good Bye ... " << endl;
                                cout << endl;
                            }
                        }
                                
                        
        } while ( option != 2 );
        
        return 0;
    }
        
        
        
    
