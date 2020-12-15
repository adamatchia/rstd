#ifndef _RSTD_CONSOLE_UTILS_H_
#define _RSTD_CONSOLE_UTILS_H_

#include <string>
using namespace std;

void println(string);

namespace RStd {
namespace Console {

	string read(string);
	string read();

} // namespace Console
} // namespace RStd

#endif