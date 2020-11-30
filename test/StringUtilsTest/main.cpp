#include "../../include/string/StringUtils.h"
#include <iostream>
#include <string>
using namespace std;

using namespace RStd;

int main() {

	StringUtils::doSomething();

	string sentence = "The quick brown fox jumped over the fence.";

	// Starts with test

	if (StringUtils::startsWith(sentence, "The")) {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << "Starts with test" << endl;

}