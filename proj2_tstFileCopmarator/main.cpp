#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compare(ifstream& file1, ifstream& file2) {
	string line1, line2;
	int lineCounter = 1;
	bool same = true;

	file1 >> line1;
	file2 >> line2;
	if (line1.compare(line2) != 0) {
		same = false;
		cout << "line: " << lineCounter << ", file1: " << line1 << ", file2: " << line2 << endl;
	}
	lineCounter++;

	while (!file1.eof() && !file2.eof()) {
		//if (!file1.good()) {
		//	throw exception("file 1 ended at line: " + lineCounter);
		//}
		//if (!file2.good()) {
		//	throw exception("file 2 ended at line: " + lineCounter);
		//}

		file1 >> line1;
		file2 >> line2;
		if (line1.compare(line2) != 0) {
			same = false;
			cout << "line: " << lineCounter << ", file1: " << line1 << ", file2: " << line2 << endl;
		}
		lineCounter++;
	}
	if (!file1.eof())
		throw exception("file 2 ended at line: " + lineCounter);
	if (!file2.eof())
		throw exception("file 1 ended at line: " + lineCounter);

	if (same)
	{
		cout << "result: SUCCESS. files are identical" << endl;
	}
	else {
		cout << "result: FAIL." << endl;
	}
}

int main()
{
	string input;

	try {
		cout << "please enter 1st file path: " << endl;
		cin >> input;

		ifstream file1(input);
		if (!file1) {
			throw invalid_argument("file not found!");
		}
		cout << "please enter 2nd file path: " << endl;
		cin >> input;

		ifstream file2(input);
		if (!file2) {
			throw invalid_argument("file not found!");
		}

		compare(file1, file2);

	}
	catch (exception e) {
		cout << e.what();
	}
	system("pause");
}