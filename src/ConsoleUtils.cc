#include <ConsoleUtils.h>

#include <string>
#include <iostream>
using std::string;
using std::iostream;
using std::getline;
using std::cin;

namespace RStd
{


void println(string message)
{
	cout << message << endl;
}

string read()
{

	string s;
	getline(cin, s);
	return s;

}


} // namespace RStd