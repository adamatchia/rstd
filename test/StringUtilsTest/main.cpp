#include "../../include/string/StringUtils.h"
#include <iostream>
#include <string>
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


}