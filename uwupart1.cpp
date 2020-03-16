#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

const int UWU_END = 3;
const string INPUT_FILE = "input.txt";

// tests strings for "uwu" in that order
bool adorabilityTester(string input) {
	string testCase;
	string uwu = "uwu";
	int index = 0;

	for (int i = 0; i < input.length(); i++) {
		testCase += tolower(input[i]);
		if (testCase[i] == uwu[index]) {
			index++;
			if (index == UWU_END)
				return true;
		}
	}
	return false;
}

// read a file and count contents
int fileReader(ifstream &file, int &lines) {
	string line;
	int adorableStrings = 0;

	while (getline(file, line)) {
		if (adorabilityTester(line)) {
			adorableStrings++;
		}
		lines++;
	}

	return adorableStrings;
}

// get ratio of file adorability and print
void getAdorability(int linesInt, int adorbsInt) {
	double lines = linesInt * 1.0;
	double adorbs = adorbsInt * 1.0;
	double ratio;

	ratio = adorbs / lines;

	cout << "There are " << linesInt << " lines in the file " << INPUT_FILE <<
		endl << adorbsInt << " of these lines are adorable." <<endl <<
		"The adorability value of " << INPUT_FILE << " is " << ratio << endl;
}

int main() {
	ifstream sourceFile(INPUT_FILE);
	int adorbs = 0, lines = 0;

	if (sourceFile)
		adorbs = fileReader(sourceFile, lines);
	else
		cout << "something went wrong with the file\n";

	getAdorability(lines, adorbs);

	return 0;
}
