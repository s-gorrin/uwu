#include <iostream>
#include <string>

using namespace std;

const int UWU_END = 3;

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

int main() {
	string input;

	cout << "Type the string you would like to test: ";
	cin >> input;

	if (adorabilityTester(input)) {
		cout << "This string is adorable.\n";
	}
	else {
		cout << "This string is not adorable.\n";
	}
	
	return 0;
}
