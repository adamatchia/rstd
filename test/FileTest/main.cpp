#include <iostream>
#include <string>
using namespace std;



#include <RStd.h>
using namespace RStd;

int main() {

	vector<string> lsResult = FileUtils::ls("./");

	if (lsResult.size() == 4) {
		cout << "[ OK ] ";
	} else {
		cout << "[ FAILED ] ";
	}

	cout << "Test: RStd::FileUtils::ls(string)" << endl;

	string a = FileUtils::read("example.txt");

	if (a == "This is a test.") {
		cout << "[ OK ] ";
	} else {
		cout << "[ FAILED ] ";
	}

	cout << "Test: RStd::FileUtils::read(string)" << endl;

}