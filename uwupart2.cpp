#include <iostream>
#include <string>

using namespace std;

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

int main() {
	string input;

	cout << "Type the string you would like to test: ";
	getline(cin, input);

	cout << "This string's adorability count is "
		<< adorabilityCounter(input) << endl;

	return 0;
}
