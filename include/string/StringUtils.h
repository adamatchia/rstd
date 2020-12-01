#ifndef _RSTD_STRING_UTILS_H_
#define _RSTD_STRING_UTILS_H_

#include <string>
#include <vector>
using namespace std;

namespace RStd {
namespace StringUtils {

	bool startsWith(string, string);
	string invert(string);
	bool endsWith(string, string);
	string replace(string, string, string, int);
	bool contains(string, string);
	int countContains(string, string);
	vector<string> splitStringMode(string, string, bool);
	vector<string> splitStringMode(string, char, bool);
	vector<string> split(string, string);
	vector<string> split(string, char);
	string toLower(string);
	string toUpper(string);
	string trim(string);
	string toTitle(string);
	string toCurrency(string);
	int Atoi(string);
	string Itoa(int);

} // namespace StringUtils
} // namespace rstd

#endif