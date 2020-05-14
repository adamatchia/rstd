#ifndef RSTD_FILE_UTILS_H_
#define RSTD_FILE_UTILS_H_

#include <string>
using std::string;

#define RSTD_FILE_ERROR 1

namespace RStd
{

namespace FileUtils
{

string read(string);

void write(string, string);

} // namespace FileUtils

} // namespace RStd

#endif