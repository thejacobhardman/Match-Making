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
	int maxHeight, minHeight, age, maxAge, minAge;
	string name, eyeColor;
	char gender, smoker;

	// Open the file.
	inputFile.open("database.txt");

	// If the file successfully opened, process it.
	if (inputFile)
	{
		/*cout << "Enter the gender of your ideal match: ";
		cin >> gender;
		cout << "Enter the maximum age of your preferred match: ";
		cin >> maxAge;
		cout << "Enter the minimum age of your preffered match: ";
		cin >> minAge;
		cout << "Enter the minimum height in inches: ";
		cin >> minHeight;
		cout << "Enter the maximum height in inches: ";
		cin >> maxHeight;
		cout << "Enter your preferred eye color: ";
		cin >> eyeColor;
		cout << "Enter your smoking preference (Y/N): ";
		cin >> smoker;*/

		cout << "Enter the maximum age: ";
		cin >> maxAge;
		cout << "Enter the minimum age: ";
		cin >> minAge;

		while (inputFile >> name >> age)
		{
			//cout <<  name << " " << age << " "<< smoker << endl;
			if (age >= minAge && age <= maxAge)
			{
				cout << name << " is within the age range you specified he/she is "
					<< age << endl;
			}
		}

		// Close the file.
		inputFile.close();
	}
	else
	{
		// Display an error message.
		cout << "Error opening the file.\n";
	}
	return 0;
}
