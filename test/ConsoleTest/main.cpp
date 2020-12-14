#include <iostream>
using namespace std;

#include "../../include/RStd.h"
using namespace RStd;

int main(int argc, char** argv) {



	Console::ArgumentParser parser (argc, argv);

	if (parser.hasFlag("compile") && parser.hasFlag("o")) {
		cout << "[ OK ] ";
	} else {
		cout << "[ FAILED ] ";
	}

	cout << "Test: RStd::Console::ArgumentParser::hasFlag(string)" << endl;

	if (parser.core == vector<string>{"g++", "main.cc"}) {
		cout << "[ OK ] ";
	} else {
		cout << "[ FAILED ] ";
	}

	cout << "Test: RStd::Console::ArgumentParser General Test" << endl;

}