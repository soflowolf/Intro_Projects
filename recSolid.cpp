/* 
Author: Gerardo Cadagan

Date: 09/01/2024

Program: Rectangular Solid Geometry App

File: recSolid.cpp

This is a program that prompts the user for the height,
length and width of the rectangular solid. Calculates surface area 
and volume. Then displays results. 
*/

// Header File
#include <iostream>
using namespace std; 

int main()
{
    // variables
    double length, height,SurfaceArea,volume, width; 

    //  Intro 
    cout << "Rectangle Volume/Area Calculator!" << endl << endl; 

    // Prompting user for values  for caluclation later...
    cout << "Please enter rectanle's length...";  
    cin >> length;

    cout << "please enter rectangle's width...";
    cin >> width;

    cout << "Please enter rectangle's height...";
    cin >> height; 
   

    // Calculate Surface Area 
    SurfaceArea = (2 * length * height) + (2 * width * height) + (2 * width * length);

    //Display Surface area result
    cout << "The surface area is " << SurfaceArea << endl; 

    //Calculate volume
    volume = length + width * height; 

    //Display Voulme Result 
    cout << "The rectangle's volume is " << volume; 
   









  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
