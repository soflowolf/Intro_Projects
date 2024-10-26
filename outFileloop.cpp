#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main ()
{
    
    int num_Students, exam_Score, amount;
    amount = 0;
    string name;
    double sum_Score, avg_Score;
    sum_Score = 0;
    
    cout << "For how many students in the class? ";
    cin >> num_Students;
    cout << endl << endl;
    
    ofstream out_File("studentfile.txt");
    
    
    
    while ( amount < num_Students)
    {
        cout << "Enter a students name: ";
        cin.ignore();
        getline(cin, name);
        out_File << name;
        cout << endl;

        cout << "Enter student's score: ";
        cin >> exam_Score;
        out_File << exam_Score;
        cout << endl;
        cout << "writing to file " << name << ". " << "Student final grade is " << exam_Score << "." << endl;
        cout << endl;
        
        
        
        
        amount++;
        sum_Score += exam_Score;
    }
    
    avg_Score = sum_Score / num_Students;
    
    cout << "Class grade average is " << fixed << setprecision(1) << avg_Score << "." << endl;
    cout << "Writing to file class average." << endl;
    
    out_File << avg_Score;
    
    out_File.close();
    
    cout << "Finished processing. " << endl;
    cout << endl;
    
    
    
    
    
    
    
    
    return 0;
    
}
