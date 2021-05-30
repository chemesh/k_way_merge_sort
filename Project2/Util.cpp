#include "Util.h"

int getPosIntFromInput(int lowBound) {

	string input;
	cin >> input;
	int res = stoi(input);
	if (res <= lowBound) {
		throw invalid_argument("wrong input");
	}
	return res;
}

long int preStol(string str)
{
	const char* c_str = str.c_str();
	int i = 0;

	while (*(c_str + i) != '\n' && *(c_str + i) != '\0') {
		if (i == 0 && *(c_str + i) == '-') {
			i++;
			continue;
		}
		else if (*(c_str + i) < '0' || *(c_str + i) > '9') {
			throw invalid_argument("wrong input");
		}
		i++;
	}
	return stol(str);


}

long int* getArrFromFile(const string& filename, const int& n)
{
	int count = 0;
	string temp;
	long int* arr = new long int[n];

	ifstream infile(filename);
	if (!infile.is_open()) {
		throw invalid_argument("wrong infile name");
	}

	infile >> temp;
	arr[count++] = preStol(temp);
	while (!infile.eof()) {
		if (!infile.good()) {
			throw invalid_argument("bad parameter from infile");
		}
		infile >> temp;
		arr[count++] = preStol(temp);
	}

	if (count != n) {
		throw invalid_argument("not enough charachters");
	}
	infile.close();
	cout << endl;
	return arr;
}

void printArrToFile(const string& filename, long int arr[], const int& n) {

	ofstream outfile(filename);
	if (!outfile) {
		throw invalid_argument("wrong outfile name");
	}

	for (int i = 0; i < n - 1; i++) {
		outfile << arr[i] << endl;
	}
	outfile << arr[n - 1];
	outfile.close();
}
