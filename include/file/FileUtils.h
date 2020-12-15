#ifndef _RSTD_FILE_UTILS_H_
#define _RSTD_FILE_UTILS_H_

#define RSTD_FILE_ERROR "$error$$"

#include <string>
#include <vector>
using namespace std;

namespace RStd {
namespace FileUtils {

	string read(string);
	void write(string, string);

	vector<string> ls(string);

}
}

#endif