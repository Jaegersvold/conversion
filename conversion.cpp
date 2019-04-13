// Joe Rensvold
// CSCI 201
// Section 1
// Spring 2019
// Homework 3
// DATE

/*
    This program will convert a number input by the
    user from one base to a different base
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int startBase;       // This variable represents the starting base of the user entered number
    int numToConvert;    // This variable represents the number the user has entered to convert
    int endBase;         // This variable represents the ending base of the user entered number
    int workingNum;      // This variable represents the number that is being deconstructed from the number to convert
    int digitPlace;      // This variable represents the place of the current digit for the resulting converted number
    int buildingNum = 0; // This variable represents the number that is being built into the resulting converted number
    int convertedNum;    // This variable represents the fully converted number
    int currentDigit;    // This variable represents the current digit value of the resulting converted number

    // Welcome the user to the program and
    // ask for a starting base to convert from
    cout << "Welcome to the Base Conversion program!"        << endl;
    cout << "Please input a base to convert from"            << endl;
    cout << "The starting base needs to be between 2 and 10" << endl;
    cin  >> startBase;

    // If the user does not enter a base within the parameters
    // display an error message to the user and prompt them
    // for a proper entry
    while (startBase < 2 || startBase > 10)
    {
        cout << "The starting base needs to be between 2 and 10" << endl;
        cout << "Please input a base to convert from"            << endl;
        cin  >> startBase;
    }

    // Ask the user for a number to convert
    cout << "Please input a number to convert"                           << endl;
    cout << "This numbers digits need to be less than the starting base" << endl;
    cout << endl;
    cout << "The number cannot be less than 0" << endl;
    cout << "or greater than (2^10) - 1"       << endl;
    cin  >> numToConvert;

    // If the user does not enter a number within the parameters
    // display an error message to the user and prompt them
    // for a proper entry
    while (numToConvert < 0 /*|| numToConvert > (pow(2,10) - 1)*/)
    {
        cout << "The number cannot be less than 0" << endl;
        cout << "or greater than (2^10) - 1"       << endl;
        cout << endl;
        cout << "Please input a number to convert" << endl;
        cin  >> numToConvert;
    }

    // Ask the user for a base to convert to
    cout << "Please input a base to convert to"                           << endl;
    cout << "The base you are converting to needs to be between 2 and 10" << endl;
    cin  >> endBase;

    // If the user does not enter a number within the parameters
    // display an error message to the user and prompt them
    // for a proper entry
    while (endBase < 2 || endBase > 10)
    {
        cout << "The base being converted to needs to be between 2 and 10" << endl;
        cout << "Please input a base to convert to"                        << endl;
        cin  >> endBase;
    }

    if ( startBase != 10 && endBase == 10)
    {
        workingNum = numToConvert;

        digitPlace = 0;

        while ((workingNum / 10) != 0 || workingNum % 10 != 0 )
        {
            currentDigit = workingNum % 10;

            workingNum = workingNum / 10;

            buildingNum = buildingNum + (currentDigit * pow(startBase, digitPlace));

            digitPlace++;
        }

        convertedNum = buildingNum;
        cout << "The number has been converted to " << convertedNum << endl;
    }

    if (startBase != 10 && endBase != 10)
    {
        workingNum = numToConvert;

        digitPlace = 0;

        while ((workingNum % 10) != 0)
        {
            currentDigit = workingNum % 10;

            workingNum = workingNum / 10;

            buildingNum = buildingNum + (currentDigit * pow(startBase, digitPlace));

            digitPlace++;
        }

        workingNum = buildingNum;

        digitPlace = 1;

        buildingNum = 0;

        while ((workingNum % endBase) != 0)
        {
            currentDigit = workingNum % endBase;

            workingNum = workingNum / endBase;

            buildingNum = buildingNum + (currentDigit * digitPlace);

            digitPlace = digitPlace * 10;

        }
        convertedNum = buildingNum;
        cout << "The number has been converted to " << convertedNum << endl;
    }

    if (startBase == 10 && endBase != 10)
    {
        workingNum = numToConvert;

        digitPlace = 1;

        while (workingNum / endBase != 0 || workingNum % endBase != 0)
        {
            currentDigit = workingNum % endBase;

            workingNum = workingNum / endBase;

            buildingNum = buildingNum + (currentDigit * digitPlace);

            digitPlace = digitPlace * 10;
        }
        convertedNum = buildingNum;
        cout << "The number has been converted to " << convertedNum << endl;
    }

    return 0;
}
