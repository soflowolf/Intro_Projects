/*
Authors: Gerardo Cadagan
         Ashley Bessard
         Patrick Jean-Louis
         Angelus Perez
Date:  December 4, 2024
Program: Lost in the Everglades
File: evergladesRPG.cpp
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Constants
const int TABLE_SIZE = 5;
const char RANGER = 'R';
const char TOURISTS = 'T';
const char UNKNOWN = '*';

// Danger symbols and names
const string DANGER_NAMES[] = { "Hungry Alligator", "Swarm of Giant Mosquitos", "Venomous Spider", "Python" };
const char DANGER_SYMBOLS[] = { 'A', 'M', 'S', 'P' };
const int NUM_DANGERS = 10;

// Function prototypes
void displayMenu();
void showRules();
void initTable(char gameTable[][TABLE_SIZE], char dangerMap[][TABLE_SIZE]);
void printTable(char gameTable[][TABLE_SIZE]);
void placeDangers(char dangerMap[][TABLE_SIZE]);
bool moveRanger(char gameTable[][TABLE_SIZE], char dangerMap[][TABLE_SIZE], int &rangerRow, int &rangerCol, int &gongsLeft);
void resolveDanger(char gameTable[][TABLE_SIZE], char dangerMap[][TABLE_SIZE], int rangerRow, int rangerCol, int &gongsLeft);

// Randomly place dangers
void placeDangers(char dangerMap[][TABLE_SIZE])
{
    int count = 0;
    while (count < NUM_DANGERS)
    {
        int row = rand() % TABLE_SIZE;
        int col = rand() % TABLE_SIZE;
        if ((row == 0 && col == 0) || (row == 4 && col == 4) || dangerMap[row][col] != UNKNOWN)
            continue;

        dangerMap[row][col] = DANGER_SYMBOLS[rand() % 4];
        count++;
    }
}

// Display menu
void displayMenu()
{
    cout << "\n    Lost in the Everglades ...\n\n";
    cout << "1. See Rules" << endl;
    cout << "2. Play Game" << endl;
    cout << "3. Quit" << endl;
    cout << "\nEnter your choice: ";
}

// Show game rules
void showRules()
{
    cout << "\n--- Rules of the Game ---\n\n";
    cout << "1. The game takes place on a 5x5 grid." << endl;
    cout << "2. The ranger (R) starts at the top-left (0,0), and the tourists (T) are at the bottom-right (4,4)." << endl;
    cout << "3. Move the ranger to reach the tourists before running out of gongs." << endl;
    cout << "4. Each move costs gongs, and encounters with dangers will also cost gongs.\n\n";
    cout << "   - Free cell: 1 gong." << endl;
    cout << "   - Wait (danger): 5 gongs." << endl;
    cout << "   - Fight (win): 2 gongs." << endl;
    cout << "   - Fight (lose): 3 gongs." << endl;
    cout << "\nGood luck!" << endl;
}


// Initialize game board and dangers
void initTable(char gameTable[][TABLE_SIZE], char dangerMap[][TABLE_SIZE])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        for (int j = 0; j < TABLE_SIZE; j++)
        {
            gameTable[i][j] = UNKNOWN;
            dangerMap[i][j] = UNKNOWN;
        }
    }
    gameTable[0][0] = RANGER;
    gameTable[4][4] = TOURISTS;
    placeDangers(dangerMap);
}

// Print the game board
void printTable(char gameTable[][TABLE_SIZE])
{
    cout << setw(6) << "0" << setw(4) << "1" << setw(4) << "2" << setw(4) << "3" << setw(4) << "4" << endl;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << i << "  | ";
        for (int j = 0; j < TABLE_SIZE; j++)
        {
            cout << gameTable[i][j] << " | ";
        }
        cout << endl;
    }
}

// Handle ranger movement
bool moveRanger(char gameTable[][TABLE_SIZE], char dangerMap[][TABLE_SIZE], int &rangerRow, int &rangerCol, int &gongsLeft)
{
    int newRow = -1, newCol = -1;

    cout << "Enter next cell (row and col, separated by a space): ";
    cin >> newRow >> newCol;

    // Validate input
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n'); // Discard invalid input
        return false;
    }

    // Validate movement logic
    if (newRow >= 0 && newRow < TABLE_SIZE && newCol >= 0 && newCol < TABLE_SIZE &&
        ((abs(newRow - rangerRow) == 1 && newCol == rangerCol) || (abs(newCol - rangerCol) == 1 && newRow == rangerRow)))
    {
        gameTable[rangerRow][rangerCol] = ' '; // Clear old position
        rangerRow = newRow;
        rangerCol = newCol;
        gameTable[rangerRow][rangerCol] = RANGER; // Set new position

        if (dangerMap[rangerRow][rangerCol] == UNKNOWN)
        {
            cout << "---> Cell (" << newRow << "," << newCol << ") is Free... You Advance!\n\n";
            gongsLeft--;
        }
        else
        {
            resolveDanger(gameTable, dangerMap, rangerRow, rangerCol, gongsLeft);
        }
        return true;
    }

    return false; // Invalid move
}

// Resolve a danger encounter
void resolveDanger(char gameTable[][TABLE_SIZE], char dangerMap[][TABLE_SIZE], int rangerRow, int rangerCol, int &gongsLeft)
{
    char danger = dangerMap[rangerRow][rangerCol];
    string dangerName;

    for (int i = 0; i < 4; i++)
    {
        if (DANGER_SYMBOLS[i] == danger)
        {
            dangerName = DANGER_NAMES[i];
            break;
        }
    }

    cout << "---> Watch out! There is a " << dangerName << " ahead.\n\n";
    cout << "Choose your next move\n";

    int choice;
    do
    {
        // menu to allow user to react to danger
        cout << setw(32) << "1. Wait until it leaves.\n";
        cout << setw(20) << "2. Fight it.\n";
        cout << "Move: ";
        cin >> choice;
        cout << endl;
    } while (choice != 1 && choice != 2);

    if (choice == 1)
    {
        cout << "---> The " << dangerName << " is gone... You Advance!\n\n";
        gongsLeft -= 5;
    }
    else if (choice == 2)
    {
        int fightOutcome = rand() % 2;
        if (fightOutcome == 1)
        {
            cout << "---> You fight the " << dangerName << " and win... You Advance!\n\n";
            gongsLeft -= 2;
            dangerMap[rangerRow][rangerCol] = UNKNOWN; // Danger resolved
        }
        else
        {
            cout << "---> You fight the " << dangerName << " and lose... Retreat!\n\n";
            gameTable[rangerRow][rangerCol] = RANGER; // Reset position
            gongsLeft -= 3;
        }
    }
    else
    {
        // input validation
        cout << "Invalid choice. Please try again.\n";
    }
}

int main()
{
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    char gameTable[TABLE_SIZE][TABLE_SIZE];
    char dangerMap[TABLE_SIZE][TABLE_SIZE];
    int rangerRow = 0, rangerCol = 0; // Ranger's initial position
    int gongsLeft = 12;              // Time (gongs)
    int choice;

    // start of loop
    while (true)
    {
        displayMenu();
        cin >> choice;

        if (choice == 1)
        {
            //  uses function to show rules
            showRules();
        }
        else if (choice == 2)
        {
            // Start the game
            initTable(gameTable, dangerMap);
            cout << "\nWelcome to Lost in the Everglades!\n";
            cout << "Rescue the tourists before time runs out. Good luck!\n\n";

            // resets game stats if the loop is repeated and the user decides to play the game again
            gongsLeft = 12;
            rangerRow = 0;
            rangerCol = 0;

            while (true)
            {
                // prints how many gongs are left
                printTable(gameTable);
                cout << "\nGongs Left: " << gongsLeft << endl;

                // Check win/loss conditions
                if (gongsLeft <= 0)
                {
                    cout << "\nYou ran out of time! The tourists are lost forever...\n";
                    break;
                }
                if (rangerRow == 4 && rangerCol == 4)
                {
                    cout << "\nCongratulations! You rescued the tourists!\n";
                    break;
                }

                if (!moveRanger(gameTable, dangerMap, rangerRow, rangerCol, gongsLeft))
                {
                    cout << "\nInvalid move. Try again.\n\n";
                }
            }
        }
        else if (choice == 3)
        {
            // allows user to break loop and leave game
            cout << "\nThank you for playing Lost in the Everglades. Goodbye!\n";
            break;
        }
        else
        {
            // input validation
            cout << "\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}
