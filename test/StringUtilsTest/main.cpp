#include "../../include/string/StringUtils.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using namespace RStd;

int main() {
	
	string sentence = "The quick brown fox jumped over the fence.";

	// Starts with test

	// ==============================================

	if (StringUtils::startsWith(sentence, "The")) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::startsWith(string, string)" << endl;

	// ==============================================

	string reverseTest = "HELLO";

	if (StringUtils::invert(reverseTest) == "OLLEH") {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::invert(string)" << endl;

	// ==============================================

	if (StringUtils::endsWith(sentence, "fence")) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::endWith(string, string)" << endl;

	// ==============================================

	if (StringUtils::replace(sentence, "fox", "cat", -1) == "The quick brown cat jumped over the fence.") {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::replace(string, string, string, int)" << endl;

	// ==============================================

	if (StringUtils::contains(sentence, "fox")) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::contains(string, string)" << endl;

	// ==============================================

	if (StringUtils::countContains(sentence, "he") == 2) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::countContains(string, string)" << endl;

	// ==============================================

	bool splitStatus = true;

	string splitString = "1,2,3";

	vector<string> splitResult = {"1", "2", "3"};

	vector<string> compare = StringUtils::split(splitString, ",");

	if (compare != splitResult) {
		splitStatus = false;
	}

	splitString = "1<a>2<a>3<a>";

	compare = StringUtils::split(splitString, "<a>");

	if (compare != splitResult) {
		splitStatus = false;
	}

	splitString = "1,\"2,3\",4";
	compare = StringUtils::splitStringMode(splitString, ",", true);

	if (compare.size() != 3) {
		splitStatus = false;
	}

	if (splitStatus) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::split(string, string)" << endl;

	if (splitStatus) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::split(string, char)" << endl;

	if (splitStatus) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::splitStringMode(string, string)" << endl;

	if (splitStatus) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::splitStringMode(string, char)" << endl;


	// ==============================================

	if (StringUtils::toLower("ABC32423423{}") == "abc32423423{}") {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::toLower(string)" << endl;

	// ==============================================

	if (StringUtils::toUpper("abc32423423{}") == "ABC32423423{}") {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::toUpper(string)" << endl;

	// ==============================================

	if (StringUtils::trim("\n  \t\nHELLO\nWORLD\n\n\t   \n") == "HELLO\nWORLD") {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::trim(string)" << endl;

	// ==============================================

	if (StringUtils::toTitle("john doe") == "John Doe") {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::toTitle(string)" << endl;

	// ==============================================


	if (StringUtils::toCurrency("500000") == "500,000.00") {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::toCurrency(string)" << endl;

	// ==============================================


	string random = StringUtils::randomString(50);

	if (random.length() == 50) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Test: RStd::StringUtils::random_string(int)" << endl;

}
