#include <iostream>
#include "../../include/RStd.h"
#include <string>
using namespace std;
using namespace RStd;

int main() {

	string contents = FileUtils::read("sample.csv");

	Table table = CSVParser::parse(contents);

	if (table.stats() == "Rows: 2 ; Columns: 2") {
		cout << "[  OK  ] ";
	} else {
		cout << "[  FAILED  ] ";
	}

	cout << table.stats() << endl;

}