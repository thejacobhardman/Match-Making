// Jacob Hardman
// Comp Sci 1
// Professor Jennifer Bailey
// 10/18/19

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputFile;
	int height, maxHeight, minHeight, age, maxAge, minAge;
	string name, eyeColor, preferredEyeColor, userInput;
	char gender, preferredGender, smoker, preferredSmoker;
	bool isRunning = true, genderMatch = false, validGender = false, validHeight = false, validAge = false, validEyeColor = false, validSmoker = false;

	while (isRunning) {

		int records = 0, matches = 0, partialMatches = 0, perfectMatches = 0;

		inputFile.open("Program3.dat");

		if (inputFile)
		{
			while (validGender == false) {
				cout << "Enter the preferred gender of your ideal match (M/F): ";
				cin >> preferredGender;

				if (preferredGender == 'M' || preferredGender == 'F') {
					break;
				}
				else {
					cout << "Please select a valid gender by entering a capital letter." << endl;
				}
			}
			while (validHeight == false) {
				cout << "Enter the minimum height in inches: ";
				cin >> minHeight;

				if (minHeight <= 0) {
					cout << "Please enter a valid height." << endl;
				}
				else {
					break;
				}
			}
			while (validHeight == false) {
				cout << "Enter the maximum height in inches: ";
				cin >> maxHeight;

				if (maxHeight <= 0) {
					cout << "Please enter a valid height." << endl;
				}
				else {
					break;
				}
			}
			while (validAge == false) {
				cout << "Enter the minimum age: ";
				cin >> minAge;

				if (minAge <= 0) {
					cout << "Please enter a valid age." << endl;
				}
				else if (minAge < 18) {
					cout << "Enter a valid LEGAL age. (geez...)" << endl;
				}
				else {
					break;
				}
			}
			while (validAge == false) {
				cout << "Enter the maximum age: ";
				cin >> maxAge;

				if (maxAge <= 0) {
					cout << "Please enter a valid age." << endl;
				}
				else if (maxAge < 18) {
					cout << "Enter a valid LEGAL age. (geez...)" << endl;
				}
				else if (maxAge > 100) {
					cout << "Hey who am I to judge?" << endl;
					break;
				}
				else {
					break;
				}
			}
			while (validEyeColor == false) {
				cout << "Enter your preferred eye color: ";
				cin >> preferredEyeColor;

				if (preferredEyeColor == "Blue" || preferredEyeColor == "Grey" || preferredEyeColor == "Green" || preferredEyeColor == "Brown") {
					break;
				}
				else {
					cout << "Please enter a valid eye color with the first letter capitalized." << endl;
				}
			}
			while (validSmoker == false) {
				cout << "Enter your smoking preference (Y/N): ";
				cin >> preferredSmoker;

				if (preferredSmoker == 'Y' || preferredSmoker == 'N') {
					break;
				}
				else {
					cout << "Please select a valid smoking preference by entering a capital letter." << endl;
				}
			}
			cout << endl;

			while (inputFile >> name >> height >> age >> gender >> eyeColor >> smoker)
			{
				matches = 0;
				genderMatch = false;
				records += 1;

				if (height >= minHeight && height <= maxHeight) {
					matches += 1;
				}
				if (age >= minAge && age <= maxAge)
				{
					matches += 1;
				}
				if (preferredGender == gender) {
					matches += 1;
					genderMatch = true;
				}
				if (preferredEyeColor == eyeColor) {
					matches += 1;
				}
				if (preferredSmoker == smoker) {
					matches += 1;
				}

				if (matches == 5) {
					perfectMatches += 1;
					cout << name << " is a perfect match!" << endl;
				}
				else if (matches < 5 && matches > 0 && genderMatch == true) {
					partialMatches += 1;
					cout << name << " is a partial match!" << endl;
				}
			}

			if (perfectMatches > 0 || partialMatches > 0) {
				cout << "\nThere were " << perfectMatches << " perfect matches and " << partialMatches << " partial matches out of " << records << " records." << endl;
			}
			else {
				cout << "\nNo matches found out of " << records << " records.";
			}

			bool userConfirm = false;
			while (userConfirm == false) {
				cout << "Would you like to run the program again? (Y/N): ";
				cin >> userInput;

				if (userInput == "Y" || userInput == "y") {
					cout << endl;
					userConfirm = true;
				}
				else if (userInput == "N" || userInput == "n") {
					isRunning = false;
					userConfirm = true;
				}
				else {
					cout << "Please enter a valid selection." << endl;
				}
			}

			inputFile.close();
		}
		else
		{
			cout << "Error opening the file.\nPlease make sure that the 'Program3.dat' file is located in the same folder as the 'Match-Making.cpp' file.";
			isRunning = false;
		}
	}
}
