#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

const string INPUT_FILE = "input.txt";

// take a string and make all alpha characters lowercase
string lowerString(string input) {
	string output;

	for (int i = 0; i < input.length(); i++) {
		output += tolower(input[i]);
	}

	return output;
}

// count the number of adorable instances in a string, cribbage rules
int adorabilityCounter(string rawSample) {
	int ind1 = 0, ind2 = 0, ind3 = 0;
	int adorbsFound = 0;
	const int end = rawSample.length();
	string sample = lowerString(rawSample);

	while (ind1 < end) {
		if (sample[ind1] == 'u') {
			ind2 = ind1 + 1;
			while (ind2 < end) {
				if (sample[ind2] == 'w') {
					ind3 = ind2 + 1;
					while (ind3 < end) {
						if (sample[ind3] == 'u') {
							adorbsFound++;
							ind3++;
						}
						ind3++;
					}
				}
				ind2++;
			}
		}
		ind1++;
	}

	return adorbsFound;
}

// read a file and count contents
string fileReader(ifstream &file, int &lines, int &adorbs) {
	string line;
	string mostAdorb;
	int mostAdorbValue = 0;

	while (getline(file, line)) {
		int temp = adorabilityCounter(line);
		adorbs += temp;
		lines++;
		if (temp > mostAdorbValue) {
			mostAdorbValue = temp;
			mostAdorb = line;
		}
	}

	return mostAdorb;
}

// get ratio of file adorability and print
void getAdorability(int linesInt, int adorbsInt, string mostAdorb) {
	double lines = linesInt * 1.0;
	double adorbs = adorbsInt * 1.0;
	double ratio;

	ratio = adorbs / lines;

	cout << "There are " << linesInt << " lines in the file " << INPUT_FILE <<
		endl << adorbsInt << " of these lines are adorable." << endl <<
		"The adorability portion of " << INPUT_FILE << " is " << ratio << endl
		<< "The most adorable line is " << mostAdorb << endl;
}

int main() {
	ifstream sourceFile(INPUT_FILE);
	int adorbs = 0, lines = 0;
	string mostAdorb;

	if (sourceFile)
		mostAdorb = fileReader(sourceFile, lines, adorbs);
	else
		cout << "something went wrong with the file\n";

	getAdorability(lines, adorbs, mostAdorb);

	return 0;
}
