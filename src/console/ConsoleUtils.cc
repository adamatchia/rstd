#include <console/ConsoleUtils.h>

#include <iostream>
using namespace std;

void println(string target) {
	cout << target << endl;
}

namespace RStd {
namespace Console {

	string read() {

		string s;
		getline(cin, s);
		return s;

	}

	string read(string target) {

		cout << target;
		return read();

	}

} // namespace Console
} // namespace RStd