#ifndef _RSTD_FILE_UTILS_H_
#define _RSTD_FILE_UTILS_H_

#define RSTD_FILE_ERROR -1

#include <string>
#include <vector>
using namespace std;

namespace RStd {
namespace FileUtils {

	string read(string);
	void write(string, string, bool);
	void write(string, string);

	vector<string> ls(string);

	bool file_exists(string);
	bool dir_exists(string);

}
}

#endif