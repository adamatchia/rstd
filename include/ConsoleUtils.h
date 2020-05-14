/*
This file contains utility functions
for console input / output.

*/

#ifndef RSTD_CONSOLE_UTILS_H_
#define RSTD_CONSOLE_UTILS_H_

#include <string>
using namespace std;

namespace RStd
{

void println(string);


namespace Console
{

string read();

} // namespace Console

} // namespace RStd

#endif