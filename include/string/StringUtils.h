#ifndef _RSTD_STRING_UTILS_H_
#define _RSTD_STRING_UTILS_H_

#include <string>
using namespace std;

namespace RStd {
namespace StringUtils {

	bool startsWith(string, string);
	bool endsWith(string, string);
	string replace(string, string, string, int);
	bool contains(string, string);


} // namespace StringUtils
} // namespace rstd

#endif